#pragma once

#include "lua.hpp"
#include "d2_interface.h"

namespace lua_rendering
{
	void bind( lua_State* lua );

	int drawLine( lua_State* lua );
	int drawRectangle( lua_State* lua );
	int drawText( lua_State* lua );
}