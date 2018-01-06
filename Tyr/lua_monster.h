#pragma once

#include "lua.hpp"
#include "d2_structures.h"
#include "d2_interface.h"
#include <vector>
#include "utilities.h"

namespace lua_monster
{
	void bind( lua_State* lua );

	int getClosestMonster( lua_State* lua );
	int getIsMonster( lua_State* lua );

	int isMonster( d2UnitAny_t* unit );
}