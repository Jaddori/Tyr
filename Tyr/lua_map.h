#pragma once

#include "lua.hpp"
#include "d2_interface.h"
#include "d2_structures.h"
#include "d2_constants.h"

namespace lua_map
{
	void bind( lua_State* lua );

	int getCurrentLevel( lua_State* lua );
}