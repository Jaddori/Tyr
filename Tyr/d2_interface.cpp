#include "d2_interface.h"

d2GetQuestInfo_t*					d2GetQuestInfo = NULL;
d2SubmitItem_t*						d2SubmitItem = NULL;
d2Transmute_t*						d2Transmute = NULL;

d2FindClientSideUnit_t*				d2FindClientSideUnit = NULL;
d2FindServerSideUnit_t*				d2FindServerSideUnit = NULL;
d2GetCurrentInteractingNPC_t*		d2GetCurrentInteractingNPC = NULL;
d2GetSelectedUnit_t*				d2GetSelectedUnit = NULL;
d2GetCursorItem_t*					d2GetCursorItem = NULL;
d2GetItemName_t*					d2GetItemName = NULL;
d2LoadItemDescription_t*			d2LoadItemDescription = NULL;
d2GetMonsterOwner_t*				d2GetMonsterOwner = NULL;
d2GetUnitHPPercent_t*				d2GetUnitHPPercent = NULL;
d2InitInventory_t*					d2InitInventory = NULL;
d2SetUIVariable_t*					d2SetUIVariable = NULL;
d2GetUnitX_t*						d2GetUnitX = NULL;
d2GetUnitY_t*						d2GetUnitY = NULL;

d2ShopAction_t*						d2ShopAction = NULL;

d2CloseNPCInteract_t*				d2CloseNPCInteract = NULL;
d2CloseInteract_t*					d2CloseInteract = NULL;

d2GetAutomapSize_t*					d2GetAutomapSize = NULL;
d2NewAutomapCell_t*					d2NewAutomapCell = NULL;
d2AddAutomapCell_t*					d2AddAutomapCell = NULL;
d2RevealAutomapRoom_t*				d2RevealAutomapRoom = NULL;
d2InitAutomapLayer_I_t*				d2InitAutomapLayer_I = NULL;

d2ClickMap_t*						d2ClickMap = NULL;
d2LeftClickItem_I_t*				d2LeftClickItem_I = NULL;

d2GetMouseXOffset_t*				d2GetMouseXOffset = NULL;
d2GetMouseYOffset_t*				d2GetMouseYOffset = NULL;

d2PrintGameString_t*				d2PrintGameString = NULL;
d2PrintPartyString_t*				d2PrintPartyString = NULL;

d2LeaveParty_t*						d2LeaveParty = NULL;

d2AcceptTrade_t*					d2AcceptTrade = NULL;
d2CancelTrade_t*					d2CancelTrade = NULL;
d2TradeOK_t*						d2TradeOK = NULL;

d2GetDifficulty_t*					d2GetDifficulty = NULL;
d2ExitGame_t*						d2ExitGame = NULL;
d2GetUIVariable_I_t*				d2GetUIVariable_I = NULL;
d2DrawRectFrame_t*					d2DrawRectFrame = NULL;
d2PerformGoldDialogAction_t*		d2PerformGoldDialogAction = NULL;
d2GetPlayerUnit_t*					d2GetPlayerUnit = NULL;
d2ClearScreen_t*					d2ClearScreen = NULL;
d2CloseNPCTalk_t*					d2CloseNPCTalk = NULL;
d2TestPvpFlag_t*					d2TestPvpFlag = NULL;

d2InitLevel_t*						d2InitLevel = NULL;
d2UnloadAct_t*						d2UnloadAct = NULL;
d2LoadAct_t*						d2LoadAct = NULL;

d2GetLevelText_t*					d2GetLevelText = NULL;
d2GetObjectText_t*					d2GetObjectText = NULL;
d2GetItemText_t*					d2GetItemText = NULL;

d2GetLayer_t*						d2GetLayer = NULL;
d2GetLevel_t*						d2GetLevel = NULL;

d2GetStatList_t*					d2GetStatList = NULL;
d2CopyStatList_t*					d2CopyStatList = NULL;
d2GetUnitStat_t*					d2GetUnitStat = NULL;
d2GetUnitState_t*					d2GetUnitState = NULL;

