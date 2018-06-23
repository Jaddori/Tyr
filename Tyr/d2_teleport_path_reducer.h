#pragma once

#include "d2_path_reducer.h"
#include "d2_path.h"
#include "d2_act_map.h"
#include "d2_astar_path.h"

namespace Mapping
{
	namespace Pathing
	{
		namespace Reducing
		{

#pragma warning ( disable: 4512 )

			class TeleportPathReducer : public PathReducer
			{
			private:
				ActMap* map;
				Distance distance;
				int range;
				bool justExpand;
				PointList distanceList;

				Point bestPtSoFar;

			public:
				TeleportPathReducer(const TeleportPathReducer&);
				TeleportPathReducer& operator=(const TeleportPathReducer&);
				TeleportPathReducer(ActMap* m, Distance d, int _range = 20)
					: map(m), distance(d), range(_range*10)
				{
					distanceList.clear();
					justExpand = false;
					bestPtSoFar = Point(0,0);

					int r = range / 10; 
					for(int x = 0 - r; x <= 0 + r; x ++)
					{
						for(int y = 0 - r; y <= 0 + r; y++)
						{					
							if( euclidean(Point(x, y),Point(0,0)) < range && euclidean(Point(x, y),Point(0,0)) > range-5 )
							{
								distanceList.push_back(Point(x,y));
							}
						}		
					}

				}

				void reduce(PointList const & in, PointList& out, bool abs)
				{
					PointList::const_iterator it = in.begin(), end = in.end();
					out.push_back(*it);
					while(it != end)
					{
						Point prev = *(out.end()-1);
						while(it != end && euclidean(*it, prev) < range) it++;
						it--;
						Point pt;
						pt.first= it->first;
						pt.second = it->second;

						//	MutatePoint(pt,abs);
						out.push_back(pt);
						it++;
					}	


				}
				// this should be in actMap with a filter setting
				// put it here because expanding telport nodes is diffrent for teleport
				void getOpenNodes(Point const & center, PointList& out, Point const & endpoint)
				{		
					// more points added slows down the a* intelegently pick a point we can jump to with tele to speed it up
					//map->pathinging point further restricsts the nodes. for tele path we dont care if its the best possible path. cuts time in half
					// if were in tele range take the jump
					if(euclidean(endpoint,center) < range -20)
					{
						out.push_back(endpoint);
						return;
					}
					// find best tele spot, this dosent help in arcane sant
					if(bestPtSoFar.first==0)
						bestPtSoFar = center;

					int val=1000000;			
					Point best(0,0);
					int x, y;
					if(euclidean(bestPtSoFar,center) < 500)
					{
						for(size_t j = 0; j < distanceList.size(); j++)
						{
							x=distanceList[j].first + center.first;
							y=distanceList[j].second + center.second;
							if(!reject(Point(x, y),true))
							{						
								if( val > euclidean(Point(x, y), endpoint))
								{
									val = euclidean(Point(x, y), endpoint);
									best = Point(x, y);
									out.push_back(best);
								}
							}
						}
						if (best.first != 0 && map->pathingPointList.find(best) == map->pathingPointList.end() && euclidean(best, endpoint) < euclidean(center, endpoint))
						{		
							map->pathingPointList.insert(best);
							out.push_back(best);
							if(euclidean(best,endpoint) < euclidean(bestPtSoFar , endpoint) )
								bestPtSoFar = best;
							return;
						}
					}
					justExpand = true;
					//expand point normally if smart tele isnt found
					for(int i = 1; i >= -1; i--)
					{
						for(int j = 1; j >= -1; j--)
						{
							if( i == 0 && j == 0 || reject(Point(center.first+i, center.second+j), true))
								continue;

							out.push_back(Point(center.first+i, center.second+j));
							map->pathingPointList.insert(Point(center.first+i, center.second+j));
						}
					}
				} 

				bool reject(Point const & pt, bool abs)
				{
					return map->spaceHasFlag(ActMap::Avoid, pt, abs) ||
						map->spaceHasFlag(ActMap::BlockWalk, pt, abs) ||
						map->spaceHasFlag(ActMap::BlockPlayer, pt, abs);
				}

				bool isWalkable(Point const & pt, bool abs)
				{
					return map->spaceHasFlag(ActMap::Avoid, pt, abs) ||
						map->spaceHasFlag(ActMap::BlockWalk, pt, abs) ||
						map->spaceHasFlag(ActMap::BlockPlayer, pt, abs);
				}

				int getPenalty(Point const & pt, bool abs)
				{
					return 0;
				}

				void mutatePoint(Point & pt, bool abs)
				{
					// find the nearest walkable space
					if(isWalkable(pt, abs)) {
						for(int i = 0; i < 3; i++) {
							for(int j = 0; j < 3; j++) {
								if(i == 0 && j == 0)
									continue;

								Point pt_pp(pt.first+i, pt.second+j);
								if(!isWalkable(pt_pp, abs)) {
									pt.first = pt_pp.first;
									pt.second = pt_pp.second;
									return;
								}

								Point pt_np(pt.first-i, pt.second+j);
								if(!isWalkable(pt_np, abs)) {
									pt.first = pt_np.first;
									pt.second = pt_np.second;
									return;
								}

								Point pt_pn(pt.first+i, pt.second-j);
								if(!isWalkable(pt_pn, abs)) {
									pt.first = pt_pn.first;
									pt.second = pt_pn.second;
									return;
								}

								Point pt_nn(pt.first-i, pt.second-j);
								if(!isWalkable(pt_nn, abs)) {
									pt.first = pt_nn.first;
									pt.second = pt_nn.second;
									return;
								}
							}
						}
					}
				}
			};

#pragma warning ( default: 4512 )

		}
	}
}
