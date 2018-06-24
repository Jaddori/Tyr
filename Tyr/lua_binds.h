#pragma once

#include "lua.hpp"
#include "lua_rendering.h"
#include "lua_interface.h"
#include "lua_filesystem.h"
#include "lua_unit.h"
#include "lua_player.h"
#include "lua_monster.h"
#include "lua_game.h"
#include "lua_menu.h"
#include "lua_input.h"
#include "lua_map.h"
#include "lua_path.h"
#include "backlog.h"

struct LuaBinds
{
	lua_State* lua;
	int startFunctionReference;
	int stopFunctionReference;
	int updateFunctionReference;
	int renderFunctionReference;
	int updateOOGFunctionReference;
	int renderOOGFunctionReference;
	int initialized;
};

int lua_bind( LuaBinds* binds );
void lua_start( LuaBinds* binds );
void lua_stop( LuaBinds* binds );
void lua_update( LuaBinds* binds );
void lua_render( LuaBinds* binds );
void lua_update_oog( LuaBinds* binds );
void lua_render_oog( LuaBinds* binds );

int lua_sleep( lua_State* lua );
int lua_backlog( lua_State* lua );