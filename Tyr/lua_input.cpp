#include "lua_input.h"

namespace lua_input
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "sendMouseClick", sendMouseClick );
	}

	int sendMouseClick( lua_State* lua )
	{
		int result = 0;

		int x = 0, y = 0, clickType = 0;

		int args = lua_gettop( lua );
		if( args == 1 )
		{
			lua_rawgeti( lua, 1, 1 );
			x = lua_tonumber( lua, -1 );

			lua_rawgeti( lua, 1, 2 );
			y = lua_tonumber( lua, -1 );

			lua_rawgeti( lua, 1, 3 );
			clickType = lua_tonumber( lua, -1 );
		}
		else if( args == 3 )
		{
			x = lua_tonumber( lua, 1 );
			y = lua_tonumber( lua, 2 );
			clickType = lua_tonumber( lua, 3 );
		}

		::sendMouseClick( x, y, clickType );

		return result;
	}
}