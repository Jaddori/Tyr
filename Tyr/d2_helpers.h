#pragma once

#include "d2_constants.h"
#include "d2_interface.h"
#include "d2_structures.h"
#include <cmath>

enum DistanceType
{
	Euclidean, Chebyshev, Manhattan
};

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
bool clickMap( int x, int y, int clickType, bool shift, d2UnitAny_t* unit );

int clientState();
d2Control_t* findControl( int type, int localeID, int disabled, int posX, int posY, int sizeX, int sizeY );
d2Control_t* findControl( int type, const char* text, int disabled, int posX, int posY, int sizeX, int sizeY );
bool clickControl( d2Control_t* control, int x = -1, int y = -1 );
//bool selectCharacter( char* name );

const char* getUnitName(d2UnitAny_t* pUnit, char* szBuf, size_t bufSize);
void getItemCode(d2UnitAny_t* pUnit, char* szBuf);
DWORD getTileLevelNo(d2Room2_t* lpRoom2, DWORD dwTileNo);

static inline void addRoomData(d2Room2_t* room) { d2AddRoomData(room->level->misc->act, room->level->levelNumber, room->x, room->y, room->room1); }
static inline void removeRoomData(d2Room2_t* room) { d2RemoveRoomData(room->level->misc->act, room->level->levelNumber, room->x, room->y, room->room1); }
static inline char* __stdcall getLevelName(const d2Level_t* level) { return d2GetLevelText(level->levelNumber)->name; }
static inline char* __stdcall getLevelIdName(DWORD level) { return d2GetLevelText(level)->name; }

double getDistance( long x1, long y1, long x2, long y2, DistanceType type = Euclidean );

d2Level_t* getLevel( DWORD levelNumber );
bool gameReady();