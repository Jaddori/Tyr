#pragma once

#include "d2_path_reducer.h"
#include "d2_act_map.h"

namespace Mapping
{
	namespace Pathing
	{
		namespace Reducing
		{

			class NoPathReducer : public PathReducer
			{
			private:
				ActMap* map;
			public:
				NoPathReducer(const NoPathReducer&);
				NoPathReducer& operator=(const NoPathReducer&);
				NoPathReducer(ActMap* map_) : map(map_) {}
				// the path is not reduced at all
				inline void reduce(PointList const & in, PointList& out, bool abs) { out = in; }
				// accept only walkable nodes
				inline bool reject(Point const & pt, bool abs) {
					return map->spaceHasFlag(ActMap::Avoid, pt, abs) ||
						map->spaceHasFlag(ActMap::BlockWalk, pt, abs) ||
						map->spaceHasFlag(ActMap::BlockPlayer, pt, abs);
				}

				void getOpenNodes(Point const & center, PointList& out, Point const & endpoint)
				{
					for(int i = 1; i >= -1; i--)
					{
						for(int j = 1; j >= -1; j--)
						{
							if( i == 0 && j == 0)
								continue;
							out.push_back(Point(center.first+i, center.second+j));
						}
					}		
				}

				int getPenalty(Point const & pt, bool abs)
				{
					return 0;
				}

				inline void mutatePoint(Point & pt, bool abs)
				{
					// find the nearest walkable space
					if(reject(pt, abs))
					{
						for(int i = 0; i < 3; i++)
						{
							for(int j = 0; j < 3; j++)
							{
								if(i == 0 && j == 0)
									continue;

								Point ptN(pt.first+i, pt.second+j);
								if(!reject(ptN, abs))
								{
									pt.first = ptN.first;
									pt.second = ptN.second;
								}
							}
						}
					}
				}

			};
		}
	}
}