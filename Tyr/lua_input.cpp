#include "lua_input.h"

namespace lua_input
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "sendMouseClick", sendMouseClick );
		lua_register( lua, "clickMap", clickMap );
	}

	int sendMouseClick( lua_State* lua )
	{
		int result = 0;

		int x = 0, y = 0, clickType = 0;

		int args = lua_gettop( lua );
		if( args == 1 )
		{
			lua_rawgeti( lua, 1, 1 );
			x = (int)lua_tonumber( lua, -1 );

			lua_rawgeti( lua, 1, 2 );
			y = (int)lua_tonumber( lua, -1 );

			lua_rawgeti( lua, 1, 3 );
			clickType = (int)lua_tonumber( lua, -1 );
		}
		else if( args == 3 )
		{
			x = (int)lua_tonumber( lua, 1 );
			y = (int)lua_tonumber( lua, 2 );
			clickType = (int)lua_tonumber( lua, 3 );
		}

		::sendMouseClick( x, y, clickType );

		return result;
	}

	int clickMap( lua_State* lua )
	{
		int result = 0;

		int x = 0, y = 0, clickType = 0;
		bool shift = false;

		int args = lua_gettop( lua );
		if( args == 1 )
		{
			lua_rawgeti( lua, 1, 1 );
			x = (int)lua_tonumber( lua, -1 );

			lua_rawgeti( lua, 1, 2 );
			y = (int)lua_tonumber( lua, -1 );

			lua_rawgeti( lua, 1, 3 );
			clickType = (int)lua_tonumber( lua, -1 );

			lua_rawgeti( lua, 1, 4 );
			shift = lua_toboolean( lua, -1 );
		}
		else if( args == 4 )
		{
			x = (int)lua_tonumber( lua, 1 );
			y = (int)lua_tonumber( lua, 2 );
			clickType = (int)lua_tonumber( lua, 3 );
			shift = lua_toboolean( lua, 4 );
		}

		::clickMap( x, y, clickType, shift, NULL );

		return result;
	}
}