#pragma once

#include "d2_map.h"

namespace Mapping
{
	namespace Pathing
	{
		namespace Reducing
		{
			class PathReducer
			{
			public:
				PathReducer(){}
				PathReducer(const PathReducer&);
				PathReducer& operator=(const PathReducer&);

				virtual void reduce(PointList const & in, PointList& out, bool abs) = 0;
				virtual void getOpenNodes(Point const & center, PointList& out, Point const & endpoint) = 0;
				virtual bool reject(Point const & pt, bool abs) = 0;
				virtual int getPenalty(Point const & pt, bool abs) = 0;
				virtual void mutatePoint(Point & pt, bool abs) = 0;
			};

		}
	}
}