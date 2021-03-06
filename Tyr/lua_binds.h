#pragma once

#include "lua.hpp"
#include "lua_rendering.h"

struct LuaBinds
{
	lua_State* lua;
	int renderFunctionReference;
	int initialized;
};

int lua_bind( LuaBinds* binds );
void lua_render( LuaBinds* binds );