d2CheckUnitCollision_t*				d2CheckUnitCollision = NULL;
d2GetRoomFromUnit_t*				d2GetRoomFromUnit = NULL;
d2GetTargetUnitType_t*				d2GetTargetUnitType = NULL;

d2GetSkillLevel_t*					d2GetSkillLevel = NULL;

d2GetItemLevelRequirement_t*		d2GetItemLevelRequirement = NULL;

d2GetItemPrice_t*					d2GetItemPrice = NULL;
d2GetRepairCost_t*					d2GetRepairCost = NULL;
d2GetItemMagicalMods_t*				d2GetItemMagicalMods = NULL;
d2GetItemFromInventory_t*			d2GetItemFromInventory = NULL;
d2GetNextItemFromInventory_t*		d2GetNextItemFromInventory = NULL;

d2GenerateOverheadMessage_t*		d2GenerateOverheadMessage = NULL;
d2FixOverheadMessage_t*				d2FixOverheadMessage = NULL;

d2AddRoomData_t*					d2AddRoomData = NULL;
d2RemoveRoomData_t*					d2RemoveRoomData = NULL;

d2GetQuestFlag_t*					d2GetQuestFlag = NULL;

d2MapToAbsScreen_t*					d2MapToAbsScreen = NULL;
d2AbsScreenToMap_t*					d2AbsScreenToMap = NULL;

d2CheckWaypoint_t*					d2CheckWaypoint = NULL;

d2IsTownByLevelNumber_t*			d2IsTownByLevelNumber = NULL;
d2GetLevelNumberFromRoom_t*			d2GetLevelNumberFromRoom = NULL;
d2FindRoom1_t*						d2FindRoom1 = NULL;
d2GetItemPalette_t*					d2GetItemPalette = NULL;

d2SendPacket_t*						d2SendPacket = NULL;
d2ReceivePacket_t*					d2ReceivePacket = NULL;
d2ReceivePacket_I_t*				d2ReceivePacket_I = NULL;

d2DrawRectangle_t*					d2DrawRectangle = NULL;
d2DrawLine_t*						d2DrawLine = NULL;
d2DrawAutomapCell2_t*				d2DrawAutomapCell2 = NULL;
d2GetHwnd_t*						d2GetHwnd = NULL;
//d2GetScreenSize_t*					d2GetScreenSize = NULL;

d2DoChat_t*							d2DoChat = NULL;
d2PrintChannelText_t*				d2PrintChannelText = NULL;

d2InitCellFile_t*					d2InitCellFile = NULL;
d2DeleteCellFile_t*					d2DeleteCellFile = NULL;
d2GetLocaleText_t*					d2GetLocaleText = NULL;

d2SetControlText_t*					d2SetControlText = NULL;
d2DrawSprites_t*					d2DrawSprites = NULL;
d2LoadCellFile_t*					d2LoadCellFile = NULL;

d2TakeScreenshot_t*					d2TakeScreenshot = NULL;
d2DrawText_t*						d2DrawText = NULL;
d2GetTextSize_t*					d2GetTextSize = NULL;
d2SetTextSize_t*					d2SetTextSize = NULL;
d2GetTextWidthFileNumber_t*			d2GetTextWidthFileNumber = NULL;
d2DestroyEditBox_t*					d2DestroyEditBox = NULL;
d2DestroyControl_t*					d2DestroyControl = NULL;

d2SetEditBoxCallback_t*				d2SetEditBoxCallback = NULL;
d2SetEditBoxProcedure_t*			d2SetEditBoxProcedure = NULL;
d2SelectEditBoxText_t*				d2SelectEditBoxText = NULL;
d2InitMPQ_t*						d2InitMPQ = NULL;

d2Rand_t*							d2Rand = NULL;
d2Exit0_t*							d2Exit0 = NULL;

//  variables
DWORD*								d2ScreenSizeX = NULL;
DWORD*								d2ScreenSizeY = NULL;
DWORD*								d2CursorHoverX = NULL;
DWORD*								d2CursorHoverY = NULL;
DWORD*								d2MouseX = NULL;
DWORD*								d2MouseY = NULL;
DWORD*								d2MouseOffsetY = NULL;
DWORD*								d2MouseOffsetX = NULL;
DWORD*								d2MouseOffsetZ = NULL;

