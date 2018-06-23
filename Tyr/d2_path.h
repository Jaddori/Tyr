#pragma once

#include "d2_map.h"
#include "d2_path_reducer.h"

namespace Mapping
{
	namespace Pathing
	{
		typedef int (__fastcall *Estimator)(Map const *, Point const &, Point const &);
		typedef int (__fastcall *Distance)(Point const &, Point const &);

		class Path
		{
		public:
			virtual void getPath(Point const & start, Point const & end, PointList& list, bool abs) = 0;

			virtual void setMap(Map* map) = 0;
			virtual void setPathReducer(Reducing::PathReducer* reducer) = 0;
		};

	}
}
