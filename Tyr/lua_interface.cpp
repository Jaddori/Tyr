#include "lua_interface.h"

namespace lua_interface
{
	void bind( lua_State* lua )
	{
		lua_register( lua, "getScreenSize", getScreenSize );
		lua_register( lua, "getMousePosition", getMousePosition );
		lua_register( lua, "getMouseOffset", getMouseOffset );
	}

	LDEC( getQuestInfo )
	{
		d2QuestInfo_t* info = (d2QuestInfo_t*)d2GetQuestInfo();
		lua_pushlightuserdata( lua, info );

		return 1;
	}

	LDEC( submitItem )
	{
		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD itemId = (DWORD)lua_tointeger( lua, 1 );
			d2SubmitItem( itemId );
		}

		return 0;
	}

	LDEC( transmute )
	{
		d2Transmute();

		return 0;
	}

	LDEC( findClientSideUnit )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			DWORD id = (DWORD)lua_tointeger( lua, 1 );
			DWORD type = (DWORD)lua_tointeger( lua, 2 );

			d2UnitAny_t* unit = d2FindClientSideUnit( id, type );
			if( unit )
			{
				lua_pushlightuserdata( lua, unit );
				result = 1;
			}
		}

		return result;
	}

	LDEC( findServerSideUnit )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			DWORD id = (DWORD)lua_tointeger( lua, 1 );
			DWORD type = (DWORD)lua_tointeger( lua, 2 );

			d2UnitAny_t* unit = d2FindServerSideUnit( id, type );
			if( unit )
			{
				lua_pushlightuserdata( lua, unit );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getCurrentInteractingNPC )
	{
		int result = 0;

		d2UnitAny_t* unit = d2GetCurrentInteractingNPC();
		if( unit )
		{
			lua_pushlightuserdata( lua, unit );
			result = 1;
		}

		return result;
	}

	LDEC( getSelectedUnit )
	{
		int result = 0;

		d2UnitAny_t* unit = d2GetSelectedUnit();
		if( unit )
		{
			lua_pushlightuserdata( lua, unit );
			result = 1;
		}

		return result;
	}

	LDEC( getCursorItem )
	{
		int result = 0;

		d2UnitAny_t* item = d2GetCursorItem();
		if( item )
		{
			lua_pushlightuserdata( lua, item );
			result = 1;
		}

		return result;
	}

	LDEC( getItemName )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2UnitAny_t* item = (d2UnitAny_t*)lua_touserdata( lua, 1 );

			if( item )
			{
				wchar_t buffer[1024] = {};
				BOOL retval = d2GetItemName( item, buffer, 1024 );

				lua_pushboolean( lua, retval );
				result = 1;

				if( retval )
				{
					char cbuffer[1024] = {};
					WideCharToMultiByte( CP_UTF8, WC_COMPOSITECHECK, buffer, -1, cbuffer, 1024, NULL, NULL );
					lua_pushstring( lua, cbuffer );
					result = 2;
				}
			}
		}

		return result;
	}

	LDEC( loadItemDescription )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			d2UnitAny_t* item = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			int type = (int)lua_tointeger( lua, 2 );

			if( item )
			{
				BOOL retval = d2LoadItemDescription( item, type );
				lua_pushboolean( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getMonsterOwner )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD monsterId = (DWORD)lua_tointeger( lua, 1 );

			DWORD retval = d2GetMonsterOwner( monsterId );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getUnitHPPercent )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD unitId = (DWORD)lua_tointeger( lua, 1 );

			DWORD retval = d2GetUnitHPPercent( unitId );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( initInventory )
	{
		d2InitInventory();
		return 0;
	}

	LDEC( setUIVariable )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			DWORD variableNumber = (DWORD)lua_tointeger( lua, 1 );
			DWORD howSet = (DWORD)lua_tointeger( lua, 2 );

			DWORD retval = d2SetUIVariable( variableNumber, howSet, 0 );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getUnitPosition )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs >= 1 )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );

			if( unit )
			{
				int x = d2GetUnitX( unit );
				int y = d2GetUnitY( unit );

				if( nargs < 2 || !lua_istable( lua, 2 ) )
				{
					result = 1;
					lua_newtable( lua );
				}

				lua_pushnumber( lua, x );
				lua_rawseti( lua, -2, 1 );
				lua_pushnumber( lua, y );
				lua_rawseti( lua, -2, 2 );
			}
		}

		return result;
	}

	LDEC( shopAction )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 5 )
		{
			d2UnitAny_t* npc = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			d2UnitAny_t* item = (d2UnitAny_t*)lua_touserdata( lua, 2 );
			DWORD sell = (DWORD)lua_tointeger( lua, 3 );
			DWORD itemCost = (DWORD)lua_tointeger( lua, 4 );
			DWORD mode = (DWORD)lua_tointeger( lua, 5 );

			if( npc && item )
				d2ShopAction( npc, item, sell, 0, itemCost, mode, 0, 0 );
		}

		return result;
	}

	LDEC( closeNPCInteract )
	{
		d2CloseNPCInteract();
		return 0;
	}
	LDEC( closeInteract )
	{
		d2CloseInteract();
		return 0;
	}

	LDEC( getAutomapSize )
	{
		DWORD size = d2GetAutomapSize();
		lua_pushboolean( lua, size );
		return 1;
	}
	LDEC( newAutomapCell )
	{
		d2AutomapCell_t* cell = d2NewAutomapCell();
		lua_pushlightuserdata( lua, cell );
		return 1;
	}
	LDEC( addAutomapCell )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			d2AutomapCell_t* cell = (d2AutomapCell_t*)lua_touserdata( lua, 1 );
			d2AutomapCell_t* node = (d2AutomapCell_t*)lua_touserdata( lua, 2 );

			d2AddAutomapCell( cell, &node );
		}

		return result;
	}

	LDEC( revealAutomapRoom )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			d2Room1_t* room = (d2Room1_t*)lua_touserdata( lua, 1 );
			DWORD clipFlag = (DWORD)lua_tointeger( lua, 2 );
			d2AutomapLayer_t* layer = (d2AutomapLayer_t*)lua_touserdata( lua, 3 );

			d2RevealAutomapRoom( room, clipFlag, layer );
		}

		return result;
	}

	LDEC( initAutomapLayer_I )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD layer = (DWORD)lua_tointeger( lua, 1 );

			d2AutomapLayer_t* retval = d2InitAutomapLayer_I( layer );
			lua_pushlightuserdata( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( clickMap )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			DWORD mouseFlag = (DWORD)lua_tointeger( lua, 1 );

			lua_rawgeti( lua, 2, 1 );
			DWORD x = (DWORD)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			DWORD y = (DWORD)lua_tointeger( lua, -1 );

			DWORD type = (DWORD)lua_tointeger( lua, 3 );

			d2ClickMap( mouseFlag, x, y, type );
		}

		return result;
	}

	LDEC( leftClickItem_I )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 6 )
		{
			d2UnitAny_t* player = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			d2Inventory_t* inventory = (d2Inventory_t*)lua_touserdata( lua, 2 );

			lua_rawgeti( lua, 3, 1 );
			DWORD x = (DWORD)lua_tonumber( lua, -1 );
			lua_rawgeti( lua, 3, 2 );
			DWORD y = (DWORD)lua_tonumber( lua, -1 );

			DWORD clickType = (DWORD)lua_tonumber( lua, 4 );
			d2InventoryLayout_t* layout = (d2InventoryLayout_t*)lua_touserdata( lua, 5 );
			DWORD location = (DWORD)lua_tonumber( lua, 6 );

			d2LeftClickItem_I( player, inventory, x, y, clickType, layout, location );
		}

		return result;
	}

	LDEC( getMouseOffset )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs < 1 || !lua_istable( lua, 1 ) )
		{
			result = 1;
			lua_newtable( lua );
		}

		DWORD x = d2GetMouseXOffset();
		DWORD y = d2GetMouseYOffset();

		lua_pushnumber( lua, x );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, y );
		lua_rawseti( lua, -2, 2 );

		return result;
	}

	LDEC( printGameString )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			const char* str = lua_tostring( lua, 1 );
			int color = (int)lua_tointeger( lua, 2 );

			wchar_t message[1024] = {};
			MultiByteToWideChar( CP_UTF8, WC_COMPOSITECHECK, str, strlen( str ), message, 1024 );

			d2PrintGameString( message, color );
		}

		return result;
	}

	LDEC( printPartyString )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			const char* str = lua_tostring( lua, 1 );
			int color = (int)lua_tointeger( lua, 2 );

			wchar_t message[1024] = {};
			MultiByteToWideChar( CP_UTF8, WC_COMPOSITECHECK, str, strlen( str ), message, 1024 );

			d2PrintPartyString( message, color );
		}

		return result;
	}

	LDEC( leaveParty )
	{
		d2LeaveParty();
		return 0;
	}

	LDEC( acceptTrade )
	{
		d2AcceptTrade();
		return 0;
	}
	LDEC( cancelTrade )
	{
		d2CancelTrade();
		return 0;
	}
	LDEC( tradeOK )
	{
		d2TradeOK();
		return 0;
	}

	LDEC( getDifficulty )
	{
		BYTE difficulty = d2GetDifficulty();
		lua_pushnumber( lua, difficulty );
		return 1;
	}

	LDEC( exitGame )
	{
		d2ExitGame();
		return 0;
	}

	LDEC( getUIVariable_I )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD variableNumber = (DWORD)lua_tointeger( lua, 1 );

			DWORD retval = d2GetUIVariable_I( variableNumber );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( drawRectFrame )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD rect = (DWORD)lua_tointeger( lua, 1 );

			d2DrawRectFrame( rect );
		}

		return result;
	}

	LDEC( performGoldDialogAction )
	{
		d2PerformGoldDialogAction();
		return 0;
	}

	LDEC( getPlayerUnit )
	{
		d2UnitAny_t* player = d2GetPlayerUnit();
		lua_pushlightuserdata( lua, player );
		return 1;
	}

	LDEC( clearScreen )
	{
		d2ClearScreen();
		return 0;
	}

	LDEC( closeNPCTalk )
	{
		DWORD retval = d2CloseNPCTalk( NULL );
		lua_pushnumber( lua, retval );
		return 1;
	}

	LDEC( testPvpFlag )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			DWORD id1 = (DWORD)lua_tointeger( lua, 1 );
			DWORD id2 = (DWORD)lua_tointeger( lua, 2 );
			DWORD flag = (DWORD)lua_tointeger( lua, 3 );

			DWORD retval = d2TestPvpFlag( id1, id2, flag );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( initLevel )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2Level_t* level = (d2Level_t*)lua_touserdata( lua, 1 );

			d2InitLevel( level );
		}

		return result;
	}
	LDEC( unloadAct )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2Act_t* act = (d2Act_t*)lua_touserdata( lua, 1 );

			unsigned retval = d2UnloadAct( act );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( loadAct )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			DWORD actNumber = (DWORD)lua_tointeger( lua, 1 );
			DWORD mapId = (DWORD)lua_tointeger( lua, 2 );
			DWORD townLevelId = (DWORD)lua_tointeger( lua, 3 );

			d2Act_t* retval = d2LoadAct( actNumber, mapId, 0, 0, 0, 0, townLevelId, 0, 0 );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getLevelText )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD levelNumber = (DWORD)lua_tointeger( lua, 1 );

			d2LevelText_t* retval = d2GetLevelText( levelNumber );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getObjectText )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD objectNumber = (DWORD)lua_tointeger( lua, 1 );

			d2ObjectText_t* retval = d2GetObjectText( objectNumber );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getItemText )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD itemNumber = (DWORD)lua_tointeger( lua, 1 );

			d2ItemText_t* retval = d2GetItemText( itemNumber );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getLayer )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD levelNumber = (DWORD)lua_tointeger( lua, 1 );

			d2AutomapLayer2_t* retval = d2GetLayer( levelNumber );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getLevel )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
			d2ActMisc_t* misc = (d2ActMisc_t*)lua_touserdata( lua, 1 );
			DWORD levelNumber = (DWORD)lua_tointeger( lua, 2 );

			d2Level_t* retval = d2GetLevel( misc, levelNumber );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getStatList )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );

			const int MAX_ENTRIES = 32;
			d2StatList_t* retval = d2GetStatList( unit, 0, MAX_ENTRIES );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( copyStatList )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}

	LDEC( getUnitStat )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			DWORD stat = (DWORD)lua_tointeger( lua, 2 );
			DWORD stat2 = (DWORD)lua_tointeger( lua, 3 );

			DWORD retval = d2GetUnitStat( unit, stat, stat2 );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getUnitState )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			DWORD stateNumber = (DWORD)lua_tointeger( lua, 2 );

			int retval = d2GetUnitState( unit, stateNumber );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( checkUnitCollision )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			d2UnitAny_t* a = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			d2UnitAny_t* b = (d2UnitAny_t*)lua_touserdata( lua, 2 );
			DWORD bitMask = (DWORD)lua_tointeger( lua, 3 );

			DWORD retval = d2CheckUnitCollision( a, b, bitMask );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getRoomFromUnit )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );

			d2Room1_t* retval = d2GetRoomFromUnit( unit );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getTargetUnitType )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
			d2Path_t* path = (d2Path_t*)lua_touserdata( lua, 1 );

			d2Path_t* retval = d2GetTargetUnitType( path );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getSkillLevel )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			d2Skill_t* skill = (d2Skill_t*)lua_touserdata( lua, 2 );
			BOOL total = (BOOL)lua_toboolean( lua, 3 );

			INT retval = d2GetSkillLevel( unit, skill, total );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getItemLevelRequirement )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
			d2UnitAny_t* item = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			d2UnitAny_t* player = (d2UnitAny_t*)lua_touserdata( lua, 2 );

			DWORD retval = d2GetItemLevelRequirement( item, player );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getItemPrice )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			d2UnitAny_t* item = (d2UnitAny_t*)lua_touserdata( lua, 2 );

			DWORD retval = d2GetItemPrice( unit, item, 0, 0, 0, 0 );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getRepairCost )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 4 )
		{
			d2UnitAny_t* unit = (d2UnitAny_t*)lua_touserdata( lua, 1 );
			DWORD npcId = (DWORD)lua_tointeger( lua, 2 );
			DWORD difficulty = (DWORD)lua_tointeger( lua, 3 );
			DWORD itemPriceList = (DWORD)lua_tointeger( lua, 4 );

			DWORD retval = d2GetRepairCost( 0, unit, npcId, difficulty, itemPriceList, 0 );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getItemMagicalMods )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD prefixNumber = (DWORD)lua_tointeger( lua, 1 );

			char* retval = d2GetItemMagicalMods( prefixNumber );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getItemFromInventory )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2Inventory_t* inventory = (d2Inventory_t*)lua_touserdata( lua, 1 );

			d2UnitAny_t* retval = d2GetItemFromInventory( inventory );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getNextItemFromInventory )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2UnitAny_t* item = (d2UnitAny_t*)lua_touserdata( lua, 1 );

			d2UnitAny_t* retval = d2GetNextItemFromInventory( item );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( generateOverheadMessage )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			const char* message = lua_tostring( lua, 1 );
			DWORD trigger = (DWORD)lua_tointeger( lua, 2 );

			d2OverheadMessage_t* retval = d2GenerateOverheadMessage( 0,(CHAR*)message, trigger );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( fixOverheadMessage )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2OverheadMessage_t* message = (d2OverheadMessage_t*)lua_touserdata( lua, 1 );

			d2FixOverheadMessage( message, 0 );
		}

		return result;
	}

	LDEC( addRoomData )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 4 )
		{
			d2Act_t* act = (d2Act_t*)lua_touserdata( lua, 1 );
			int levelId = (int)lua_tointeger( lua, 2 );

			lua_rawgeti( lua, 3, 1 );
			int x = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 3, 2 );
			int y = (int)lua_tointeger( lua, -1 );

			d2Room1_t* room = (d2Room1_t*)lua_touserdata( lua, 4 );

			d2AddRoomData( act, levelId, x, y, room );
		}

		return result;
	}

	LDEC( removeRoomData )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 4 )
		{
			d2Act_t* act = (d2Act_t*)lua_touserdata( lua, 1 );
			int levelId = (int)lua_tointeger( lua, 2 );

			lua_rawgeti( lua, 3, 1 );
			int x = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 3, 2 );
			int  y = (int)lua_tointeger( lua, -1 );

			d2Room1_t* room = (d2Room1_t*)lua_touserdata( lua, 4 );

			d2RemoveRoomData( act, levelId, x, y, room );
		}

		return result;
	}

	LDEC( getQuestFlag )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			void* questInfo = lua_touserdata( lua, 1 );
			DWORD act = (DWORD)lua_tointeger( lua, 2 );
			DWORD quest = (DWORD)lua_tointeger( lua, 3 );

			int retval = d2GetQuestFlag( questInfo, act, quest );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( mapToAbsScreen )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs >= 1 )
		{
			lua_rawgeti( lua, 1, 1 );
			long x = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 1, 2 );
			long y = (int)lua_tointeger( lua, -1 );

			d2MapToAbsScreen( &x, &y );

			if( nargs == 1 || !lua_istable( lua, 2 ) )
			{
				result = 1;
				lua_newtable( lua );
			}

			lua_pushnumber( lua, x );
			lua_rawseti( lua, -2, 1 );
			lua_pushnumber( lua, y );
			lua_rawseti( lua, -2, 2 );
		}

		return result;
	}

	LDEC( absScreenToMap )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs >= 1 )
		{
			lua_rawgeti( lua, 1, 1 );
			long x = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 1, 2 );
			long y = (int)lua_tointeger( lua, -1 );

			d2AbsScreenToMap( &x, &y );

			if( nargs == 1 || !lua_istable( lua, 2 ) )
			{
				result = 1;
				lua_newtable( lua );
			}

			lua_pushnumber( lua, x );
			lua_rawseti( lua, -2, 1 );
			lua_pushnumber( lua, y );
			lua_rawseti( lua, -2, 2 );
		}

		return result;
	}

	LDEC( checkWaypoint )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			DWORD waypointTable = (DWORD)lua_tointeger( lua, 1 );
			DWORD levelId = (DWORD)lua_tointeger( lua, 2 );

			DWORD retval = d2CheckWaypoint( waypointTable, levelId );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( isTownByLevelNumber )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD levelNumber = (DWORD)lua_tointeger( lua, 1 );

			BOOL retval = d2IsTownByLevelNumber( levelNumber );
			lua_pushboolean( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getLevelNumberFromRoom )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2Room1_t* room = (d2Room1_t*)lua_touserdata( lua, 1 );

			BOOL retval = d2GetLevelNumberFromRoom( room );
			lua_pushboolean( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( findRoom1 )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			d2Act_t* act = (d2Act_t*)lua_touserdata( lua, 1 );

			lua_rawgeti( lua, 2, 1 );
			int x = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			int y = (int)lua_tointeger( lua, -1 );

			d2Room1_t* retval = d2FindRoom1( act, x, y );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( getItemPalette )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 4 )
		{
		}

		return result;
	}

	LDEC( sendPacket )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
		}

		return result;
	}

	LDEC( receivePacket )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
		}

		return result;
	}

	LDEC( receivePacket_I )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
		}

		return result;
	}

	LDEC( drawRectangle )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 4 )
		{
			lua_rawgeti( lua, 1, 1 );
			int x1 = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 1, 2 );
			int y1 = (int)lua_tointeger( lua, -1 );

			lua_rawgeti( lua, 2, 1 );
			int x2 = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			int y2 = (int)lua_tointeger( lua, -1 );

			DWORD color = (DWORD)lua_tointeger( lua, 3 );
			DWORD transparency = (DWORD)lua_tointeger( lua, 4 );

			d2DrawRectangle( x1, y1, x2, y2, color, transparency );
		}

		return result;
	}

	LDEC( drawLine )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			lua_rawgeti( lua, 1, 1 );
			int x1 = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 1, 2 );
			int y1 = (int)lua_tointeger( lua, -1 );

			lua_rawgeti( lua, 2, 1 );
			int x2 = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			int y2 = (int)lua_tointeger( lua, -1 );

			DWORD color = (DWORD)lua_tointeger( lua, 3 );
			
			d2DrawLine( x1, y1, x2, y2, color, 0 );
		}

		return result;
	}

	LDEC( drawAutomapCell2 )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}

	LDEC( getHwnd )
	{
		HWND hwnd = d2GetHwnd();
		lua_pushlightuserdata( lua, hwnd );
		return 1;
	}

	LDEC( getScreenSize )
	{
		DWORD screenSize = d2GetScreenSize();
		lua_pushnumber( lua, screenSize );
		return 1;
	}

	LDEC( doChat )
	{
		d2DoChat();
		return 0;
	}

	LDEC( printChannelText )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			const char* text = lua_tostring( lua, 1 );
			DWORD color = (DWORD)lua_tointeger( lua, 2 );

			d2PrintChannelText( 0, text, color );
		}

		return result;
	}

	LDEC( initCellFile )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}

	LDEC( deleteCellFile )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}
	LDEC( getLocaleText )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}

	LDEC( setControlText )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
			d2Control_t* box = (d2Control_t*)lua_touserdata( lua, 1 );
			const char* buf = lua_tostring( lua, 2 );

			wchar_t text[1024] = {};
			MultiByteToWideChar( CP_UTF8, WC_COMPOSITECHECK, buf, strlen( buf ), text, 1024 );

			void* retval = d2SetControlText( box, text );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( drawSprites )
	{
		d2DrawSprites();
		return 0;
	}

	LDEC( loadCellFile )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 2 )
		{
			const char* file = lua_tostring( lua, 1 );
			int type = (int)lua_tointeger( lua, 2 );

			d2CellFile_t* retval = d2LoadCellFile( file, type );
			if( retval )
			{
				lua_pushlightuserdata( lua, retval );
				result = 1;
			}
		}

		return result;
	}

	LDEC( takeScreenshot )
	{
		d2TakeScreenshot();
		return 0;
	}

	LDEC( drawText )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 3 )
		{
			const char* buf = lua_tostring( lua, 1 );

			lua_rawgeti( lua, 2, 1 );
			int x = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			int y = (int)lua_tointeger( lua, -1 );

			DWORD color = (DWORD)lua_tointeger( lua, 3 );
			
			wchar_t str[1024] = {};
			MultiByteToWideChar( CP_UTF8, WC_COMPOSITECHECK, buf, strlen( buf ), str, 1024 );

			d2DrawText( str, x, y, color, 0 );
		}

		return result;
	}

	LDEC( getTextSize )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}

	LDEC( setTextSize )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			DWORD size = (DWORD)lua_tointeger( lua, 1 );

			DWORD retval = d2SetTextSize( size );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( getTextWidthFileNumber )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}

	LDEC( destroyEditBox )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2Control_t* control = (d2Control_t*)lua_touserdata( lua, 1 );

			DWORD retval = d2DestroyEditBox( control );
			lua_pushnumber( lua, retval );
			result = 1;
		}

		return result;
	}

	LDEC( destroyControl )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 1 )
		{
			d2Control_t* control = (d2Control_t*)lua_touserdata( lua, 1 );

			d2DestroyControl( control );
		}

		return result;
	}

	LDEC( setEditBoxCallback )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}
	LDEC( setEditBoxProcedure )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}
	LDEC( selectEditBoxText )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}

	LDEC( initMPQ )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 4 )
		{
		}

		return result;
	}

	LDEC( rand )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 )
		{
		}

		return result;
	}

	LDEC( exit0 )
	{
		d2Exit0();
		return 0;
	}

	// variables
	LDEC( getCursorHoverPosition )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 || !lua_istable( lua, 1 ) )
		{
			result = 1;
			lua_newtable( lua );
		}

		lua_pushnumber( lua, *d2CursorHoverX );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, *d2CursorHoverY );
		lua_rawseti( lua, -2, 2 );

		return result;
	}

	LDEC( getMousePosition )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 || !lua_istable( lua, 1 ) )
		{
			result = 1;
			lua_newtable( lua );
		}

		lua_pushnumber( lua, *d2MouseX );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, *d2MouseY );
		lua_rawseti( lua, -2, 2 );

		return result;
	}

	LDEC( getMouseOffset )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 || !lua_istable( lua, 1 ) )
		{
			result = 1;
			lua_newtable( lua );
		}

		lua_pushnumber( lua, *d2MouseOffsetX );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, *d2MouseOffsetY );
		lua_rawseti( lua, -2, 2 );
		lua_pushnumber( lua, *d2MouseOffsetZ );
		lua_rawseti( lua, -2, 3 );

		return result;
	}

	LDEC( getAutomapOn )
	{
		lua_pushboolean( lua, *d2AutomapOn );
		return 1;
	}

	LDEC( getAutomapMode )
	{
		lua_pushnumber( lua, *d2AutomapMode );
		return 1;
	}

	LDEC( getOffset )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 || !lua_istable( lua, 1 ) )
		{
			result = 1;
			lua_newtable( lua );
		}

		lua_pushnumber( lua, d2Offset->x );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, d2Offset->y );
		lua_rawseti( lua, -2, 2 );

		return result;
	}

	LDEC( getAutomapLayer )
	{
		lua_pushlightuserdata( lua, *d2AutomapLayer );
		return 1;
	}

	LDEC( getMercenaryReviveCost )
	{
		lua_pushnumber( lua, *d2MercenaryReviveCost );
		return 1;
	}

	LDEC( getServerSideUnitHashTables )
	{
		lua_pushlightuserdata( lua, d2ServerSideUnitHashTables );
		return 1;
	}

	LDEC( getClientSideUnitHashTables )
	{
		lua_pushlightuserdata( lua, d2ClientSideUnitHashTables );
		return 1;
	}

	LDEC( getViewport )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 || !lua_istable( lua, 1 ) )
		{
			result = 1;
			lua_newtable( lua );
		}

		lua_pushnumber( lua, *d2ViewportX );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, *d2ViewportY );
		lua_rawseti( lua, -2, 2 );

		return result;
	}

	LDEC( getGoldDialogAction )
	{
		lua_pushnumber( lua, *d2GoldDialogAction );
		return 1;
	}

	LDEC( getGoldDialogAmount )
	{
		lua_pushnumber( lua, *d2GoldDialogAmount );
		return 1;
	}

	LDEC( getNPCMenu )
	{
		lua_pushlightuserdata( lua, *d2NPCMenu );
		return 1;
	}

	LDEC( getNPCMenuAmount )
	{
		lua_pushnumber( lua, *d2NPCMenuAmount );
		return 1;
	}

	LDEC( getTradeLayout )
	{
		lua_pushlightuserdata( lua, *d2TradeLayout );
		return 1;
	}

	LDEC( getStashLayout )
	{
		lua_pushlightuserdata( lua, *d2StashLayout );
		return 1;
	}

	LDEC( getStoreLayout )
	{
		lua_pushlightuserdata( lua, *d2StoreLayout );
		return 1;
	}

	LDEC( getCubeLayout )
	{
		lua_pushlightuserdata( lua, *d2CubeLayout );
		return 1;
	}

	LDEC( getInventoryLayout )
	{
		lua_pushlightuserdata( lua, *d2InventoryLayout );
		return 1;
	}

	LDEC( getMercenaryLayout )
	{
		lua_pushlightuserdata( lua, *d2MercenaryLayout );
		return 1;
	}

	LDEC( getRegularCursorType )
	{
		lua_pushnumber( lua, *d2RegularCursorType );
		return 1;
	}

	LDEC( getShopCursorType )
	{
		lua_pushnumber( lua, *d2ShopCursorType );
		return 1;
	}

	LDEC( getPing )
	{
		lua_pushnumber( lua, *d2Ping );
		return 1;
	}

	LDEC( getSkip )
	{
		lua_pushnumber( lua, *d2Skip );
	}

	LDEC( getFPS )
	{
		lua_pushnumber( lua, *d2FPS );
		return 1;
	}

	LDEC( getDivisor )
	{
		lua_pushnumber( lua, *d2Divisor );
		return 1;
	}

	LDEC( getOverheadTrigger )
	{
		lua_pushnumber( lua, *d2OverheadTrigger );
		return 1;
	}

	LDEC( getRecentInteractId )
	{
		lua_pushnumber( lua, *d2RecentInteractId );
		return 1;
	}

	LDEC( getItemPriceList )
	{
		lua_pushnumber( lua, *d2ItemPriceList );
		return 1;
	}

	LDEC( getTransactionDialog )
	{
		lua_pushlightuserdata( lua, *d2TransactionDialog );
		return 1;
	}

	LDEC( getTransactionDialogs )
	{
		lua_pushnumber( lua, *d2TransactionDialogs );
		return 1;
	}

	LDEC( getTransactionDialogs_2 )
	{
		lua_pushnumber( lua, *d2TransactionDialogs_2 );
		return 1;
	}

	LDEC( getTransactionDialogsInfo )
	{
		lua_pushlightuserdata( lua, *d2TransactionDialogsInfo );
		return 1;
	}

	LDEC( getGameInfo )
	{
		lua_pushlightuserdata( lua, *d2GameInfo );
		return 1;
	}

	LDEC( getWaypointTable )
	{
		lua_pushnumber( lua, *d2WaypointTable );
		return 1;
	}

	LDEC( getPlayerUnit )
	{
		lua_pushlightuserdata( lua, *d2PlayerUnit );
		return 1;
	}

	LDEC( getSelectedInventoryItem )
	{
		lua_pushlightuserdata( lua, *d2SelectedInventoryItem );
		return 1;
	}

	LDEC( getPlayerUnitList )
	{
		lua_pushlightuserdata( lua, *d2PlayerUnitList );
		return 1;
	}

	LDEC( getWeaponSwitch )
	{
		lua_pushboolean( lua, *d2WeaponSwitch );
		return 1;
	}

	LDEC( getTradeAccepted )
	{
		lua_pushboolean( lua, *d2TradeAccepted );
		return 1;
	}

	LDEC( getTradeBlock )
	{
		lua_pushboolean( lua, *d2TradeBlock );
		return 1;
	}

	LDEC( getRecentTradeId )
	{
		lua_pushnumber( lua, *d2RecentTradeId );
		return 1;
	}

	LDEC( getExpansionCharacterFlag )
	{
		lua_pushboolean( lua, *d2ExpansionCharacterFlag );
		return 1;
	}

	LDEC( getMapId )
	{
		lua_pushnumber( lua, *d2MapId );
		return 1;
	}

	LDEC( getAlwaysRun )
	{
		lua_pushboolean( lua, *d2AlwaysRun );
		return 1;
	}

	LDEC( getNoPickup )
	{
		lua_pushboolean( lua, *d2NoPickup );
		return 1;
	}

	LDEC( getChatMessage )
	{
		char buffer[1024] = {};
		WideCharToMultiByte( CP_UTF8, WC_COMPOSITECHECK, *d2ChatMessage, -1, buffer, 1024, NULL, NULL );

		lua_pushstring( lua, buffer );
		return 1;
	}

	LDEC( getOrificeId )
	{
		lua_pushnumber( lua, *d2OrificeId );
		return 1;
	}

	LDEC( getCursorItemMode )
	{
		lua_pushnumber( lua, *d2CursorItemMode );
		return 1;
	}

	LDEC( getSGPTDataTable )
	{
		lua_pushnumber( lua, *d2SGPTDataTable );
		return 1;
	}

	LDEC( getChatBoxMessage )
	{
		lua_pushstring( lua, *d2ChatBoxMessage );
		return 1;
	}

	LDEC( getGameListControl )
	{
		lua_pushlightuserdata( lua, *d2GameListControl );
		return 1;
	}

	LDEC( getBattleNetData )
	{
		lua_pushlightuserdata( lua, *d2BattleNetData );
		return 1;
	}

	LDEC( getFirstControl )
	{
		lua_pushlightuserdata( lua, *d2FirstControl );
		return 1;
	}

	LDEC( getFocusedControl )
	{
		lua_pushlightuserdata( lua, *d2FocusedControl );
		return 1;
	}

	LDEC( getChatInputBox )
	{
		return 0;
	}

	LDEC( getClassicKey )
	{
		lua_pushstring( lua, *d2ClassicKey );
		return 1;
	}

	LDEC( getExpansionKey )
	{
		lua_pushstring( lua, *d2ExpansionKey );
		return 1;
	}

	LDEC( getKeyOwner )
	{
		lua_pushstring( lua, *d2KeyOwner );
		return 1;
	}

	LDEC( getWindowHandlers )
	{
		return 0;
	}
}