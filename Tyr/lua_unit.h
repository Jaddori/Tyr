#pragma once

#include "lua.hpp"
#include "d2_structures.h"
#include "utilities.h"

namespace lua_unit
{
	void bind( lua_State* lua );

	int getUnitPosition( lua_State* lua );
	int getDistanceBetweenUnits( lua_State* lua );
	int getUnitType( lua_State* lua );
}