#include "lua_menu.h"

namespace lua_menu
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "selectCharacter", selectCharacter );
		lua_register( lua, "findButton", findButton );
		lua_register( lua, "clickControl", clickControl );
		lua_register( lua, "printAllControls", printAllControls );
	}

	int selectCharacter( lua_State* lua )
	{
		int result = 0;

		if( lua_gettop( lua ) >= 1 )
		{
			const char* name = lua_tostring( lua, 1 );
			bool success = false;

			if( clientState() == CLIENT_STATE_MENU )
			{
				d2Control_t* control = ::findControl( CONTROL_TEXTBOX, NULL, -1, 237, 178, 72, 93 );
				d2ControlText_t* text = NULL;

				while( control && !success )
				{
					if( control->type == CONTROL_TEXTBOX && control->firstText && control->firstText->next )
					{
						text = control->firstText->next;
					}
					else
						text = NULL;

					if( text )
					{char* line = unicodeToAnsi( text->textw[0] );
						if( line )
						{
							char* lineLower = _strdup( line );
							char* nameLower = _strdup( name );

							stringToLower( lineLower );
							stringToLower( nameLower );

							if( strlen( line ) == strlen( name ) && strstr( lineLower, nameLower ) != NULL )
							{
								if( clickControl( control ) )
								{
									control = ::findControl( -1, "OK", -1, -1, -1, -1, -1 );

									if( control )
									{
										if( clickControl( control ) )
											success = true;
									}
								}
							}

							delete[] line;
							delete[] lineLower;
							delete[] nameLower;
						}
					}

					if( control )
						control = control->next;
				}
			}

			lua_pushboolean( lua, success );
			result = 1;
		}

		return result;
	}

	int findButton( lua_State* lua )
	{
		int result = 0;

		if( lua_gettop( lua ) >= 1 && lua_isstring( lua, 1 ) )
		{
			const char* text = lua_tostring( lua, 1 );
			//MessageBoxA( NULL, text, "NUB", MB_OK );

			d2Control_t* control = ::findControl( CONTROL_BUTTON, text, -1, -1, -1, -1, -1 );

			if( control )
			{
				lua_pushlightuserdata( lua, control );
				result = 1;
			}
			//else
				//MessageBoxA( NULL, "NO CONTROL FOUND", "NUT", MB_OK );
		}

		return result;
	}

	int clickControl( lua_State* lua )
	{
		int result = 0;

		if( lua_gettop( lua ) >= 1 && lua_isuserdata( lua, 1 ) )
		{
			d2Control_t* control = (d2Control_t*)lua_touserdata( lua, 1 );

			if( control )
			{
				bool success = ::clickControl( control );
				lua_pushboolean( lua, success );
				result = 1;
			}
		}

		return result;
	}

	int printAllControls( lua_State* lua )
	{
		int result = 0;

		for( d2Control_t* control = *d2FirstControl; control; control = control->next )
		{
			if( control->type == CONTROL_BUTTON )
			{
				if( control->buttonText )
					MessageBoxW( NULL, control->buttonText, L"TYR", MB_OK );
			}
		}

		return result;
	}
}