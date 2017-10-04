#pragma once

#include <Windows.h>

// function offsets
#define d2DrawRectangleOffset	0xF6300
#define d2DrawLineOffset		0xF6380
#define d2DrawTextOffset		0x102320
#define d2GetTextSizeOffset		0x102520
#define d2SetTextSizeOffset		0x102EF0

// variable offsets
#define d2ScreenSizeXOffset		0x31146C
#define d2ScreenSizeYOffset		0x311470
#define d2MouseXOffset			0x3A6AB0
#define d2MouseYOffset			0x3A6AAC
#define d2MouseOffsetYOffset	0x3A5208
#define d2MouseOffsetXOffset	0x3A5214
#define d2MouseOffsetZOffset	0x3A520C

// functions
typedef void (__stdcall d2DrawRectangle_t)( int x1, int y1, int x2, int y2, DWORD color, DWORD transparency );
typedef void (__stdcall d2DrawLine_t)( int x1, int y1, int x2, int y2, DWORD color, DWORD unknown );

typedef void (__fastcall d2DrawText_t)( const wchar_t* str, int x, int y, DWORD color, DWORD unknown );
typedef void (__fastcall d2GetTextSize_t)( wchar_t* str, DWORD* width, DWORD* fileNo );
typedef void (__fastcall d2SetTextSize_t)( DWORD size );

extern d2DrawRectangle_t* d2DrawRectangle;
extern d2DrawLine_t* d2DrawLine;

extern d2DrawText_t* d2DrawText;
extern d2GetTextSize_t* d2GetTextSize;
extern d2SetTextSize_t* d2SetTextSize;

//  variables
extern DWORD* d2ScreenSizeX;
extern DWORD* d2ScreenSizeY;
extern DWORD* d2MouseX;
extern DWORD* d2MouseY;
extern DWORD* d2MouseOffsetY;
extern DWORD* d2MouseOffsetX;
extern DWORD* d2MouseOffsetZ;

void initializeInterface( DWORD baseAddress );