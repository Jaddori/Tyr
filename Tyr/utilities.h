#pragma once

#include <cmath>

inline float getDistance( int x1, int y1, int x2, int y2 )
{
	x2 -= x1;
	y2 -= y1;

	return (float)sqrtf( x2*x2 + y2*y2 );
}