#include "lua_monster.h"

namespace lua_monster
{
	static std::vector<d2UnitAny_t*> monsters;

	void bind( lua_State* lua )
	{
		lua_register( lua, "getClosestMonster", getClosestMonster );

		monsters.reserve(100);
	}

	int getClosestMonster( lua_State* lua )
	{
		monsters.clear();

		int result = 0;

		d2UnitAny_t* playerUnit = *d2PlayerUnit;
		if( playerUnit )
		{
			for( d2Room1_t* room = playerUnit->act->room1; room; room = room->next )
			{
				for( d2UnitAny_t* unit = room->unitFirst; unit; unit = unit->roomNext )
				{
					if( unit != playerUnit && isMonster( unit ) )
						monsters.push_back( unit );
				}
			}

			float minDist = 9999.0f;
			d2UnitAny_t* closestMonster = NULL;

			int playerX = playerUnit->path->x;
			int playerY = playerUnit->path->y;
			for( std::vector<d2UnitAny_t*>::iterator it = monsters.begin(); it != monsters.end(); it++ )
			{
				int x = (*it)->path->x;
				int y = (*it)->path->y;

				float dist = getDistance( x, y, playerX, playerY );
				if( dist < minDist )
				{
					minDist = dist;
					closestMonster = *it;
				}
			}

			if( closestMonster )
			{
				lua_pushlightuserdata( lua, closestMonster );
				result = 1;
			}
		}

		return result;
	}

	int getIsMonster( lua_State* lua )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 && lua_isuserdata( lua, 1 ) )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );

			lua_pushboolean( lua, isMonster( unit ) );
			result = 1;
		}

		return result;
	}

	int isMonster( d2UnitAny_t* unit )
	{
		return unit->textFileNumber == 5 || unit->textFileNumber == 63 || unit->textFileNumber == 19;
	}
}