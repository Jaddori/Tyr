#pragma once

#include "lua.hpp"
#include "lua_rendering.h"
#include "lua_interface.h"
#include "lua_filesystem.h"

struct LuaBinds
{
	lua_State* lua;
	int startFunctionReference;
	int stopFunctionReference;
	int updateFunctionReference;
	int renderFunctionReference;
	int initialized;
};

int lua_bind( LuaBinds* binds );
void lua_start( LuaBinds* binds );
void lua_stop( LuaBinds* binds );
void lua_update( LuaBinds* binds );
void lua_render( LuaBinds* binds );