DWORD*								d2AutomapOn = NULL;
int*								d2AutomapMode = NULL;
POINT*								d2Offset = NULL;
d2AutomapLayer_t**					d2AutomapLayer = NULL;

DWORD*								d2MercenaryReviveCost = NULL;

d2UnitHashTable_t*					d2ServerSideUnitHashTables = NULL;
d2UnitHashTable_t*					d2ClientSideUnitHashTables = NULL;

int*								d2ViewportX = NULL;
int*								d2ViewportY = NULL;

DWORD*								d2GoldDialogAction = NULL;
DWORD*								d2GoldDialogAmount = NULL;

d2NPCMenu_t**						d2NPCMenu = NULL;
DWORD*								d2NPCMenuAmount = NULL;

d2InventoryLayout_t**				d2TradeLayout = NULL;
d2InventoryLayout_t**				d2StashLayout = NULL;
d2InventoryLayout_t**				d2StoreLayout = NULL;
d2InventoryLayout_t**				d2CubeLayout = NULL;
d2InventoryLayout_t**				d2InventoryLayout = NULL;
d2InventoryLayout_t**				d2MercenaryLayout = NULL;

DWORD*								d2RegularCursorType = NULL;
DWORD*								d2ShopCursorType = NULL;

DWORD*								d2Ping = NULL;
DWORD*								d2Skip = NULL;
DWORD*								d2FPS = NULL;
int*								d2Divisor = NULL;

DWORD*								d2OverheadTrigger = NULL;
DWORD*								d2RecentInteractId = NULL;
DWORD*								d2ItemPriceList = NULL;

void**								d2TransactionDialog = NULL;
DWORD*								d2TransactionDialogs = NULL;
DWORD*								d2TransactionDialogs_2 = NULL;
d2TransactionDialogsInfo_t**		d2TransactionDialogsInfo = NULL;

d2GameInfo_t**						d2GameInfo = NULL;
DWORD*								d2WaypointTable = NULL;

d2UnitAny_t**						d2PlayerUnit = NULL;
d2UnitAny_t**						d2SelectedInventoryItem = NULL;
d2RosterUnit_t**					d2PlayerUnitList = NULL;

DWORD*								d2WeaponSwitch = NULL;

DWORD*								d2TradeAccepted = NULL;
DWORD*								d2TradeBlock = NULL;
DWORD*								d2RecentTradeId = NULL;

DWORD*								d2ExpansionCharacterFlag = NULL;
DWORD*								d2MapId = NULL;

DWORD*								d2AlwaysRun = NULL;
DWORD*								d2NoPickup = NULL;

wchar_t**							d2ChatMessage = NULL;
DWORD*								d2OrificeId = NULL;
DWORD*								d2CursorItemMode = NULL;

DWORD*								d2SGPTDataTable = NULL;

char**								d2ChatBoxMessage = NULL;
d2Control_t**						d2GameListControl = NULL;

d2BattleNetData_t**					d2BattleNetData = NULL;

d2Control_t**						d2FirstControl = NULL;
d2Control_t**						d2FocusedControl = NULL;
DWORD**								d2ChatInputBox = NULL;

char**								d2ClassicKey = NULL;
char**								d2ExpansionKey = NULL;
char**								d2KeyOwner = NULL;
d2WindowHandlerHashTable_t*			d2WindowHandlers = NULL;

#define FUNC( name ) name = ( name ## _t* )( baseAddress + name ## _Offset )
#define VAR( name, type ) name = ( type* )( baseAddress + name ## _Offset )

