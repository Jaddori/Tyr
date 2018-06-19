#include "reroute.h"

void reroute( BYTE inst, LPVOID addr, LPVOID func, SIZE_T size )
{
	const int MAX_POSSIBLE_SIZE = 16;

	BYTE code[MAX_POSSIBLE_SIZE] = { inst };
	memset( code+1, NOP, MAX_POSSIBLE_SIZE-1 ); // fill code with NOP instructions

	DWORD functionOffset = (DWORD)func - ( (DWORD)addr + 5 );
	memcpy( code+1, &functionOffset, sizeof(functionOffset) );

	DWORD oldProtect;
	VirtualProtect( addr, size, PAGE_READWRITE, &oldProtect );

	memcpy( addr, code, size );
	VirtualProtect( addr, size, oldProtect, NULL );
}