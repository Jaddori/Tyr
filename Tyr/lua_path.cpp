#include "lua_path.h"
using namespace Mapping;
using namespace Pathing;
using namespace Reducing;

namespace lua_path
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "getPath", getPath );

		lua_newtable( lua );

		lua_pushnumber( lua, REDUCER_NONE );
		lua_setfield( lua, -2, "None" );
		
		lua_pushnumber( lua, REDUCER_WALK );
		lua_setfield( lua, -2, "Walk" );

		lua_pushnumber( lua, REDUCER_TELEPORT );
		lua_setfield( lua, -2, "Teleport" );

		lua_setglobal( lua, "Reducer" );
	}

	int getPath( lua_State* lua )
	{
		int result = 0;

		int args = lua_gettop( lua );
		if( args >= 5 )
		{
			int levelNumber = (int)lua_tonumber( lua, 1 );
			int x = (int)lua_tonumber( lua, 2 );
			int y = (int)lua_tonumber( lua, 3 );
			int dx = (int)lua_tonumber( lua, 4 );
			int dy = (int)lua_tonumber( lua, 5 );

			int reductionType = 0;
			int radius = 20;

			if( args >= 6 )
				reductionType = (int)lua_tonumber( lua, 6 );
			if( args >= 7 )
				radius = (int)lua_tonumber( lua, 7 );

			d2Level_t* level = getLevel( levelNumber );
			if( level )
			{
				ActMap* map = ActMap::getMap( level );
				Point start( x, y ), end( dx, dy );

				PathReducer* reducer = NULL;
				switch( reductionType )
				{
					default:
					case REDUCER_NONE: reducer = new NoPathReducer( map ); break;
					case REDUCER_WALK: reducer = new WalkPathReducer( map, diagonalShortcut, radius ); break;
					case REDUCER_TELEPORT: reducer = new TeleportPathReducer( map, diagonalShortcut, radius ); break;
				}

				PointList list;
				AStarPath<> path( map, reducer );
				path.getPath( start, end, list, true );
				map->cleanUp();
				delete reducer;

				int count = list.size();

				lua_newtable( lua );
				for( int i=0; i<count; i++ )
				{
					lua_newtable( lua );
						lua_pushnumber( lua, list[i].first );
						lua_rawseti( lua, -2, 1 );

						lua_pushnumber( lua, list[i].second );
						lua_rawseti( lua, -2, 2 );
					lua_rawseti( lua, -2, i+1 );
				}

				result = 1;
			}
		}

		return result;
	}
}