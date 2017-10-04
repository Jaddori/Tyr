#pragma once

#include "lua.hpp"
#include "d2_interface.h"

namespace lua_interface
{
	void bind( lua_State* lua );

	int getScreenSize( lua_State* lua );
	int getMousePosition( lua_State* lua );
	int getMouseOffset( lua_State* lua );
}