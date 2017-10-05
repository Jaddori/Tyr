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
d2GetUIVariable_t*					d2GetUIVariable = NULL;
d2DrawRectFrame_t*					d2DrawRectFrame = NULL;
d2PerformGoldDialogAction_t*		d2PerformGoldDialogAction = NULL;
d2GetPlayerUnit_t*					d2GetPlayerUnit = NULL;
d2ClearScreen_t*					d2ClearScreen = NULL;
d2CloseNPCTalk_t*					d2CloseNPCTalk = NULL;
d2TestPvpFlag_t*					d2TestPvpFlag = NULL;

d2InitLevel_t*						d2InitLevel = NULL;
d2UnloadAct_t*						d2UnloadAct = NULL;
d2GetObjectText_t*					d2GetObjectText = NULL;
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
d2GetScreenSize_t*					d2GetScreenSize = NULL;

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
d2SelectEditBoxText_t*				d2SelecEditBoxText = NULL;
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
AutomapLayer**						d2AutomapLayer = NULL;

DWORD*								d2MercenaryReviveCost = NULL;

UnitHashTable*						d2ServerSideUnitHashTables = NULL;
UnitHashtable*						d2ClientSideUnitHashTables = NULL;

int*								d2ViewportX = NULL;
int*								d2ViewportY = NULL;

DWORD*								d2GoldDialogAction = NULL;
DWORD*								d2GoldDialogAmount = NULL;

NPCMenu**							d2NPCMenu = NULL;
DWORD*								d2NPCMenuAmount = NULL;

InventoryLayout**					d2TradeLayout = NULL;
InventoryLayout**					d2StashLayout = NULL;
InventoryLayout**					d2StoreLayout = NULL;
InventoryLayout**					d2CubeLayout = NULL;
InventoryLayout**					d2InventoryLayout = NULL;
InventoryLayout**					d2MercenaryLayout = NULL;

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
TransactionDialogsInfo_t*			d2TransactionDialogsInfo = NULL;

GameInfo**							d2GameInfo = NULL;
DWORD*								d2WaypointTable = NULL;

UnitAny**							d2PlayerUnit = NULL;
UnitAny**							d2SelectedInventoryItem = NULL;
RosterUnit**						d2PlayerUnitList = NULL;

DWORD*								d2WeaponSwitch = NULL;

DWORD*								d2TradeAccepted = NULL;
DWORD*								d2TradeBlock = NULL;
DWORD*								d2RecentTradeId = NULL;

DWORD*								d2ExpansionCharacterFlag = NULL;
DWORD*								d2MapId = NULL;

DWORD*								d2AlwaysRun = NULL;
DWORD*								d2NoPickup = NULL;

wchar_t*							d2ChatMessage = NULL;
DWORD*								d2OrificeId = NULL;
DWORD*								d2CursorItemMode = NULL;

DWORD*								d2SGPTDataTable = NULL;

char**								d2ChatBoxMessage = NULL;
Control**							d2GameListControl = NULL;

BattleNetData**						d2BattleNetData = NULL;

Control**							d2FirstControl = NULL;
Control**							d2FocusedControl = NULL;
DWORD**								d2ChatInputBox = NULL;

char**								d2ClassicKey = NULL;
char**								d2ExpansionKey = NULL;
char**								d2KeyOwner = NULL;
WindowHandlersHashTable*			d2WindowHandlers = NULL;

void initializeInterface(DWORD baseAddress )
{
	// functions


	d2DrawRectangle	= (d2DrawRectangle_t*)(baseAddress +d2DrawRectangleOffset);
	d2DrawLine		= (d2DrawLine_t*)(baseAddress +d2DrawLineOffset);

	d2DrawText		= (d2DrawText_t*)(baseAddress +d2DrawTextOffset);
	d2GetTextSize	= (d2GetTextSize_t*)(baseAddress +d2GetTextSizeOffset);
	d2SetTextSize	= (d2SetTextSize_t*)(baseAddress +d2SetTextSizeOffset);

	// variables
	d2ScreenSizeX	= (DWORD*)(baseAddress +d2ScreenSizeXOffset);
	d2ScreenSizeY	= (DWORD*)(baseAddress +d2ScreenSizeYOffset);
	d2MouseX		= (DWORD*)(baseAddress +d2MouseXOffset);
	d2MouseY		= (DWORD*)(baseAddress +d2MouseYOffset);
	d2MouseOffsetY	= (DWORD*)(baseAddress +d2MouseOffsetYOffset);
	d2MouseOffsetX	= (DWORD*)(baseAddress +d2MouseOffsetXOffset);
	d2MouseOffsetZ	= (DWORD*)(baseAddress +d2MouseOffsetZOffset);
}