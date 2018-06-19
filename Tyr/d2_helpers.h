#pragma once

#include "d2_constants.h"
#include "d2_interface.h"
#include "d2_structures.h"

enum ClientGameState
{
	CLIENT_STATE_NULL = 0,
	CLIENT_STATE_MENU,
	CLIENT_STATE_IN_GAME,
	CLIENT_STATE_BUSY
};

wchar_t* ansiToUnicode(const char* str);
char* unicodeToAnsi(const wchar_t* str);
void stringToLower( char* p );
bool stringToBool( const char* str );
void stringReplace( char* str, const char find, const char replace, size_t buflen );

void sendMouseClick( int x, int y, int clickType );

int clientState();
d2Control_t* findControl( int type, int localeID, int disabled, int posX, int posY, int sizeX, int sizeY );
d2Control_t* findControl( int type, const char* text, int disabled, int posX, int posY, int sizeX, int sizeY );
bool clickControl( d2Control_t* control, int x = -1, int y = -1 );
//bool selectCharacter( char* name );