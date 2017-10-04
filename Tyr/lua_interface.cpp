#include "lua_interface.h"

namespace lua_interface
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "getScreenSize", getScreenSize );
		lua_register( lua, "getMousePosition", getMousePosition );
		lua_register( lua, "getMouseOffset", getMouseOffset );
	}

	int getScreenSize( lua_State* lua )
	{
		int result = 1;

		if( lua_istable( lua, -1 ) )
			result = 0;
		else
			lua_newtable( lua );

		int ssx = *d2ScreenSizeX;
		int ssy = *d2ScreenSizeY;

		lua_pushnumber( lua, ssx );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, ssy );
		lua_rawseti( lua, -2, 2 );

		return result;
	}

	int getMousePosition( lua_State* lua )
	{
		int result = 1;

		if( lua_istable( lua, -1 ) )
			result = 0;
		else
			lua_newtable( lua );

		int mx = *d2MouseX;
		int my = *d2MouseY;

		lua_pushnumber( lua, mx );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, my );
		lua_rawseti( lua, -2, 2 );

		return result;
	}

	int getMouseOffset( lua_State* lua )
	{
		int result = 1;
			
		if( lua_istable( lua, -1 ) )
			result = 0;
		else
			lua_newtable( lua );

		int ox = *d2MouseOffsetX;
		int oy = *d2MouseOffsetY;
		int oz = *d2MouseOffsetZ;

		lua_pushnumber( lua, ox );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, oy );
		lua_rawseti( lua, -2, 2 );
		lua_pushnumber( lua, oz );
		lua_rawseti( lua, -2, 3 );

		return result;
	}
}