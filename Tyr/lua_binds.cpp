#include "lua_binds.h"

int lua_bind( LuaBinds* binds )
{
	binds->initialized = 0;
	binds->lua = luaL_newstate();
	luaL_openlibs( binds->lua );

	// bind subsystem here:
	lua_rendering::bind( binds->lua );

	// run main script
	if( luaL_loadfile( binds->lua, "./scripts/main.lua" ) == 0 )
	{
		if( lua_pcall( binds->lua, 0, 0, 0 ) == 0 )
		{
			lua_getglobal( binds->lua, "mainRender" );
			if( lua_isfunction( binds->lua, -1 ) )
			{
				binds->renderFunctionReference = luaL_ref( binds->lua, LUA_REGISTRYINDEX );
				binds->initialized = 1;
			}
		}
	}

	return binds->initialized;
}

void lua_render( LuaBinds* binds )
{
	if( !binds->initialized )
		return;

	lua_rawgeti( binds->lua, LUA_REGISTRYINDEX, binds->renderFunctionReference );
	if( lua_pcall( binds->lua, 0, 0, 0 ) )
	{
		const char* errorMessage = lua_tostring( binds->lua, -1 );
		MessageBoxA( NULL, errorMessage, "Tyr - Lua error", MB_OK );

		binds->initialized = 0;
	}

	/*if( d2DrawLine )
		d2DrawLine( 320-5, 240, 320+5, 240, 0xFF, 0 );*/
}