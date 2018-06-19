#pragma once

#include "lua.hpp"
#include "d2_constants.h"
#include "d2_structures.h"
#include "d2_interface.h"
#include "d2_helpers.h"

namespace lua_game
{
	void bind( lua_State* lua );

	int getState( lua_State* lua );
	int getGameReady( lua_State* lua );
}