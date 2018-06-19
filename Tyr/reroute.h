#pragma once

#include <Windows.h>

#define NOP		0x90
#define JMP		0xE9
#define INT3	0xCC
#define CALL	0xE8
#define RET		0xC3

void reroute( BYTE inst, LPVOID addr, LPVOID func, SIZE_T size = 5 );