void initializeInterface(DWORD baseAddress )
{
	// functions
	FUNC( d2GetQuestInfo );
	FUNC( d2SubmitItem );
	FUNC( d2Transmute );

	FUNC( d2FindClientSideUnit );
	FUNC( d2FindServerSideUnit );
	FUNC( d2GetCurrentInteractingNPC );
	FUNC( d2GetSelectedUnit );
	FUNC( d2GetCursorItem );
	FUNC( d2GetItemName );
	FUNC( d2LoadItemDescription );
	FUNC( d2GetMonsterOwner );
	FUNC( d2GetUnitHPPercent );
	FUNC( d2InitInventory );
	FUNC( d2SetUIVariable );
	FUNC( d2GetUnitX );
	FUNC( d2GetUnitY );

	FUNC( d2ShopAction );

	FUNC( d2CloseNPCInteract );
	FUNC( d2CloseInteract );

	FUNC( d2GetAutomapSize );
	FUNC( d2NewAutomapCell );
	FUNC( d2AddAutomapCell );
	FUNC( d2RevealAutomapRoom );
	FUNC( d2InitAutomapLayer_I );

	FUNC( d2ClickMap );
	FUNC( d2LeftClickItem_I );

	FUNC( d2GetMouseXOffset );
	FUNC( d2GetMouseYOffset );

	FUNC( d2PrintGameString );
	FUNC( d2PrintPartyString );

	FUNC( d2LeaveParty );

	FUNC( d2AcceptTrade );
	FUNC( d2CancelTrade );
	FUNC( d2TradeOK );

	FUNC( d2GetDifficulty );
	FUNC( d2ExitGame );
	FUNC( d2GetUIVariable_I );
	FUNC( d2DrawRectFrame );
	FUNC( d2PerformGoldDialogAction );
	FUNC( d2GetPlayerUnit );
	FUNC( d2ClearScreen );
	FUNC( d2CloseNPCTalk );
	FUNC( d2TestPvpFlag );

	FUNC( d2InitLevel );
	FUNC( d2UnloadAct );
	FUNC( d2LoadAct );

	FUNC( d2GetLevelText );
	FUNC( d2GetObjectText );
	FUNC( d2GetItemText );

	FUNC( d2GetLayer );
	FUNC( d2GetLevel );

	FUNC( d2GetStatList );
	FUNC( d2CopyStatList );
	FUNC( d2GetUnitStat );
	FUNC( d2GetUnitState );

	FUNC( d2CheckUnitCollision );
	FUNC( d2GetRoomFromUnit );
	FUNC( d2GetTargetUnitType );

	FUNC( d2GetSkillLevel );

	FUNC( d2GetItemLevelRequirement );

	FUNC( d2GetItemPrice );
	FUNC( d2GetRepairCost );
	FUNC( d2GetItemMagicalMods );
	FUNC( d2GetItemFromInventory );
	FUNC( d2GetNextItemFromInventory );

	FUNC( d2GenerateOverheadMessage );
	FUNC( d2FixOverheadMessage );

	FUNC( d2AddRoomData );
	FUNC( d2RemoveRoomData );

	FUNC( d2GetQuestFlag );

	FUNC( d2MapToAbsScreen );
	FUNC( d2AbsScreenToMap );

	FUNC( d2CheckWaypoint );

	FUNC( d2IsTownByLevelNumber );
	FUNC( d2GetLevelNumberFromRoom );
	FUNC( d2FindRoom1 );
	FUNC( d2GetItemPalette );

	FUNC( d2SendPacket );
	FUNC( d2ReceivePacket );
	FUNC( d2ReceivePacket_I );

	FUNC( d2DrawRectangle );
	FUNC( d2DrawLine );
	FUNC( d2DrawAutomapCell2 );
	FUNC( d2GetHwnd );
	//FUNC( d2GetScreenSize );

	FUNC( d2DoChat );
	FUNC( d2PrintChannelText );

	FUNC( d2InitCellFile );
	FUNC( d2DeleteCellFile );
	FUNC( d2GetLocaleText );

	FUNC( d2SetControlText );
	FUNC( d2DrawSprites );
	FUNC( d2LoadCellFile );

	FUNC( d2TakeScreenshot );
	FUNC( d2DrawText );
	FUNC( d2GetTextSize );
	FUNC( d2SetTextSize );
	FUNC( d2GetTextWidthFileNumber );
	FUNC( d2DestroyEditBox );
	FUNC( d2DestroyControl );

	FUNC( d2SetEditBoxCallback );
	FUNC( d2SetEditBoxProcedure );
	FUNC( d2SelectEditBoxText );
	FUNC( d2InitMPQ );

	FUNC( d2Rand );
	FUNC( d2Exit0 );

	// variables
	VAR( d2ScreenSizeX, DWORD );
	VAR( d2ScreenSizeY, DWORD );
	VAR( d2CursorHoverX, DWORD );
	VAR( d2CursorHoverY, DWORD );
	VAR( d2MouseX, DWORD );
	VAR( d2MouseY, DWORD );
	VAR( d2MouseOffsetY, DWORD );
	VAR( d2MouseOffsetX, DWORD );
	VAR( d2MouseOffsetZ, DWORD );

	VAR( d2AutomapOn, DWORD );
	VAR( d2AutomapMode, int );
	VAR( d2Offset, POINT );
	VAR( d2AutomapLayer, d2AutomapLayer_t* );

	VAR( d2MercenaryReviveCost, DWORD );

	VAR( d2ServerSideUnitHashTables, d2UnitHashTable_t );
	VAR( d2ClientSideUnitHashTables, d2UnitHashTable_t );

	VAR( d2ViewportX, int );
	VAR( d2ViewportY, int );

	VAR( d2GoldDialogAction, DWORD );
	VAR( d2GoldDialogAmount, DWORD );

	VAR( d2NPCMenu, d2NPCMenu_t* );
	VAR( d2NPCMenuAmount, DWORD );

	VAR( d2TradeLayout, d2InventoryLayout_t* );
	VAR( d2StashLayout, d2InventoryLayout_t* );
	VAR( d2StoreLayout, d2InventoryLayout_t* );
	VAR( d2CubeLayout, d2InventoryLayout_t* );
	VAR( d2InventoryLayout, d2InventoryLayout_t* );
	VAR( d2MercenaryLayout, d2InventoryLayout_t* );

	VAR( d2RegularCursorType, DWORD );
	VAR( d2ShopCursorType, DWORD );

	VAR( d2Ping, DWORD );
	VAR( d2Skip, DWORD );
	VAR( d2FPS, DWORD );
	VAR( d2Divisor, int );

	VAR( d2OverheadTrigger, DWORD );
	VAR( d2RecentInteractId, DWORD );
	VAR( d2ItemPriceList, DWORD );

	VAR( d2TransactionDialog, void* );
	VAR( d2TransactionDialogs, DWORD );
	VAR( d2TransactionDialogs_2, DWORD );
	VAR( d2TransactionDialogsInfo, d2TransactionDialogsInfo_t* );

	VAR( d2GameInfo, d2GameInfo_t* );
	VAR( d2WaypointTable, DWORD );

	VAR( d2PlayerUnit, d2UnitAny_t* );
	VAR( d2SelectedInventoryItem, d2UnitAny_t* );
	VAR( d2PlayerUnitList, d2RosterUnit_t* );

	VAR( d2WeaponSwitch, DWORD );

	VAR( d2TradeAccepted, DWORD );
	VAR( d2TradeBlock, DWORD );
	VAR( d2RecentTradeId, DWORD );

	VAR( d2ExpansionCharacterFlag, DWORD );
	VAR( d2MapId, DWORD );

	VAR( d2AlwaysRun, DWORD );
	VAR( d2NoPickup, DWORD );

	VAR( d2ChatMessage, wchar_t* );
	VAR( d2OrificeId, DWORD );
	VAR( d2CursorItemMode, DWORD );

	VAR( d2SGPTDataTable, DWORD );

	VAR( d2ChatBoxMessage, char* );
	VAR( d2GameListControl, d2Control_t* );

	VAR( d2BattleNetData, d2BattleNetData_t* );

	VAR( d2FirstControl, d2Control_t* );
	VAR( d2FocusedControl, d2Control_t* );
	VAR( d2ChatInputBox, DWORD* );

	VAR( d2ClassicKey, char* );
	VAR( d2ExpansionKey, char* );
	VAR( d2KeyOwner, char* );
	VAR( d2WindowHandlers, d2WindowHandlerHashTable_t );
}