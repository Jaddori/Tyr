#include "lua_binds.h"
#include "backlog.h"

extern Backlog g_backlog;

int lua_bind( LuaBinds* binds )
{
	binds->initialized = 0;
	binds->lua = luaL_newstate();
	luaL_openlibs( binds->lua );

	lua_register( binds->lua, "sleep", lua_sleep );
	lua_register( binds->lua, "backlog", lua_backlog );

	// bind subsystem here:
	lua_rendering::bind( binds->lua );
	lua_interface::bind( binds->lua );
	lua_filesystem::bind( binds->lua );
	lua_unit::bind( binds->lua );
	lua_player::bind( binds->lua );
	lua_monster::bind( binds->lua );
	lua_game::bind( binds->lua );
	lua_menu::bind( binds->lua );
	lua_input::bind( binds->lua );
	lua_map::bind( binds->lua );
	lua_path::bind( binds->lua );

	// run main script
	if( luaL_loadfile( binds->lua, "./scripts/main.lua" ) == 0 )
	{
		if( lua_pcall( binds->lua, 0, 0, 0 ) == 0 )
		{
			binds->initialized = 1;

			lua_getglobal( binds->lua, "start");
			if( lua_isfunction( binds->lua, -1 ) )
			{
				binds->startFunctionReference = luaL_ref( binds->lua, LUA_REGISTRYINDEX );
			}
			else
			{
				binds->initialized = 0;
			}

			lua_getglobal( binds->lua, "stop" );
			if( lua_isfunction( binds->lua, -1 ) )
			{
				binds->stopFunctionReference = luaL_ref( binds->lua, LUA_REGISTRYINDEX );
			}
			else
				binds->initialized = 0;

			lua_getglobal( binds->lua, "update" );
			if( lua_isfunction( binds->lua, -1 ) )
			{
				binds->updateFunctionReference = luaL_ref( binds->lua, LUA_REGISTRYINDEX );
			}
			else
				binds->initialized = 0;

			lua_getglobal( binds->lua, "render" );
			if( lua_isfunction( binds->lua, -1 ) )
			{
				binds->renderFunctionReference = luaL_ref( binds->lua, LUA_REGISTRYINDEX );
			}
			else
				binds->initialized = 0;

			lua_getglobal( binds->lua, "update_oog" );
			if( lua_isfunction( binds->lua, -1 ) )
			{
				binds->updateOOGFunctionReference = luaL_ref( binds->lua, LUA_REGISTRYINDEX );
			}
			else
				binds->initialized = 0;

			lua_getglobal( binds->lua, "render_oog" );
			if( lua_isfunction( binds->lua, -1 ) )
			{
				binds->renderOOGFunctionReference = luaL_ref( binds->lua, LUA_REGISTRYINDEX );
			}
			else
				binds->initialized = 0;
		}
		else
			MessageBoxA( NULL, lua_tostring( binds->lua, -1 ), "Tyr - Lua error", MB_OK );
	}
	else
		MessageBoxA( NULL, lua_tostring( binds->lua, -1 ), "Tyr - Lua error", MB_OK );

	return binds->initialized;
}

void runLuaFunction( LuaBinds* binds, int index )
{
	if( !binds->initialized )
		return;

	lua_rawgeti( binds->lua, LUA_REGISTRYINDEX, index );
	if( lua_pcall( binds->lua, 0, 0, 0 ) )
	{
		const char* errorMessage = lua_tostring( binds->lua, -1 );
		MessageBoxA( NULL, errorMessage, "Tyr - Lua error", MB_OK );

		binds->initialized = 0;
	}
}

void lua_start( LuaBinds* binds )
{
	runLuaFunction( binds, binds->startFunctionReference );
}

void lua_stop( LuaBinds* binds )
{
	runLuaFunction( binds, binds->stopFunctionReference );
}

void lua_update( LuaBinds* binds )
{
	runLuaFunction( binds, binds->updateFunctionReference );
}

void lua_render( LuaBinds* binds )
{
	runLuaFunction( binds, binds->renderFunctionReference );
}

void lua_update_oog( LuaBinds* binds )
{
	runLuaFunction( binds, binds->updateOOGFunctionReference );
}

void lua_render_oog( LuaBinds* binds )
{
	runLuaFunction( binds, binds->renderOOGFunctionReference );
}

int lua_sleep( lua_State* lua )
{
	int result = 0;

	if( lua_gettop( lua ) >= 1 )
	{
		int ms = (int)lua_tonumber( lua, 1 );
		Sleep( ms );
	}

	return result;
}

int lua_backlog( lua_State* lua )
{
	int result = 0;

	if( lua_gettop( lua ) >= 1 )
	{
		const char* message = lua_tostring( lua, 1 );
		g_backlog.log( message );
	}

	return result;
}