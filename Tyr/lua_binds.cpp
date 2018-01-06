#include "lua_binds.h"

int lua_bind( LuaBinds* binds )
{
	binds->initialized = 0;
	binds->lua = luaL_newstate();
	luaL_openlibs( binds->lua );

	// bind subsystem here:
	lua_rendering::bind( binds->lua );
	lua_interface::bind( binds->lua );
	lua_filesystem::bind( binds->lua );
	lua_unit::bind( binds->lua );
	lua_player::bind( binds->lua );
	lua_monster::bind( binds->lua );

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