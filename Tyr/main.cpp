#include <Windows.h>
#include <stdio.h>
#include "reroute.h"
#include "lua_binds.h"

HMODULE g_module = NULL;
LuaBinds g_binds = {};

INT APIENTRY DllMain( HINSTANCE handle, DWORD reason, LPVOID reserved )
{
	switch( reason )
	{
		case DLL_PROCESS_ATTACH:
		{
			g_module = handle;
		} break;

		case DLL_PROCESS_DETACH:
		{
		} break;
	}

	return TRUE;
}

void DrawIntercept(void)
{
	lua_update( &g_binds );
	lua_render( &g_binds );
}

void Startup()
{
	DWORD baseAddress = (DWORD)GetModuleHandle( NULL );
	reroute( (LPVOID)(baseAddress+0x53B30), DrawIntercept );

	initializeInterface( baseAddress );

	lua_bind( &g_binds );
	lua_start( &g_binds );
}

void Shutdown()
{
	lua_stop( &g_binds );
}

extern "C" __declspec(dllexport) int hookProc( int code, WPARAM wparam, LPARAM lparam )
{
	if( code >= 0 )
	{
		CWPSTRUCT* cw = (CWPSTRUCT*)lparam;

		switch( cw->message )
		{
			case WM_COPYDATA:
			{
				COPYDATASTRUCT* copyData = (COPYDATASTRUCT*)lparam;

				int isStartup = (int)copyData->dwData;
				if( isStartup )
					Startup();
				else
					Shutdown();
			} break;

			default:
				break;
		}
	}

	return CallNextHookEx( NULL, code, wparam, lparam );
}