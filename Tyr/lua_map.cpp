#include "lua_map.h"
using namespace Mapping;

namespace lua_map
{
	//static std::vector<ActMap> g_cachedMaps;
	static std::unordered_map<int, ActMap*> g_cachedMaps;

	void bind( lua_State* lua )
	{
		lua_register( lua, "getCurrentLevel", getCurrentLevel );
		lua_register( lua, "getLevelNumber", getLevelNumber );
		lua_register( lua, "getExits", getExits );
		lua_register( lua, "dumpActMap", dumpActMap );
		lua_register( lua, "precacheMap", precacheMap );
	}

	int getCurrentLevel( lua_State* lua )
	{
		int result = 0;

		d2UnitAny_t* player = *d2PlayerUnit;
		if( player )
		{
			//d2Level_t* currentLevel = player->act->misc->levelFirst;
			int levelNumber = player->path->room1->room2->level->levelNumber;
			d2Level_t* currentLevel = getLevel( levelNumber );

			if( currentLevel )
			{
				lua_pushlightuserdata( lua, currentLevel );
				result = 1;
			}
		}

		return result;
	}

	int getLevelNumber( lua_State* lua )
	{
		int result = 0;

		if( lua_gettop( lua ) >= 1 && lua_isuserdata( lua, 1 ) )
		{
			d2Level_t* level = (d2Level_t*)lua_touserdata( lua, 1 );
			if( level )
			{
				lua_pushnumber( lua, level->levelNumber );
				result = 1;
			}
		}

		return result;
	}

	int getExits( lua_State* lua )
	{
		int result = 0;

		int levelNumber = -1;
		if( lua_gettop( lua ) >= 1 && lua_isnumber( lua, 1 ) )
			levelNumber = (int)lua_tointeger( lua, 1 );
		else
		{
			d2UnitAny_t* player = *d2PlayerUnit;
			if( player )
				levelNumber = player->path->room1->room2->level->levelNumber;
		}

		ActMap* map = NULL;
		std::unordered_map<int, ActMap*>::const_iterator mapit = g_cachedMaps.find( levelNumber );
		if( mapit != g_cachedMaps.end() )
			map = mapit->second;
		else
		{
			d2Level_t* currentLevel = getLevel( levelNumber );
			if( currentLevel )
				map = ActMap::getMap( currentLevel );
		}

		if( map )
		{
			ExitArray exits;
			map->getExits( exits );
			map->cleanUp();

			lua_newtable( lua );

			const int SIZE = exits.size();
			for( int i=0; i<SIZE; i++ )
			{
				const Exit& exit = exits[i];

				int target = exit.target;
				int x = exit.position.first;
				int y = exit.position.second;
				int type = exit.type;
				int tileId = exit.tileId;

				lua_newtable( lua );

					lua_pushnumber( lua, target );
					lua_setfield( lua, -2, "target" );

					lua_newtable( lua );

						lua_pushnumber( lua, x );
						lua_rawseti( lua, -2, 1 );

						lua_pushnumber( lua, y );
						lua_rawseti( lua, -2, 2 );

					lua_setfield( lua, -2, "position" );

					lua_pushnumber( lua, type );
					lua_setfield( lua, -2, "type" );

					lua_pushnumber( lua, tileId );
					lua_setfield( lua, -2, "tileId" );

				lua_rawseti( lua, -2, i+1 );
			}

			result = 1;
		}

		return result;
	}

	int dumpActMap( lua_State* lua )
	{
		int result = 0;

		if( lua_gettop( lua ) >= 1 && lua_isstring( lua, 1 ) )
		{
			const char* filename = lua_tostring( lua, 1 );

			d2UnitAny_t* player = *d2PlayerUnit;
			if( player )
			{
				d2Level_t* currentLevel = player->act->misc->levelFirst;
				if( currentLevel )
				{
					ActMap* map = ActMap::getMap( currentLevel );
					map->dumpLevel( filename );
				}
			}
		}

		return result;
	}

	/*int getConnectedLevels( lua_State* lua )
	{
		int result = 0;

		if( lua_gettop( lua ) >= 1 )
		{
			d2Level_t* level = (d2Level_t*)lua_touserdata( lua, 1 );

			if( level )
			{
				lua_newtable( lua );

				d2Room2_t* room2 = level->room2First;
				if( room2 )
				{
					d2Room2_t** connectedRooms = room2->room2Near;
					for( int i=0; i<room2->roomsNear; i++ )
					{
						d2Room2_t*
					}
				}
			}
		}

		return result;
	}*/

	void _precacheMap( int levelNumber )
	{
		if( g_cachedMaps.find( levelNumber ) == g_cachedMaps.end() )
		{
			d2Level_t* level = getLevel( levelNumber );
			g_cachedMaps.insert( std::pair<int, ActMap*>( levelNumber, ActMap::getMap( level ) ) );
		}
	}

	int precacheMap( lua_State* lua )
	{
		int result = 0;

		if( lua_gettop( lua ) >= 1 )
		{
			if( lua_isnumber( lua, 1 ) )
			{
				int levelNumber = (int)lua_tointeger( lua, 1 );

				_precacheMap( levelNumber );
			}
			else if( lua_istable( lua, 1 ) )
			{
				lua_pushnil( lua );

				while( lua_next( lua, -2 ) != 0 )
				{
					int levelNumber = (int)lua_tointeger( lua, -1 );
					_precacheMap( levelNumber );

					lua_pop( lua, 1 );
				}
			}
		}

		return result;
	}
}