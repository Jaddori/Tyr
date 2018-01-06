#include "lua_player.h"

namespace lua_player
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "getPlayer", getPlayer );
		lua_register( lua, "getPlayerName", getPlayerName );
	}

	int getPlayer( lua_State* lua )
	{
		int result = 0;

		d2UnitAny_t* player = *d2PlayerUnit;
		if( player )
		{
			lua_pushlightuserdata( lua, player );
			result = 1;
		}

		return result;
	}

	int getPlayerName( lua_State* lua )
	{
		int result = 0;

		const char* name = (*d2PlayerUnit)->playerData->name;
		if( name )
		{
			lua_pushstring( lua, name );
			result = 1;
		}

		return result;
	}
}