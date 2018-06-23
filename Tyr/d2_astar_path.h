#pragma once

#include "d2_path.h"
#include "d2_map.h"
#include "d2_path_reducer.h"
#include "d2_structures.h"
#include <vector>
#include <set>
#include <queue>
#include <cmath>

namespace Mapping
{
	namespace Pathing
	{

		inline int __fastcall manhattan(Point const & start, Point const & end)
		{
			return 10*(std::abs(start.first-end.first) + std::abs(start.second-end.second));	
		}

		inline int __fastcall diagonalShortcut(Point const & start, Point const & end)
		{
			int xdist = std::abs(start.first-end.first);
			int ydist = std::abs(start.second-end.second);
			return ((xdist > ydist) ? 14*ydist + 10*(xdist-ydist) : 14*xdist + 10*(ydist-xdist));
		}

		inline int __fastcall chebyshev(Point const & start, Point const & end)
		{
			int xdist = (start.first-end.first);
			int ydist = (start.second-end.second);
			return (xdist > ydist ? xdist : ydist);
		}

		inline int __fastcall euclidean(Point const & start, Point const & end)
		{
			double dx = (double)(end.first - start.first);
			double dy = (double)(end.second - start.second);
			dx = pow(dx, 2);
			dy = pow(dy, 2);
			return (int)(sqrt(dx + dy)*10);
		}

		inline int __fastcall estimateDistance(const Map* m, const Point& point, const Point& end) { return diagonalShortcut(point, end); }

#pragma warning ( disable: 4512 )

		class Node
		{
		public:
			Node* const parent;
			Point point;
			int g, h;

			Node() : parent(0) {}
			Node(Point s, Node* p, int _g, int _h) : point(s), parent(p), g(_g), h(_h) {}
		};
		struct NodeComparer {
			inline bool __fastcall operator() (const Node* left, const Node* right) const { return (left->g + left->h) > (right->g + right->h); }
		};

		template <class Allocator = std::allocator<Node> >
		class AStarPath : public Path
		{
		private:
			Allocator alloc;

			Map* map;
			Reducing::PathReducer* reducer;
			Estimator estimate;
			Distance distance;

			inline void reverseList(Node* node, PointList& list)
			{
				list.clear();
				Node* current = node;
				do
				{
					list.insert(list.begin(), current->point);
				} while((current = current->parent) != NULL);
			}

			void findPath(Point const & start, Point const & end, Node** result, std::vector<Node*>& nodes, bool abs)
			{
				std::priority_queue<Node*, std::vector<Node*>, NodeComparer> open;
				std::set<Point> closed;
				PointList newNodes;
				Node* begin = alloc.allocate(1);
				d2UnitAny_t* player = d2GetPlayerUnit();
				DWORD startLvl = player->path->room1->room2->level->levelNumber;

				// if we don't get a valid node, just return
				if(!begin) return;

				alloc.construct(begin, Node(start, NULL, 0, estimate(map, start, end)));
				nodes.push_back(begin);
				open.push(begin);
				DWORD ticks = GetTickCount();
				while(!open.empty())
				{
					Node* current = open.top();
					open.pop();

					if(closed.find(current->point) != closed.end()) continue;

					if(current->point == end)
					{
						*result = current;
						return;
					}

					if (!gameReady() || startLvl != d2GetPlayerUnit()->path->room1->room2->level->levelNumber)
					{
						return;
					}

					bool result = closed.insert(current->point).second;
					assert(result == true);
					(void)(result); // shut up compiler about unused variable warning

									// getOpenNodes should be in map along with a filter
					reducer->getOpenNodes(current->point, newNodes ,end);
					while (!newNodes.empty())
					{
						Point point = newNodes.back();
						newNodes.pop_back();

						if (reducer->reject(point, abs) && point != end)
						{
							closed.insert(point);				
							continue;
						}
						Node* next = alloc.allocate(1);
						// if we don't get a valid node, just return
						if(!next) return;
						int pointPenalty = reducer->getPenalty(point, abs);
						alloc.construct(next, Node(point, current, current->g + distance(current->point, point) + pointPenalty,
							estimate(map, point, end)));
						nodes.push_back(next);
						open.push(next);
					}
				}
			}

		public:
			AStarPath(const AStarPath&);
			AStarPath& operator=(const AStarPath&);
			AStarPath(Map* _map, Reducing::PathReducer* _reducer, Estimator _estimate = estimateDistance, Distance _distance = diagonalShortcut)
				: map(_map), reducer(_reducer), estimate(_estimate), distance(_distance), alloc(Allocator()) {}

			inline Allocator const & getAllocator() { return alloc; }
			inline void setMap(Map* map) { this->map = map; }
			inline void setPathReducer(Reducing::PathReducer* reducer) { this->reducer = reducer; }

			void getPath(Point const & _start, Point const & _end, PointList& list, bool abs = true)
			{
				Node* result = NULL;
				Point start = _start, end = _end;

				// if we don't have a valid start and end, try mutating the points
				if(reducer->reject(start, abs))
					reducer->mutatePoint(start, abs);
				if(reducer->reject(end, abs))
					reducer->mutatePoint(end, abs);

				// if they still get rejected, forget it
				//if(!map->IsValidPoint(start, abs) || !map->IsValidPoint(end, abs)) return;

				std::vector<Node*> nodes;
				findPath(start, end, &result, nodes, abs);
				if(result)
				{
					PointList in;
					reverseList(result, in);
					reducer->reduce(in, list, abs);
				}
				else
					list = PointList();

				std::vector<Node*>::iterator lbegin = nodes.begin(), lend = nodes.end();
				for(std::vector<Node*>::iterator it = lbegin; it != lend; it++)
				{
					alloc.destroy((*it));
					alloc.deallocate((*it), sizeof(*it));
				}
			}
		};

#pragma warning ( default: 4512 )

	}
}
