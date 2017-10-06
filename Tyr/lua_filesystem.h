#pragma once

#include <Windows.h>
#include "lua.hpp"

namespace lua_filesystem
{
	void bind( lua_State* lua );

	int getFiles( lua_State* lua );
	int messageBox( lua_State* lua );
}