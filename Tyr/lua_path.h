#pragma once

#include "lua.hpp"
#include "d2_no_path_reducer.h"
#include "d2_teleport_path_reducer.h"
#include "d2_walk_path_reducer.h"
#include "d2_astar_path.h"

namespace lua_path
{
	enum
	{
		REDUCER_NONE = 0,
		REDUCER_WALK,
		REDUCER_TELEPORT,
	};

	void bind( lua_State* lua );

	int getPath( lua_State* lua );
}