#include <Windows.h>
#include <stdio.h>

int main( int argc, char* argv[] )
{
	if( argc >= 2 )
	{
		const char* D2_DIR = argv[1];
		char cmdLine[256] = {};
		_snprintf( cmdLine, 256, "%s/Game.exe -res640 -w", D2_DIR );
		cmdLine[255] = 0;

		printf( "Running: %s\n", cmdLine );

		printf( "Starting Diablo II.\n" );
		STARTUPINFO d2StartupInfo = {};
		d2StartupInfo.cb = sizeof(d2StartupInfo);

		PROCESS_INFORMATION d2ProcessInfo;
		if( !CreateProcessA( NULL, cmdLine, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, D2_DIR, &d2StartupInfo, &d2ProcessInfo ) )
		{
			printf( "Failed to start Diablo II.\n" );
			getchar();
			return -1;
		}

		Sleep( 500 );

		printf( "Loading hook DLL.\n" );
		HMODULE hookDLL = LoadLibrary( "Tyr.dll" );
		if( !hookDLL )
		{
			printf( "Failed to load hook DLL.\n" );
			getchar();
			return -1;
		}

		HOOKPROC hookProc = (HOOKPROC)GetProcAddress( hookDLL, "hookProc" );
		if( !hookProc )
		{
			printf( "Failed to find hook procedure address.\n" );
			getchar();
			return -1;
		}

		printf( "Hooking process.\n" );
		HHOOK hook = SetWindowsHookEx( WH_CALLWNDPROC, hookProc, hookDLL, d2ProcessInfo.dwThreadId );
		if( !hook )
		{
			printf( "Failed to hook process.\n" );
			getchar();
			return -1;
		}

		HWND d2Window = FindWindow( NULL, "Diablo II" );
		if( !d2Window )
		{
			printf( "Failed to find Diablo II window.\n" );
			getchar();
			return -1;
		}
		Sleep(1000);

		COPYDATASTRUCT copyData = {};
		copyData.dwData = 1; // 1 means startup
		copyData.cbData = sizeof(DWORD);
		SendMessage( d2Window, WM_COPYDATA, NULL, (LPARAM)&copyData );

		printf( "Press enter to stop Tyr...\n" );
		getchar();

		UnhookWindowsHookEx( hook );
		TerminateProcess( d2ProcessInfo.hProcess, 0 );
	}

	return 0;
}