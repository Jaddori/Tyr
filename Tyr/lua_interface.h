#pragma once

#include "lua.hpp"
#include "d2_interface.h"

#define LDEC( name ) int name ( lua_State* lua )

namespace lua_interface
{
	void bind( lua_State* lua );

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
	LDEC( getScreenSize );

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
	LDEC( getCursorHoverPosition );
	LDEC( getMousePosition );
	LDEC( getMouseOffset );

	LDEC( getAutomapOn );
	LDEC( getAutomapMode );
	LDEC( getOffset );
	LDEC( getAutomapLayer );

	LDEC( getMercenaryReviveCost );

	LDEC( getServerSideUnitHashTables );
	LDEC( getClientSideUnitHashTables );

	LDEC( getViewport );

	LDEC( getGoldDialogAction );
	LDEC( getGoldDialogAmount );

	LDEC( getNPCMenu );
	LDEC( getNPCMenuAmount );

	LDEC( getTradeLayout );
	LDEC( getStashLayout );
	LDEC( getStoreLayout );
	LDEC( getCubeLayout );
	LDEC( getInventoryLayout );
	LDEC( getMercenaryLayout );

	LDEC( getRegularCursorType );
	LDEC( getShopCursorType );

	LDEC( getPing );
	LDEC( getSkip );
	LDEC( getFPS );
	LDEC( getDivisor );

	LDEC( getOverheadTrigger );
	LDEC( getRecentInteractId );
	LDEC( getItemPriceList );

	LDEC( getTransactionDialog );
	LDEC( getTransactionDialogs );
	LDEC( getTransactionDialogs_2 );
	LDEC( getTransactionDialogsInfo );

	LDEC( getGameInfo );
	LDEC( getWaypointTable );

	LDEC( getPlayerUnit );
	LDEC( getSelectedInventoryItem );
	LDEC( getPlayerUnitList );

	LDEC( getWeaponSwitch );

	LDEC( getTradeAccepted );
	LDEC( getTradeBlock );
	LDEC( getRecentTradeId );

	LDEC( getExpansionCharacterFlag );
	LDEC( getMapId );

	LDEC( getAlwaysRun );
	LDEC( getNoPickup );

	LDEC( getChatMessage );
	LDEC( getOrificeId );
	LDEC( getCursorItemMode );

	LDEC( getSGPTDataTable );

	LDEC( getChatBoxMessage );
	LDEC( getGameListControl );

	LDEC( getBattleNetData );

	LDEC( getFirstControl );
	LDEC( getFocusedControl );
	LDEC( getChatInputBox );

	LDEC( getClassicKey );
	LDEC( getExpansionKey );
	LDEC( getKeyOwner );
	LDEC( getWindowHandlers );
}