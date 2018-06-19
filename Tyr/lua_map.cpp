#include "lua_map.h"

namespace lua_map
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "getCurrentLevel", getCurrentLevel );
	}

	int getCurrentLevel( lua_State* lua )
	{
		int result = 0;

		d2UnitAny_t* player = *d2PlayerUnit;
		if( player )
		{
			d2Level_t* currentLevel = player->act->misc->levelFirst;
		}

		return result;
	}
}