#pragma once

#include "lua.hpp"
#include "d2_helpers.h"

namespace lua_input
{
	void bind( lua_State* lua );

	int sendMouseClick( lua_State* lua );
	int clickMap( lua_State* lua );
}