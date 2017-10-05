#pragma once

#include <Windows.h>

// function offsets
#define d2DrawRectangle_Offset				0xF6300
#define d2DrawLine_Offset					0xF6380
#define d2DrawText_Offset					0x102320
#define d2GetTextSize_Offset				0x102520
#define d2SetTextSize_Offset				0x102EF0
#define d2GetHwnd_Offset					0xF59A0
#define d2GetScreenSize_Offset				0xF5160

#define d2GetQuestInfo_Offset				0xB32D0
#define d2SubmitItem_Offset					0xB2370
#define d2Transmute_Offset					0x8A0D0

#define d2FindClientSideUnit_Offset			0x63990
#define d2FindServerSideUnit_Offset			0x639B0
#define d2GetCurrentInteractingNPC_Offset	0xB1620
#define d2GetSelectedUnit_Offset			0x67A10
#define d2GetCursorItem_Offset				0x680A0
#define d2SetSelectedUnit_I_Offset			0x66DE0
#define d2GetItemName_Offset				0x8C060
#define d2LoadItemDesc_Offset				0x8DD90
#define d2GetMonsterOwner_Offset			0x79150
#define d2GetUnitHPPercent_Offset			0x79080
#define d2InitInventory_Offset				0x845A0
#define d2SetUIVar_Offset					0x55F20
#define d2GetUnitX_Offset					0x5ADF0
#define d2GetUnitY_Offset					0x5AE20
#define d2ShopAction_Offset					0xB3870
#define d2CloseNPCInteract_Offset			0xB3F10
#define d2CloseInteract_Offset				0x4C6B0

#define d2GetAutomapSize_Offset				0x5A710
#define d2NewAutomapCell_Offset				0x57C30
#define d2AddAutomapCell_Offset				0x57B00
#define d2RevealAutomapRoom_Offset			0x58F40
#define d2InitAutomapLayer_I_Offset			0x58D40

#define d2ClickMap_Offset					0x62D00
#define d2LeftClickItem_I_Offset			0x8FFE0

#define d2GetMouseXOffset_Offset			0x5AFC0
#define d2GetMouseYOffset_Offset			0x5AFB0

#define d2PrintGameString_Offset			0x9E3A0
#define d2PrintPartyString_Offset			0x9E5C0
#define d2LeaveParty_Offset					0x79FC0

#define d2AcceptTrade_Offset				0xB9070
#define d2CancelTrade_Offset				0xB90B0
#define d2TradeOK_Offset					0xB8A30

#define d2GetDifficulty_Offset				0x4DCD0
#define d2ExitGame_Offset					0x4DD60
#define d2GetUiVar_I_Offset					0x538D0
#define d2DrawRectFrame_Offset				0x52E50
#define d2PerformGoldDialogAction_Offset	0x54080
#define d2GetPlayerUnit_Offset				0x63DD0
#define d2ClearScreen_Offset				0xB4620
#define d2CloseNPCTalk_Offset				0xA17D0
#define d2TestPvpFlag_Offset				0xDC440

// variable offsets
#define d2ScreenSizeXOffset					0x31146C
#define d2ScreenSizeYOffset					0x311470
#define d2CursorHoverX_Offset				0x321E4C						
#define d2CursorHoverY_Offset				0x321E50
#define d2MouseX_Offset						0x3A6AB0
#define d2MouseY_Offset						0x3A6AAC
#define d2MouseOffsetY_Offset				0x3A5208
#define d2MouseOffsetX_Offset				0x3A5214
#define d2MouseOffsetZ_Offset				0x3A520C

#define d2AutomapOn_Offset					0x3A27E8
#define d2AutomapMode_Offset				0x311254
#define d2Offset_Offset						0x3A5198
#define d2AutomapLayer_Offset				0x3A5164
#define d2MercenaryReviveCost_Offset		0x3C0DD0

#define d2ServerSideUnitHashTables_Offset	0x3A5E70
#define d2ClientSideUnitHashTables_Offset	0x3A5270

#define d2ViewportX_Offset					0x3A5208
#define d2ViewportY_Offset					0x3A520C

#define d2GoldDialogAction_Offset			0x3A279C
#define d2GoldDialogAmount_Offset			0x3A2A68

#define d2NPCMenu_Offset					0x326C48
#define d2NPCMenuAmount_Offset				0x325A74

#define d2TradeLayout_Offset				0x3BCA30
#define d2StashLayout_Offset				0x3BCA78
#define d2StoreLayout_Offset				0x3BCB58
#define d2CubeLayout_Offset					0x3BCB70
#define d2InventoryLayout_Offset			0x3BCB88
#define d2MercLayout_Offset					0x3BCD4C

#define d2RegularCursorType_Offset			0x3A6AF0
#define d2ShopCursorType_Offset				0x3BCBF0

#define d2Ping_Offset						0x3A04A4
#define d2Skip_Offset						0x3A04B0
#define d2FPS_Offset						0x3BB390
#define d2Divisor_Offset					0x311254

#define d2OverheadTrigger_Offset			0x3BF20E
#define d2RecentInteractId_Offset			0x3C0D25
#define d2ItemPriceList_Offset				0x3C0D43

#define d2TransactionDialog_Offset			0x3C0D63
#define d2TransactionDialogs_Offset			0x3C0E5C
#define d2TransactionDuakigs_2_Offset		0x3C0E58
#define d2TransactionDialogInfo_Offset		0x3C0E54

#define d2GameInfo_Offset					0x3A0438
#define d2WaypointTable_Offset				0x3BF081
#define d2PlayerUnit_Offset					0x3A6A70
#define d2SelectedInvItem_Offset			0x3BCBF4
#define d2PlayerUnitList_Offset				0x3BB5C0
#define d2WeaponSwitch_Offset				0x3BCC4C

#define d2TradeAccepted_Offset				0x3BCE18
#define d2TradeBlock_Offset					0x3BCE28

#define d2RecentTradeId_Offset				0x3C0E7C
#define d2ExpansionCharacterFlag_Offset		0x3A04F4
#define d2MapId_Offset						0x3A0638
#define d2AlwaysRun_Offset					0x3A0660
#define d2NoPickup_Offset					0x3A6A90

#define d2ChatMessage_Offset				0x3BB638
#define d2OrificeId_Offset					0x3C547C
#define d2CursorItemMode_Offset				0x3C5474

// functions
typedef void(__stdcall d2DrawRectangle_t)(int x1, int y1, int x2, int y2, DWORD color, DWORD transparency);
typedef void(__stdcall d2DrawLine_t)(int x1, int y1, int x2, int y2, DWORD color, DWORD unknown);

typedef void(__fastcall d2DrawText_t)(const wchar_t* str, int x, int y, DWORD color, DWORD unknown);
typedef void(__fastcall d2GetTextSize_t)(wchar_t* str, DWORD* width, DWORD* fileNo);
typedef void(__fastcall d2SetTextSize_t)(DWORD size);

extern d2DrawRectangle_t* d2DrawRectangle;
extern d2DrawLine_t* d2DrawLine;

extern d2DrawText_t* d2DrawText;
extern d2GetTextSize_t* d2GetTextSize;
extern d2SetTextSize_t* d2SetTextSize;

//  variables
extern DWORD* d2ScreenSizeX;
extern DWORD* d2ScreenSizeY;
extern DWORD* d2MouseX;
extern DWORD* d2MouseY;
extern DWORD* d2MouseOffsetY;
extern DWORD* d2MouseOffsetX;
extern DWORD* d2MouseOffsetZ;

void initializeInterface(DWORD baseAddress);