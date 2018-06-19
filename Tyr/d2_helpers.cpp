#include "d2_helpers.h"
#include <stdio.h>

wchar_t* ansiToUnicode(const char* str)
{
	wchar_t* buf = NULL;
	int len = MultiByteToWideChar(1252, 0, str, -1, buf, 0);
	buf = new wchar_t[len];
	MultiByteToWideChar(1252, 0, str, -1, buf, len);
	return buf;
}

char* unicodeToAnsi(const wchar_t* str)
{
	char* buf = NULL;
	int len = WideCharToMultiByte(1252, 0, str, -1, buf, 0, "?", NULL);
	buf = new char[len];
	WideCharToMultiByte(1252, 0, str, -1, buf, len, "?", NULL);
	return buf;
}

void stringToLower(char* p)
{
	for ( ; *p; ++p) *p = tolower(*p);
}
bool stringToBool(const char* str)
{
	switch(tolower(str[0]))
	{
		case 't': case '1':
			return true;
		case 'f': case '0': default:
			return false;
	}
}

void stringReplace(char* str, const char find, const char replace, size_t buflen)
{
	for(size_t i = 0; i < buflen; i++)
	{
		if(str[i] == find)
			str[i] = replace;
	}
}

void sendMouseClick( int x, int y, int clickType )
{
	LPARAM lp = x + ( y << 16 );

	switch( clickType )
	{
		case 0: PostMessage( d2GetHwnd(), WM_LBUTTONDOWN, 0, lp ); break;
		case 1: PostMessage( d2GetHwnd(), WM_LBUTTONUP, 0, lp ); break;
		case 2: PostMessage( d2GetHwnd(), WM_RBUTTONDOWN, 0, lp ); break;
		case 3: PostMessage( d2GetHwnd(), WM_RBUTTONUP, 0, lp ); break;
	}
}

int clientState()
{
	int result = CLIENT_STATE_NULL;
	d2UnitAny_t* player = *d2PlayerUnit;
	d2Control_t* firstControl = *d2FirstControl;

	if( player && !firstControl )
	{
		if( player && player->updateUnit )
		{
			result = CLIENT_STATE_BUSY;
		}
		else
		{
			if( player->inventory &&
				player->path &&
				player->path->room1 &&
				player->path->room1->room2 &&
				player->path->room1->room2->level &&
				player->path->room1->room2->level->levelNumber )
			{
				result = CLIENT_STATE_IN_GAME;
			}
			else
				result = CLIENT_STATE_BUSY;
		}
	}
	else if( !player && firstControl )
		result = CLIENT_STATE_MENU;

	return result;
}

d2Control_t* findControl(int type, int localeID, int disabled, int posX, int posY, int sizeX, int sizeY)
{
	if(clientState() != CLIENT_STATE_MENU)
	{
		MessageBoxA( NULL, "NOT MENU, ABRORTINH", "Tyr", MB_OK );
		return NULL;
	}

	char* localeStr = NULL; 
	if(localeID >= 0)
	{
		//localeStr = unicodeToAnsi(D2LANG_GetLocaleText((WORD)LocaleID));
		localeStr = unicodeToAnsi( d2GetLocaleText( (WORD)localeID ) );
		if(!localeStr)
		{
			MessageBoxA( NULL, "NO STRING FOUND; ABORTINGH", "TYR", MB_OK );
			return NULL;
		}

		d2Control_t* res = findControl(type, localeStr, disabled, posX, posY, sizeX, sizeY);
		delete[] localeStr;
		return res;
	}
	else
		MessageBoxA( NULL, "LOCALID < 0, ABORTYING", "TYR", MB_OK );

	return NULL;
}

d2Control_t* findControl( int type, const char* text, int disabled, int posX, int posY, int sizeX, int sizeY )
{
	d2Control_t* result = NULL;

	if( clientState() == CLIENT_STATE_MENU )
	{
		if( type == -1 && text == NULL && disabled == -1 && posX == -1 && posY == -1 && sizeX == -1 && sizeY == -1 )
		{
			result = *d2FirstControl;
		}
		else
		{
			bool found = false;
			for( d2Control_t* control = *d2FirstControl; control && !result; control = control->next )
			{
				if(type >= 0 && static_cast<int>(control->type) == type)
					found = TRUE;
				else if(type >= 0 && static_cast<int>(control->type) != type)
				{
					found = FALSE;
					continue;
				}

				if(disabled >= 0 && static_cast<int>(control->disabled) == disabled)
				{
					if(control->type == CONTROL_BUTTON && control->unknownState == 1)
					{
						found = FALSE;
						continue;
					}
					found = TRUE;
				}
				else if(disabled >= 0 && static_cast<int>(control->disabled) != disabled)
				{			
					found = FALSE;
					continue;
				}

				if(posX >= 0 && static_cast<int>(control->x) == posX)
					found = TRUE;
				else if(posX >= 0 && static_cast<int>(control->x) != posX)
				{
					found = FALSE;
					continue;
				}

				if(posY >= 0 && static_cast<int>(control->y) == posY)
					found = TRUE;
				else if(posY >= 0 && static_cast<int>(control->y) != posY)
				{
					found = FALSE;
					continue;
				}

				if(sizeX >= 0 && static_cast<int>(control->width) == sizeX)
					found = TRUE;
				else if(sizeX >= 0 && static_cast<int>(control->width) != sizeX)
				{
					found = FALSE;
					continue;
				}

				if(sizeY >= 0 && static_cast<int>(control->height) == sizeY)
					found = TRUE;
				else if(sizeY >= 0 && static_cast<int>(control->height) != sizeY)
				{
					found = FALSE;
					continue;
				}

				if(text && control->type == CONTROL_BUTTON)
				{
					char* text2 = unicodeToAnsi(control->buttonText);
					if(!text2)
						return NULL;

					if(strcmp(text2, text) == 0)
					{
						found = TRUE;
						delete[] text2;
					}
					else
					{
						found = FALSE;
						delete[] text2;
						continue;
					}
				}

				if(text && control->type == CONTROL_TEXTBOX)
				{
					if(control->firstText != NULL && control->firstText->textw[0] != NULL)
					{
						char* text2 = unicodeToAnsi(control->firstText->textw[0]);
						if(!text2)
							return NULL;
						if(strstr(text, text2) != 0)
						{
							found = TRUE;
							delete[] text2;
						}
						else
						{
							found = FALSE;
							delete[] text2;
							continue;
						}
					}
					else
					{
						found = FALSE;
						continue;
					}
				}

				if(found)
				{
					return control;
				}
			}
		}
	}

	return result;
}

bool clickControl( d2Control_t* control, int x, int y )
{
	bool result = false;

	if( clientState() == CLIENT_STATE_MENU && control )
	{
		if( x == -1 )
			x = control->x + ( control->width / 2 );
		if( y == -1 )
			y = control->y - ( control->height / 2 );

		Sleep( 100 );
		sendMouseClick( x, y, 0 );
		Sleep( 100 );
		sendMouseClick( x, y, 1 );
		Sleep( 100 );

		result = true;
	}

	return result;
}