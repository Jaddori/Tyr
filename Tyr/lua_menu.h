#pragma once

#include "lua.hpp"
#include "d2_constants.h"
#include "d2_helpers.h"

namespace lua_menu
{
	void bind( lua_State* lua );

	int selectCharacter( lua_State* lua );
	int findControl( lua_State* lua );
	int findButton( lua_State* lua );
	int clickControl( lua_State* lua );

	int printAllControls( lua_State* lua );
}