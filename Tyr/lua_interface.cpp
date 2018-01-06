#include "lua_interface.h"

namespace lua_interface
{
	static const char* NIL_STRING = "nil";

	void bind( lua_State* lua )
	{
		lua_register( lua, "MessageBox", lua_MessageBox );

		LREG( getQuestInfo );
		LREG( submitItem );
		LREG( transmute );

		LREG( findClientSideUnit );
		LREG( findServerSideUnit );
		LREG( getCurrentInteractingNPC );
		LREG( getSelectedUnit );
		LREG( getCursorItem );
		LREG( getItemName );
		LREG( loadItemDescription );
		LREG( getMonsterOwner );
		LREG( getUnitHPPercent );
		LREG( initInventory );
		LREG( setUIVariable );
		LREG( getUnitPosition );

		LREG( shopAction );

		LREG( closeNPCInteract );
		LREG( closeInteract );

		LREG( getAutomapSize );
		LREG( newAutomapCell );
		LREG( addAutomapCell );
		LREG( revealAutomapRoom );
		LREG( initAutomapLayer_I );

		LREG( clickMap );
		LREG( leftClickItem_I );

		LREG( getMouseOffset );

		LREG( printGameString );
		LREG( printPartyString );

		LREG( leaveParty );

		LREG( acceptTrade );
		LREG( cancelTrade );
		LREG( tradeOK );

		LREG( getDifficulty );
		LREG( exitGame );
		LREG( getUIVariable_I );
		LREG( drawRectFrame );
		LREG( performGoldDialogAction );
		LREG( getPlayerUnit );
		LREG( clearScreen );
		LREG( closeNPCTalk );
		LREG( testPvpFlag );

		LREG( initLevel );
		LREG( unloadAct );
		LREG( loadAct );

		LREG( getLevelText );
		LREG( getObjectText );
		LREG( getItemText );

		LREG( getLayer );
		LREG( getLevel );

		LREG( getStatList );
		LREG( copyStatList );
		LREG( getUnitStat );
		LREG( getUnitState );

		LREG( checkUnitCollision );
		LREG( getRoomFromUnit );
		LREG( getTargetUnitType );

		LREG( getSkillLevel );

		LREG( getItemLevelRequirement );

		LREG( getItemPrice );
		LREG( getRepairCost );
		LREG( getItemMagicalMods );
		LREG( getItemFromInventory );
		LREG( getNextItemFromInventory );

		LREG( generateOverheadMessage );
		LREG( fixOverheadMessage );

		LREG( addRoomData );
		LREG( removeRoomData );

		LREG( getQuestFlag );

		LREG( mapToAbsScreen );
		LREG( absScreenToMap );

		LREG( checkWaypoint );

		LREG( isTownByLevelNumber );
		LREG( getLevelNumberFromRoom );
		LREG( findRoom1 );
		LREG( getItemPalette );

		LREG( sendPacket );
		LREG( receivePacket );
		LREG( receivePacket_I );

		LREG( drawRectangle );
		LREG( drawLine );
		LREG( drawAutomapCell2 );
		LREG( getHwnd );
		LREG( getScreenSize );

		LREG( doChat );
		LREG( printChannelText );

		LREG( initCellFile );
		LREG( deleteCellFile );
		LREG( getLocaleText );

		LREG( setControlText );
		LREG( drawSprites );
		LREG( loadCellFile );

		LREG( takeScreenshot );
		LREG( drawText );
		LREG( getTextSize );
		LREG( setTextSize );
		LREG( getTextWidthFileNumber );
		LREG( destroyEditBox );
		LREG( destroyControl );

		LREG( setEditBoxCallback );
		LREG( setEditBoxProcedure );
		LREG( selectEditBoxText );
		LREG( initMPQ );

		LREG( rand );
		LREG( exit0 );

		// variables
		LREG( getScreenSize );
		LREG( getCursorHoverPosition );
		LREG( getMousePosition );
		LREG( getMouseOffset );

		LREG( automapOn );
		LREG( automapMode );
		LREG( getOffset );
		LREG( automapLayer );

		LREG( mercenaryReviveCost );

		LREG( serverSideUnitHashTables );
		LREG( clientSideUnitHashTables );

		LREG( getViewport );

		LREG( goldDialogAction );
		LREG( goldDialogAmount );

		LREG( NPCMenu );
		LREG( NPCMenuAmount );

		LREG( tradeLayout );
		LREG( stashLayout );
		LREG( storeLayout );
		LREG( cubeLayout );
		LREG( inventoryLayout );
		LREG( mercenaryLayout );

		LREG( regularCursorType );
		LREG( shopCursorType );

		LREG( ping );
		LREG( skip );
		LREG( FPS );
		LREG( divisor );

		LREG( overheadTrigger );
		LREG( recentInteractId );
		LREG( itemPriceList );

		LREG( transactionDialog );
		LREG( transactionDialogs );
		LREG( transactionDialogs_2 );
		LREG( transactionDialogsInfo );

		LREG( gameInfo );
		LREG( waypointTable );

		LREG( playerUnit );
		LREG( selectedInventoryItem );
		LREG( playerUnitList );

		LREG( weaponSwitch );

		LREG( tradeAccepted );
		LREG( tradeBlock );
		LREG( recentTradeId );

		LREG( expansionCharacterFlag );
		LREG( mapId );

		LREG( alwaysRun );
		LREG( noPickup );

		LREG( chatMessage );
		LREG( orificeId );
		LREG( cursorItemMode );

		LREG( SGPTDataTable );

		LREG( chatBoxMessage );
		LREG( gameListControl );

		LREG( battleNetData );

		LREG( firstControl );
		LREG( focusedControl );
		LREG( chatInputBox );

		LREG( classicKey );
		LREG( expansionKey );
		LREG( keyOwner );
		LREG( windowHandlers );
	}

