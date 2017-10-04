#pragma once

#include <Windows.h>

//FUNCPTR(D2GFX, DrawRectangle, void __stdcall, (int X1, int Y1, int X2, int Y2, DWORD dwColor, DWORD dwTrans), 0xF6300) //Updated 1.14d //004F6300-BASE
//FUNCPTR(D2GFX, DrawLine, void __stdcall, (int X1, int Y1, int X2, int Y2, DWORD dwColor, DWORD dwUnk), 0xF6380) //Updated 1.14d //004F6380-BASE

//FUNCPTR(D2WIN, DrawText, void __fastcall, (const wchar_t *wStr, int xPos, int yPos, DWORD dwColor, DWORD dwUnk), 0x102320) //Updated 1.14d //00502320-BASE
//FUNCPTR(D2WIN, GetTextSize, DWORD __fastcall, (wchar_t *wStr, DWORD* dwWidth, DWORD* dwFileNo), 0x102520) //Updated 1.14d //00502520-BASE
//FUNCPTR(D2WIN, SetTextSize, DWORD __fastcall, (DWORD dwSize), 0x102EF0) //Updated 1.14d //00502EF0-BASE

#define d2DrawRectangleOffset	0xF6300
#define d2DrawLineOffset		0xF6380
#define d2DrawTextOffset		0x102320
#define d2GetTextSizeOffset		0x102520
#define d2SetTextSizeOffset		0x102EF0

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

void initializeInterface( DWORD baseAddress );