#include "lua_filesystem.h"

namespace lua_filesystem
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "getFiles", getFiles );
		lua_register( lua, "messageBox", messageBox );
	}

	int getFiles( lua_State* lua )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 || nargs == 2 )
		{
			const char* directory = lua_tostring( lua, 1 );

			if( nargs == 1 || !lua_istable( lua, 2 ) )
			{
				result = 1;
				lua_newtable( lua );
			}

			int index = 1;
			WIN32_FIND_DATAA findData = {};
			HANDLE findHandle = FindFirstFileA( directory, &findData );
			if( findHandle != INVALID_HANDLE_VALUE )
			{
				do
				{
					if( (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0 )
					{
						lua_pushstring( lua, findData.cFileName );
						lua_rawseti( lua, -2, index );
						index++;
					}
				} while( FindNextFileA( findHandle, &findData ) != 0 );
			}
		}

		return result;
	}

	int messageBox( lua_State* lua )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 || nargs == 2 )
		{
			const char* text = lua_tostring( lua, 1 );

			const char* title = "Tyr";
			if( nargs == 2 )
				title = lua_tostring( lua, 2 );

			MessageBoxA( NULL, text, title, MB_OK );
		}

		return result;
	}
}