	int lua_MessageBox( lua_State* lua )
	{
		if( lua_gettop( lua ) > 0 )
		{
			const char* str = lua_tostring( lua, 1 );

			MessageBoxA( NULL, str, "Tyr", MB_OK );
		}

		return 0;
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
					wcstombs( cbuffer, buffer, 1024 );
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
			if( str == NULL )
				str = NIL_STRING;

			int color = (int)lua_tointeger( lua, 2 );

			wchar_t message[1024] = {};
			mbstowcs( message, str, 1024 );

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
			if( str == NULL )
				str = NIL_STRING;

			int color = (int)lua_tointeger( lua, 2 );

			wchar_t message[1024] = {};
			mbstowcs( message, str, 1024 );

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
			if( message == NULL )
				message = NIL_STRING;

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
			int curArg = 1;

			long x = 0, y = 0;
			if( lua_istable( lua, curArg ) )
			{
				lua_rawgeti( lua, curArg, 1 );
				x = (long)lua_tointeger( lua, -1 );
				lua_rawgeti( lua, curArg, 2 );
				y = (long)lua_tointeger( lua, -1 );

				curArg++;
			}
			else if( lua_isnumber( lua, curArg ) && lua_isnumber( lua, curArg+1 ) )
			{
				x = (long)lua_tointeger( lua, curArg );
				y = (long)lua_tointeger( lua, curArg+1 );

				curArg += 2;
			}
			else
				return 0;

			d2MapToAbsScreen( &x, &y );
			x -= d2GetMouseXOffset();
			y -= d2GetMouseYOffset();

			int tableIndex = curArg;
			if( nargs < curArg || !lua_istable( lua, curArg ) )
			{
				result = 1;
				lua_newtable( lua );
				tableIndex = -2;
			}

			lua_pushnumber( lua, x );
			lua_rawseti( lua, tableIndex, 1 );
			lua_pushnumber( lua, y );
			lua_rawseti( lua, tableIndex, 2 );
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

			x -= d2GetMouseXOffset();
			y -= d2GetMouseYOffset();
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
		if( nargs >= 2 )
		{
			lua_assert( !lua_isnil( lua, 1 ) && !lua_isnil( lua, 2 ) );

			int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

			int curArg = 1;
			if( lua_istable( lua, curArg ) )
			{
				lua_rawgeti( lua, curArg, 1 );
				x1 = (int)lua_tointeger( lua, -1 );
				lua_rawgeti( lua, curArg, 2 );
				y1 = (int)lua_tointeger( lua, -1 );

				curArg++;
			}
			else if( lua_isnumber( lua, curArg ) && lua_isnumber( lua, curArg+1 ) )
			{
				x1 = (int)lua_tointeger( lua, curArg );
				y1 = (int)lua_tointeger( lua, curArg+1 );

				curArg += 2;
			}
			else
				return 0;

			if( lua_istable( lua, curArg ) )
			{
				lua_rawgeti( lua, curArg, 1 );
				x2 = (int)lua_tointeger( lua, -1 );
				lua_rawgeti( lua, curArg, 2 );
				y2 = (int)lua_tointeger( lua, -1 );

				curArg++;
			}
			else if( lua_isnumber( lua, curArg ) && lua_isnumber( lua, curArg+1 ) )
			{
				x2 = (int)lua_tonumber( lua, curArg );
				y2 = (int)lua_tointeger( lua, curArg+1 );

				curArg += 2;
			}

			DWORD color = 0xFF;
			if( nargs == curArg )
				color = (DWORD)lua_tointeger( lua, curArg );
			
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
			if( text == NULL )
				text = NIL_STRING;

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
			if( buf == NULL )
				buf = NIL_STRING;

			wchar_t text[1024] = {};
			mbstowcs( text, buf, 1024 );

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
		if( nargs >= 2 )
		{
			const char* buf = lua_tostring( lua, 1 );
			if( buf == NULL )
				buf = NIL_STRING;

			lua_rawgeti( lua, 2, 1 );
			int x = (int)lua_tointeger( lua, -1 );
			lua_rawgeti( lua, 2, 2 );
			int y = (int)lua_tointeger( lua, -1 );

			DWORD color = 0xFF;
			if( nargs == 3 )
				color = (DWORD)lua_tointeger( lua, 3 );
			
			wchar_t str[1024] = {};
			mbstowcs( str, buf, 1024 );

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
	LDEC( getScreenSize )
	{
		int result = 0;

		int nargs = lua_gettop( lua );
		if( nargs == 0 || !lua_istable( lua, 1 ) )
		{
			result = 1;
			lua_newtable( lua );
		}

		lua_pushnumber( lua, *d2ScreenSizeX );
		lua_rawseti( lua, -2, 1 );
		lua_pushnumber( lua, *d2ScreenSizeY );
		lua_rawseti( lua, -2, 2 );

		return result;
	}

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

	LDEC( getMouseXYZOffset )
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

	LDEC( automapOn )
	{
		lua_pushboolean( lua, *d2AutomapOn );
		return 1;
	}

	LDEC( automapMode )
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

	LDEC( automapLayer )
	{
		lua_pushlightuserdata( lua, *d2AutomapLayer );
		return 1;
	}

	LDEC( mercenaryReviveCost )
	{
		lua_pushnumber( lua, *d2MercenaryReviveCost );
		return 1;
	}

	LDEC( serverSideUnitHashTables )
	{
		lua_pushlightuserdata( lua, d2ServerSideUnitHashTables );
		return 1;
	}

	LDEC( clientSideUnitHashTables )
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

	LDEC( goldDialogAction )
	{
		lua_pushnumber( lua, *d2GoldDialogAction );
		return 1;
	}

	LDEC( goldDialogAmount )
	{
		lua_pushnumber( lua, *d2GoldDialogAmount );
		return 1;
	}

	LDEC( NPCMenu )
	{
		lua_pushlightuserdata( lua, *d2NPCMenu );
		return 1;
	}

	LDEC( NPCMenuAmount )
	{
		lua_pushnumber( lua, *d2NPCMenuAmount );
		return 1;
	}

	LDEC( tradeLayout )
	{
		lua_pushlightuserdata( lua, *d2TradeLayout );
		return 1;
	}

	LDEC( stashLayout )
	{
		lua_pushlightuserdata( lua, *d2StashLayout );
		return 1;
	}

	LDEC( storeLayout )
	{
		lua_pushlightuserdata( lua, *d2StoreLayout );
		return 1;
	}

	LDEC( cubeLayout )
	{
		lua_pushlightuserdata( lua, *d2CubeLayout );
		return 1;
	}

	LDEC( inventoryLayout )
	{
		lua_pushlightuserdata( lua, *d2InventoryLayout );
		return 1;
	}

	LDEC( mercenaryLayout )
	{
		lua_pushlightuserdata( lua, *d2MercenaryLayout );
		return 1;
	}

	LDEC( regularCursorType )
	{
		lua_pushnumber( lua, *d2RegularCursorType );
		return 1;
	}

	LDEC( shopCursorType )
	{
		lua_pushnumber( lua, *d2ShopCursorType );
		return 1;
	}

	LDEC( ping )
	{
		lua_pushnumber( lua, *d2Ping );
		return 1;
	}

	LDEC( skip )
	{
		lua_pushnumber( lua, *d2Skip );
		return 1;
	}

	LDEC( FPS )
	{
		lua_pushnumber( lua, *d2FPS );
		return 1;
	}

	LDEC( divisor )
	{
		lua_pushnumber( lua, *d2Divisor );
		return 1;
	}

	LDEC( overheadTrigger )
	{
		lua_pushnumber( lua, *d2OverheadTrigger );
		return 1;
	}

	LDEC( recentInteractId )
	{
		lua_pushnumber( lua, *d2RecentInteractId );
		return 1;
	}

	LDEC( itemPriceList )
	{
		lua_pushnumber( lua, *d2ItemPriceList );
		return 1;
	}

	LDEC( transactionDialog )
	{
		lua_pushlightuserdata( lua, *d2TransactionDialog );
		return 1;
	}

	LDEC( transactionDialogs )
	{
		lua_pushnumber( lua, *d2TransactionDialogs );
		return 1;
	}

	LDEC( transactionDialogs_2 )
	{
		lua_pushnumber( lua, *d2TransactionDialogs_2 );
		return 1;
	}

	LDEC( transactionDialogsInfo )
	{
		lua_pushlightuserdata( lua, *d2TransactionDialogsInfo );
		return 1;
	}

	LDEC( gameInfo )
	{
		lua_pushlightuserdata( lua, *d2GameInfo );
		return 1;
	}

	LDEC( waypointTable )
	{
		lua_pushnumber( lua, *d2WaypointTable );
		return 1;
	}

	LDEC( playerUnit )
	{
		lua_pushlightuserdata( lua, *d2PlayerUnit );
		return 1;
	}

	LDEC( selectedInventoryItem )
	{
		lua_pushlightuserdata( lua, *d2SelectedInventoryItem );
		return 1;
	}

	LDEC( playerUnitList )
	{
		lua_pushlightuserdata( lua, *d2PlayerUnitList );
		return 1;
	}

	LDEC( weaponSwitch )
	{
		lua_pushboolean( lua, *d2WeaponSwitch );
		return 1;
	}

	LDEC( tradeAccepted )
	{
		lua_pushboolean( lua, *d2TradeAccepted );
		return 1;
	}

	LDEC( tradeBlock )
	{
		lua_pushboolean( lua, *d2TradeBlock );
		return 1;
	}

	LDEC( recentTradeId )
	{
		lua_pushnumber( lua, *d2RecentTradeId );
		return 1;
	}

	LDEC( expansionCharacterFlag )
	{
		lua_pushboolean( lua, *d2ExpansionCharacterFlag );
		return 1;
	}

	LDEC( mapId )
	{
		lua_pushnumber( lua, *d2MapId );
		return 1;
	}

	LDEC( alwaysRun )
	{
		lua_pushboolean( lua, *d2AlwaysRun );
		return 1;
	}

	LDEC( noPickup )
	{
		lua_pushboolean( lua, *d2NoPickup );
		return 1;
	}

	LDEC( chatMessage )
	{
		int result = 0;

		if( d2ChatMessage )
		{
			char buffer[1024] = {};
			wcstombs( buffer, d2ChatMessage, 1024 );

			lua_pushstring( lua, buffer );
			result = 1;
		}

		return result;
	}

	LDEC( orificeId )
	{
		lua_pushnumber( lua, *d2OrificeId );
		return 1;
	}

	LDEC( cursorItemMode )
	{
		lua_pushnumber( lua, *d2CursorItemMode );
		return 1;
	}

	LDEC( SGPTDataTable )
	{
		lua_pushnumber( lua, *d2SGPTDataTable );
		return 1;
	}

	LDEC( chatBoxMessage )
	{
		lua_pushstring( lua, *d2ChatBoxMessage );
		return 1;
	}

	LDEC( gameListControl )
	{
		lua_pushlightuserdata( lua, *d2GameListControl );
		return 1;
	}

	LDEC( battleNetData )
	{
		lua_pushlightuserdata( lua, *d2BattleNetData );
		return 1;
	}

	LDEC( firstControl )
	{
		lua_pushlightuserdata( lua, *d2FirstControl );
		return 1;
	}

	LDEC( focusedControl )
	{
		lua_pushlightuserdata( lua, *d2FocusedControl );
		return 1;
	}

	LDEC( chatInputBox )
	{
		return 0;
	}

	LDEC( classicKey )
	{
		lua_pushstring( lua, *d2ClassicKey );
		return 1;
	}

	LDEC( expansionKey )
	{
		lua_pushstring( lua, *d2ExpansionKey );
		return 1;
	}

	LDEC( keyOwner )
	{
		lua_pushstring( lua, *d2KeyOwner );
		return 1;
	}

	LDEC( windowHandlers )
	{
		return 0;
	}
}