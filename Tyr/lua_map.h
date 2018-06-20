#pragma once

#include "lua.hpp"
#include "d2_interface.h"
#include "d2_structures.h"
#include "d2_constants.h"
#include "d2_act_map.h"

namespace lua_map
{
	void bind( lua_State* lua );

	int getCurrentLevel( lua_State* lua );
	int getLevelNumber( lua_State* lua );
	int getExits( lua_State* lua );
	int dumpActMap( lua_State* lua );
}