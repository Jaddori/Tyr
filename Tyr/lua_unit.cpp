#include "lua_unit.h"

namespace lua_unit
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "getUnitPosition", getUnitPosition );
		lua_register( lua, "getDistanceBetweenUnits", getDistanceBetweenUnits );
		lua_register( lua, "getUnitType", getUnitType );
	}

	int getUnitPosition( lua_State* lua )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs >= 1 && lua_isuserdata( lua, 1 ) )
		{
			int curArg = 1;
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, curArg++ );

			int tableIndex = curArg;
			if( nargs < curArg || !lua_istable( lua, curArg ) )
			{
				lua_newtable( lua );
				tableIndex = -2;
			}

			lua_pushnumber( lua, unit->path->x );
			lua_rawseti( lua, tableIndex, 1 );
			lua_pushnumber( lua, unit->path->y );
			lua_rawseti( lua, tableIndex, 2 );
		}

		return result;
	}

	int getDistanceBetweenUnits( lua_State* lua )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 && lua_isuserdata( lua, 1 ) && lua_isuserdata( lua, 2 ) )
		{
			int curArg = 1;
			d2UnitAny_t* a = (d2UnitAny_t*)lua_touserdata( lua, curArg++ );
			d2UnitAny_t* b = (d2UnitAny_t*)lua_touserdata( lua, curArg++ );

			int x1 = a->path->x;
			int y1 = a->path->y;
			int x2 = b->path->x;
			int y2 = b->path->y;
			float dist = getDistance( x1, y1, x2, y2 );

			lua_pushnumber( lua, dist );
			result = 1;
		}

		return result;
	}

	int getUnitType( lua_State* lua )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 && lua_isuserdata( lua, 1 ) )
		{
			int curArg = 1;
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, curArg++ );

			int type = unit->textFileNumber;
			lua_pushnumber( lua, type );
			result = 1;
		}

		return result;
	}
}