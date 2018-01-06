#pragma once

#include "lua.hpp"
#include "d2_structures.h"
#include "d2_interface.h"

namespace lua_player
{
	void bind( lua_State* lua );

	int getPlayer( lua_State* lua );
	int getPlayerName( lua_State* lua );
}