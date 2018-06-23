#pragma once

#include "d2_path_reducer.h"
#include "d2_path.h"
#include "d2_act_map.h"

namespace Mapping
{
	namespace Pathing
	{
		namespace Reducing
		{

#pragma warning ( disable: 4512 )

			class WalkPathReducer : public PathReducer
			{
			private:
				ActMap* map;
				Distance distance;
				int range;

				inline void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }

			public:
				WalkPathReducer(const WalkPathReducer&);
				WalkPathReducer& operator=(const WalkPathReducer&);
				WalkPathReducer(ActMap* m, Distance d, int _range = 20) 
					: map(m), distance(d), range(_range*10) {}

				void reduce(PointList const & in, PointList& out, bool abs)
				{
					PointList::const_iterator it = in.begin(), end = in.end();
					out.push_back(*it);
					Point lineStartStep;
					Point lineStartPoint;
					Point currentStep;
					Point previousPoint;
					Point secondStep;
					int differentStepCount = 0;
					int lineLength = 0;
					bool first = true;
					while(it != end)
					{
						if (first)
						{
							lineStartPoint = *it;
							it++;
							lineLength++;
							first = false;
							if (it != end)
							{
								lineStartStep = Point(lineStartPoint.first - (*it).first, lineStartPoint.second - (*it).second);
								secondStep = lineStartStep;
							}
							continue;
						}
						previousPoint = *it;
						it++;
						lineLength++;
						if (it == end)
						{
							out.push_back(previousPoint);
							break;
						}
						currentStep = Point(previousPoint.first - (*it).first, previousPoint.second - (*it).second);
						if (currentStep != lineStartStep)
						{
							if (lineStartStep == secondStep)
							{
								secondStep = currentStep;
							}
							differentStepCount++;
						}
						else if (differentStepCount == 1)
						{
							differentStepCount = 0;
						}
						if (lineLength > 5 && ((currentStep != lineStartStep && currentStep != secondStep) || differentStepCount > 1 || lineLength > 20))
						{
							out.push_back(previousPoint);
							lineStartStep = Point(currentStep);
							secondStep = lineStartStep;
							lineLength = 1;
							differentStepCount = 0;
						}
					}
				}

				bool reject(Point const & pt, bool abs)
				{
					return map->spaceHasFlag(ActMap::Avoid, pt, abs)     ||
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
					return map->spaceHasFlag(ActMap::Object, pt, abs) ? 60 : (map->spaceHasFlag(ActMap::ClosedDoor, pt, abs) ? 80 : 0);
				}

				void mutatePoint(Point & pt, bool abs)
				{
					bool mutated = false;
					// find the nearest walkable space
					if(reject(pt, abs))
					{
						for(int i = -2; !mutated && i <= 2; i++)
						{
							for(int j = -2; !mutated && j <= 2; j++)
							{
								if(i == 0 && j == 0)
									continue;
								Point ptN(pt.first+i, pt.second+j);
								if(!reject(ptN, abs))
								{
									pt.first = ptN.first;
									pt.second = ptN.second;
									mutated = true;
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
