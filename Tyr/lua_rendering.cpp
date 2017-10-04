#include "lua_rendering.h"

namespace lua_rendering
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "drawRectangle", drawRectangle );
		lua_register( lua, "drawLine", drawLine );
		lua_register( lua, "drawText", drawText );
	}

	int drawRectangle( lua_State* lua )
	{
		int nargs = lua_gettop( lua );
		if( nargs >= 2 )
		{
			// min
			lua_rawgeti( lua, 1, 1 );
			int x1 = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 1, 2 );
			int y1 = (int)lua_tointeger( lua, -1 );

			// max
			lua_rawgeti( lua, 2, 1 );
			int x2 = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			int y2 = (int)lua_tointeger( lua, -1 );

			// color & transparency
			DWORD color = 0;
			DWORD trans = 0xFF;

			if( nargs >= 3 )
				color = (int)lua_tointeger( lua, 3 );
			if( nargs >= 4 )
				trans = (int)lua_tointeger( lua, 4 );

			d2DrawRectangle( x1, y1, x2, y2, color, trans );
		}

		return 0;
	}

	int drawLine( lua_State* lua )
	{
		int nargs = lua_gettop( lua );
		if( nargs >= 2 )
		{
			// from
			lua_rawgeti( lua, 1, 1 );
			int x1 = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 1, 2 );
			int y1 = (int)lua_tointeger( lua, -1 );

			// to
			lua_rawgeti( lua, 2, 1 );
			int x2 = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			int y2 = (int)lua_tointeger( lua, -1 );

			// color
			DWORD color = 0xFF;
			if( nargs >= 3 )
				color = (DWORD)lua_tointeger( lua, 3 );

			d2DrawLine( x1, y1, x2, y2, color, 0 );
		}

		return 0;
	}

	int drawText( lua_State* lua )
	{
		int nargs = lua_gettop( lua );
		if( nargs >= 2 )
		{
			// text
			const char* str = lua_tostring( lua, 1 );

			// position
			lua_rawgeti( lua, 2, 1 );
			int x = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			int y = (int)lua_tointeger( lua, -1 );

			// color
			DWORD color = 0xFF;
			if( nargs >= 3 )
				color = (DWORD)lua_tointeger( lua, 3 );

			wchar_t buf[1024] = {};
			mbstowcs( buf, str, 1024 );
			d2DrawText( buf, x, y, color, 0 );
		}

		return 0;
	}
}