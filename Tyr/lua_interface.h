#pragma once

#include "lua.hpp"
#include "d2_interface.h"

#define LDEC( name ) int name ( lua_State* lua )
#define LREG( name ) lua_register( lua, #name, name )

namespace lua_interface
{
	void bind( lua_State* lua );

	int lua_MessageBox( lua_State* lua );

	LDEC( getQuestInfo );
	LDEC( submitItem );
	LDEC( transmute );

	LDEC( findClientSideUnit );
	LDEC( findServerSideUnit );
	LDEC( getCurrentInteractingNPC );
	LDEC( getSelectedUnit );
	LDEC( getCursorItem );
	LDEC( getItemName );
	LDEC( loadItemDescription );
	LDEC( getMonsterOwner );
	LDEC( getUnitHPPercent );
	LDEC( initInventory );
	LDEC( setUIVariable );
	LDEC( getUnitPosition );

	LDEC( shopAction );

	LDEC( closeNPCInteract );
	LDEC( closeInteract );

	LDEC( getAutomapSize );
	LDEC( newAutomapCell );
	LDEC( addAutomapCell );
	LDEC( revealAutomapRoom );
	LDEC( initAutomapLayer_I );

	LDEC( clickMap );
	LDEC( leftClickItem_I );

	LDEC( getMouseOffset );

	LDEC( printGameString );
	LDEC( printPartyString );

	LDEC( leaveParty );

	LDEC( acceptTrade );
	LDEC( cancelTrade );
	LDEC( tradeOK );

	LDEC( getDifficulty );
	LDEC( exitGame );
	LDEC( getUIVariable_I );
	LDEC( drawRectFrame );
	LDEC( performGoldDialogAction );
	LDEC( getPlayerUnit );
	LDEC( clearScreen );
	LDEC( closeNPCTalk );
	LDEC( testPvpFlag );

	LDEC( initLevel );
	LDEC( unloadAct );
	LDEC( loadAct );

	LDEC( getLevelText );
	LDEC( getObjectText );
	LDEC( getItemText );

	LDEC( getLayer );
	LDEC( getLevel );

	LDEC( getStatList );
	LDEC( copyStatList );
	LDEC( getUnitStat );
	LDEC( getUnitState );

	LDEC( checkUnitCollision );
	LDEC( getRoomFromUnit );
	LDEC( getTargetUnitType );

	LDEC( getSkillLevel );

	LDEC( getItemLevelRequirement );

	LDEC( getItemPrice );
	LDEC( getRepairCost );
	LDEC( getItemMagicalMods );
	LDEC( getItemFromInventory );
	LDEC( getNextItemFromInventory );

	LDEC( generateOverheadMessage );
	LDEC( fixOverheadMessage );

	LDEC( addRoomData );
	LDEC( removeRoomData );

	LDEC( getQuestFlag );

	LDEC( mapToAbsScreen );
	LDEC( absScreenToMap );

	LDEC( checkWaypoint );

	LDEC( isTownByLevelNumber );
	LDEC( getLevelNumberFromRoom );
	LDEC( findRoom1 );
	LDEC( getItemPalette );

	LDEC( sendPacket );
	LDEC( receivePacket );
	LDEC( receivePacket_I );

	LDEC( drawRectangle );
	LDEC( drawLine );
	LDEC( drawAutomapCell2 );
	LDEC( getHwnd );

	LDEC( doChat );
	LDEC( printChannelText );

	LDEC( initCellFile );
	LDEC( deleteCellFile );
	LDEC( getLocaleText );

	LDEC( setControlText );
	LDEC( drawSprites );
	LDEC( loadCellFile );

	LDEC( takeScreenshot );
	LDEC( drawText );
	LDEC( getTextSize );
	LDEC( setTextSize );
	LDEC( getTextWidthFileNumber );
	LDEC( destroyEditBox );
	LDEC( destroyControl );

	LDEC( setEditBoxCallback );
	LDEC( setEditBoxProcedure );
	LDEC( selectEditBoxText );
	LDEC( initMPQ );

	LDEC( rand );
	LDEC( exit0 );

	// variables
	LDEC( getScreenSize );
	LDEC( getCursorHoverPosition );
	LDEC( getMousePosition );
	LDEC( getMouseOffset );

	LDEC( automapOn );
	LDEC( automapMode );
	LDEC( getOffset );
	LDEC( automapLayer );

	LDEC( mercenaryReviveCost );

	LDEC( serverSideUnitHashTables );
	LDEC( clientSideUnitHashTables );

	LDEC( getViewport );

	LDEC( goldDialogAction );
	LDEC( goldDialogAmount );

	LDEC( NPCMenu );
	LDEC( NPCMenuAmount );

	LDEC( tradeLayout );
	LDEC( stashLayout );
	LDEC( storeLayout );
	LDEC( cubeLayout );
	LDEC( inventoryLayout );
	LDEC( mercenaryLayout );

	LDEC( regularCursorType );
	LDEC( shopCursorType );

	LDEC( ping );
	LDEC( skip );
	LDEC( FPS );
	LDEC( divisor );

	LDEC( overheadTrigger );
	LDEC( recentInteractId );
	LDEC( itemPriceList );

	LDEC( transactionDialog );
	LDEC( transactionDialogs );
	LDEC( transactionDialogs_2 );
	LDEC( transactionDialogsInfo );

	LDEC( gameInfo );
	LDEC( waypointTable );

	LDEC( playerUnit );
	LDEC( selectedInventoryItem );
	LDEC( playerUnitList );

	LDEC( weaponSwitch );

	LDEC( tradeAccepted );
	LDEC( tradeBlock );
	LDEC( recentTradeId );

	LDEC( expansionCharacterFlag );
	LDEC( mapId );

	LDEC( alwaysRun );
	LDEC( noPickup );

	LDEC( chatMessage );
	LDEC( orificeId );
	LDEC( cursorItemMode );

	LDEC( SGPTDataTable );

	LDEC( chatBoxMessage );
	LDEC( gameListControl );

	LDEC( battleNetData );

	LDEC( firstControl );
	LDEC( focusedControl );
	LDEC( chatInputBox );

	LDEC( classicKey );
	LDEC( expansionKey );
	LDEC( keyOwner );
	LDEC( windowHandlers );
}