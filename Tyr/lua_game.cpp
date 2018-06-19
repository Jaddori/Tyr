#include "lua_game.h"

#define GAME_STATE(name) lua_pushnumber( lua, name ); \
	lua_setfield( lua, -2, #name );

namespace lua_game
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "getState", getState );
		lua_register( lua, "getGameReady", getGameReady );

		lua_newtable( lua );

		GAME_STATE( OOG_NONE );
		GAME_STATE( OOG_LOBBY );
		GAME_STATE( OOG_INLINE );
		GAME_STATE( OOG_CHAT );
		GAME_STATE( OOG_CREATE );
		GAME_STATE( OOG_JOIN );
		GAME_STATE( OOG_LADDER );
		GAME_STATE( OOG_CHANNEL );
		GAME_STATE( OOG_MAIN_MENU );
		GAME_STATE( OOG_LOGIN );
		GAME_STATE( OOG_LOGIN_ERROR );
		GAME_STATE( OOG_UNABLE_TO_CONNECT );
		GAME_STATE( OOG_CHAR_SELECT );
		GAME_STATE( OOG_REALM_DOWN );
		GAME_STATE( OOG_DISCONNECTED );
		GAME_STATE( OOG_NEW_CHARACTER );
		GAME_STATE( OOG_CHARACTER_SELECT_PLEASE_WAIT );
		GAME_STATE( OOG_LOST_CONNECTION );
		GAME_STATE( OOG_D2SPLASH );
		GAME_STATE( OOG_CDKEY_IN_USE );
		GAME_STATE( OOG_DIFFICULTY );
		GAME_STATE( OOG_MAIN_MENU_CONNECTING );
		GAME_STATE( OOG_INVALID_CDKEY );
		GAME_STATE( OOG_CONNECTING );
		GAME_STATE( OOG_SERVER_DOWN );
		GAME_STATE( OOG_PLEASE_WAIT );
		GAME_STATE( OOG_GAME_EXIST );
		GAME_STATE( OOG_GATEWAY );
		GAME_STATE( OOG_GAME_DOES_NOT_EXIST );
		GAME_STATE( OOG_CHARACTER_CREATE );
		GAME_STATE( OOG_CHARACTER_CREATE_ALREADY_EXISTS );
		GAME_STATE( OOG_AGREE_TO_TERMS );
		GAME_STATE( OOG_NEW_ACCOUNT );
		GAME_STATE( OOG_PLEASE_READ );
		GAME_STATE( OOG_REGISTER_EMAIL );
		GAME_STATE( OOG_CREDITS );
		GAME_STATE( OOG_CINEMATICS );
		GAME_STATE( OOG_CHARACTOR_CHANGE_REALM );
		GAME_STATE( OOG_GAME_IS_FULL );
		GAME_STATE( OOG_OTHER_MULTIPLAYER );
		GAME_STATE( OOG_TCP_IP );
		GAME_STATE( OOG_ENTER_IP_ADDRESS );
		GAME_STATE( OOG_CHARACTER_SELECT_NO_CHARS );
		GAME_STATE( OOG_CHARACTER_SELECT_CHANGE_REALM );

		lua_setglobal( lua, "GameStates" );
	}

	int getState( lua_State* lua )
	{
		int result = 0;

		int location = OOG_NONE;
		if( clientState() == CLIENT_STATE_MENU )
		{
			if(findControl(CONTROL_BUTTON, 5103, -1, 330, 416, 128, 35))
				location = OOG_MAIN_MENU_CONNECTING;					//21 Connecting to Battle.net	
			else if(findControl(CONTROL_BUTTON, 5102, -1, 335, 412, 128, 35))
				location = OOG_LOGIN_ERROR;								//10 Login Error	
			else if (findControl(CONTROL_BUTTON, 5102, -1, 351,337,96,32))	//5102 =OK
			{
				if (findControl(CONTROL_TEXTBOX, 5351, -1, 268,320,264,120))	
					location = OOG_LOST_CONNECTION;						//17 lost connection	
				else if (findControl(CONTROL_TEXTBOX, 5347, -1, 268,320,264,120))
					location = OOG_DISCONNECTED;						//14  Disconnected
				else
					location = OOG_CHARACTER_CREATE_ALREADY_EXISTS;		//30 Character Create - Dupe Name									
			}
			else if(findControl(CONTROL_BUTTON, 5103, -1, 351,337,96,32))		//5103 = CANCEL
			{
				if(findControl(CONTROL_TEXTBOX, 5243, -1, 268, 300, 264, 100))
					location = OOG_CHARACTER_SELECT_PLEASE_WAIT;		//16 char select please wait...
				if (findControl(CONTROL_TEXTBOX, (char *)NULL, -1, 268,320,264,120))
					location = OOG_PLEASE_WAIT;							//25 "Please Wait..."single player already exists also
			}	
			else if(findControl(CONTROL_BUTTON, 5103, -1, 433, 433, 96, 32))
			{ 
				if (findControl(CONTROL_TEXTBOX, (char *)NULL, -1, 427,234,300,100))
					location = OOG_INLINE;								//2 waiting in line	
				else if(findControl(CONTROL_TEXTBOX, 10018, -1, 459, 380, 150, 12))
					location = OOG_CREATE;								//4 Create game
				else if(findControl(CONTROL_BUTTON, 5119, -1, 594, 433, 172, 32))
					location = OOG_JOIN;								// 5 Join Game
				else if(findControl(CONTROL_BUTTON, 5102, -1, 671, 433, 96, 32))
					location = OOG_CHANNEL;								//7 "Channel List"
				else
					location = OOG_LADDER;								//6 "Ladder"		
			}		
			else if(findControl(CONTROL_BUTTON, 5101, -1, 33,572,128,35))		//5101 = EXIT
			{
				if(findControl(CONTROL_BUTTON, 5288, -1, 264, 484, 272, 35))
					location = OOG_LOGIN;								//9 Login
				if (findControl(CONTROL_BUTTON, 5102, -1, 495,438,96,32))
					location = OOG_CHARACTER_SELECT_CHANGE_REALM;		//43 char select change realm						
				if(findControl(CONTROL_BUTTON, 5102, -1, 627,572,128,35) && findControl(CONTROL_BUTTON, 10832, -1, 33,528,168,60)) //10832=create new
				{
					if (findControl(CONTROL_BUTTON, 10018, -1, 264,297,272,35)) //NORMAL
						location = OOG_DIFFICULTY;						//20 single char Difficulty
					d2Control_t* pControl = findControl(CONTROL_TEXTBOX, (char *)NULL, -1, 37, 178, 200, 92);
					if(pControl && pControl->firstText && pControl->firstText->next)
						location = OOG_CHAR_SELECT;						//12 char select
					else
					{
						if (findControl(CONTROL_TEXTBOX, 11162, -1,45,318,531,140) || findControl(CONTROL_TEXTBOX, 11066, -1,45,318,531,140))	
							location = OOG_REALM_DOWN;
						// Look for CONNECTING... string
						else if (findControl(CONTROL_TEXTBOX, 11065, -1, 0x2D, 0x13E, 0x213, 0x8C))
							location = OOG_CONNECTING;
						else
							location = OOG_CHARACTER_SELECT_NO_CHARS;	//42 char info not loaded 
					}
				}
				if(findControl(CONTROL_BUTTON, 5101, -1, 33, 572, 128, 35))		//5101=Exit
				{
					if (findControl(CONTROL_BUTTON, 5102, 0, 627,572,128,35))			//5102=ok
						location = OOG_CHARACTER_CREATE;				//29 char create screen with char selected
					else
					{
						if(findControl(CONTROL_TEXTBOX, 5226, -1, 321, 448, 300, 32))
							location = OOG_NEW_ACCOUNT;					//32 create new bnet account
						else
							location = OOG_NEW_CHARACTER;				//15 char create screen no char selected
					}
				}
			}
			if(findControl(CONTROL_BUTTON, 5102, -1, 335, 450, 128, 35))
			{
				if(findControl(CONTROL_TEXTBOX, 5200, -1, 162, 270, 477, 50))
					location = OOG_CDKEY_IN_USE;						//19 CD-KEY in use
				else if (findControl(CONTROL_TEXTBOX, 5190, -1, 162,420,477,100))		 //5190="If using a modem"
					location = OOG_UNABLE_TO_CONNECT;					//11 unable to connect
				else		
					location = OOG_INVALID_CDKEY;						//22 invalid CD-KEY	
			}	
			else if (findControl(CONTROL_TEXTBOX, 5159, -1, 438, 300, 326, 150)) 
				location = OOG_GAME_DOES_NOT_EXIST;						//28 game doesn't exist
			else if (findControl(CONTROL_TEXTBOX, 5161, -1, 438, 300, 326, 150)) 
				location = OOG_GAME_IS_FULL;							//38 Game is full
			else if (findControl(CONTROL_TEXTBOX, 5138, -1, 438, 300, 326, 150)) 
				location = OOG_GAME_EXIST;								//26 Game already exists
			else if (findControl(CONTROL_TEXTBOX, 5139, -1, 438, 300, 326, 150)) 
				location = OOG_SERVER_DOWN;								//24 server down	
			else if (findControl(CONTROL_BUTTON, 5106, -1, 264,324,272,35))				//5106="SINGLE PLAYER"
				location = OOG_MAIN_MENU;								//8 Main Menu
			else if (findControl(CONTROL_BUTTON, 11126, -1, 27,480,120,20))					//11126=ENTER CHAT
				location = OOG_LOBBY;									//1 base bnet 
			else if (findControl(CONTROL_BUTTON, 5308, -1, 187,470,80,20))					//5308="HELP"
				location = OOG_CHAT;									//3 chat bnet 
			else if(findControl(CONTROL_TEXTBOX, 21882, -1, 100, 580, 600, 80))
				location = OOG_D2SPLASH;								//18 Spash	
			else if (findControl(CONTROL_BUTTON, 5102, -1, 281,538,96,32))
				location = OOG_GATEWAY;									//27 select gateway
			else if (findControl(CONTROL_BUTTON, 5181, -1, 525,513,128,35))
				location = OOG_AGREE_TO_TERMS;							//31 agree to terms
			else if (findControl(CONTROL_BUTTON, 5102, -1, 525,513,128,35))
				location = OOG_PLEASE_READ;								//33 please read
			else if (findControl(CONTROL_BUTTON, 11097, -1, 265,527,272,35))
				location = OOG_REGISTER_EMAIL;							//34 register email
			else if (findControl(CONTROL_BUTTON, 5101, -1, 33,578,128,35))
				location = OOG_CREDITS;									//35 Credits
			else if (findControl(CONTROL_BUTTON, 5103, -1, 334,488,128,35))
				location = OOG_CINEMATICS;								//36 Cinematics
			else if (findControl(CONTROL_BUTTON, 5116, -1, 264,350,272,35))
				location =	OOG_OTHER_MULTIPLAYER;						//39 other multi player
			else if (findControl(CONTROL_BUTTON, 5103, -1,281,337,96,32))
				location = OOG_ENTER_IP_ADDRESS;						//41 enter ip	
			else if (findControl(CONTROL_BUTTON, 5118, -1,265,206,272,35))
				location =	OOG_TCP_IP;									//40 tcp-ip

			lua_pushnumber( lua, location );
			result = 1;
		}

		return result;
	}

	int getGameReady( lua_State* lua )
	{
		int result = 0;

		bool ready = ( clientState() == CLIENT_STATE_IN_GAME );
		lua_pushboolean( lua, ready );
		result = 1;

		return result;
	}
}