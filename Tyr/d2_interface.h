#pragma once

#include <Windows.h>
#include "d2_structures.h"

// function offsets
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
#define d2LoadItemDescription_Offset		0x8DD90
#define d2GetMonsterOwner_Offset			0x79150
#define d2GetUnitHPPercent_Offset			0x79080
#define d2InitInventory_Offset				0x845A0
#define d2SetUIVariable_Offset				0x55F20
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
#define d2GetUIVariable_I_Offset			0x538D0
#define d2DrawRectFrame_Offset				0x52E50
#define d2PerformGoldDialogAction_Offset	0x54080
#define d2GetPlayerUnit_Offset				0x63DD0
#define d2ClearScreen_Offset				0xB4620
#define d2CloseNPCTalk_Offset				0xA17D0
#define d2TestPvpFlag_Offset				0xDC440

#define d2InitLevel_Offset					0x2424A0
#define d2UnloadAct_Offset					0x21AFD3
#define d2GetObjectText_Offset				0x240E90
#define d2LoadAct_Offset					0x2194A0

#define d2GetLevelText_Offset				0x21DB70
#define d2GetObjectText_Offset				0x240E90
#define d2GetItemText_Offset				0x2335F0

#define d2GetLayer_Offset					0x21E470
#define d2GetLevel_Offset					0x242AE0

#define d2GetStatList_Offset				0x2257D0
#define d2CopyStatList_Offset				0x225C90
#define d2GetUnitStat_Offset				0x225480
#define d2GetUnitState_Offset				0x239DF0

#define d2CheckUnitCollision_Offset			0x222AA0
#define d2GetRoomFromUnit_Offset			0x220BB0
#define d2GetTargetUnitType_Offset			0x773C0
#define d2GetSkillLevel_Offset				0x2442A0

#define d2GetItemLevelRequirement_Offset	0x22BA60
#define d2GetItemPrice_Offset				0x22FDC0
#define d2GetRepairCost_Offset				0x22FE60
#define d2GetItemMagicalMods_Offset			0x233EE0
#define d2GetItemFromInventory_Offset		0x23B2C0
#define d2GetNextItemFromInventory_Offset	0x23DFA0

#define d2GenerateOverheadMessage_Offset	0x261110
#define d2FixOverheadMessage_Offset			0x261230

#define d2AddRoomData_Offset				0x21A070
#define d2RemoveRoomData_Offset				0x21A0C0

#define d2GetQuestFlag_Offset				0x25C310

#define d2MapToAbsScreen_Offset				0x243260
#define d2AbsScreenToMap_Offset				0x243510
#define d2CheckWaypoint_Offset				0x260E50

#define d2IsTownByLevelNumber_Offset		0x21AAF0
#define d2GetLevelNumberFromRoom_Offset		0x21A1B0
#define d2FindRoom1_Offset					0x219DA3
#define d2GetItemPalette_Offset				0x22C100

#define d2SendPacket_Offset					0x12AE50
#define d2ReceivePacket_Offset				0x12AEB0
#define d2ReceivePacket_I_Offset			0x12B920

#define d2DrawRectangle_Offset				0xF6300
#define d2DrawLine_Offset					0xF6380
#define d2DrawAutomapCell2_Offset			0x0
#define d2GetHwnd_Offset					0xF59A0
//#define d2GetScreenSize_Offset				0xF5160

#define d2DoChat_Offset						0x42810
#define d2PrintChannelText_Offset			0x47AB0

#define d2InitCellFile_Offset				0x201340
#define d2DeleteCellFile_Offset				0x201A50
#define d2GetLocaleText_Offset				0x124A30

#define d2SetControlText_Offset				0xFF5A0
#define d2DrawSprites_Offset				0xF9870
#define d2LoadCellFile_Offset				0xFA9B0

#define d2TakeScreenshot_Offset				0xFA7A0
#define d2DrawText_Offset					0x102320
#define d2GetTextSize_Offset				0x102520
#define d2SetTextSize_Offset				0x102EF0
#define d2GetTextWidthFileNumber_Offset		0x102520
#define d2DestroyEditBox_Offset				0xFDAA0
#define d2DestroyControl_Offset				0xf95c0
#define d2SetEditBoxCallback_Offset			0xFDAD0
#define d2SetEditBoxProcedure_Offset		0xFDAD0
#define d2SelectEditBoxText_Offset			0xfdd00
#define d2InitMPQ_Offset					0x117332

#define d2DecodeAndLoadKeys_Offset			0x1234D0

#define d2Rand_Offset						0x5C370
#define d2Exit0_Offset						0x576F

// variable offsets
#define d2ScreenSizeX_Offset				0x31146C
#define d2ScreenSizeY_Offset				0x311470
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
#define d2MercenaryLayout_Offset			0x3BCD4C

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
#define d2TransactionDialogs_2_Offset		0x3C0E58
#define d2TransactionDialogsInfo_Offset		0x3C0E54

#define d2GameInfo_Offset					0x3A0438
#define d2WaypointTable_Offset				0x3BF081
#define d2PlayerUnit_Offset					0x3A6A70
#define d2SelectedInventoryItem_Offset		0x3BCBF4
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

// TODO: Figure out what this is
#define d2SGPTDataTable_Offset				0x344304

#define d2ChatBoxMessage_Offset				0x37AE40
#define d2GameListControl_Offset			0x398BC0

#define d2BattleNetData_Offset				0x3795D4

#define d2FirstControl_Offset				0x3D55BC
#define d2FocusedControl_Offset				0x3D55CC
#define d2ChatInputBox_Offset				0x398C80

#define d2ClassicKey_Offset					0x482744
#define d2ExpansionKey_Offset				0x48274C
#define d2KeyOwner_Offset					0x482750
#define d2WindowHandlers_Offset				0x379300

// functions
typedef void*								(__stdcall d2GetQuestInfo_t)(void);
typedef void								(__fastcall d2SubmitItem_t)(DWORD itemID);
typedef void								(__fastcall d2Transmute_t)(void);

typedef d2UnitAny_t*						(__fastcall d2FindClientSideUnit_t)(DWORD id, DWORD type);
typedef d2UnitAny_t*						(__fastcall d2FindServerSideUnit_t)(DWORD id, DWORD type);
typedef d2UnitAny_t*						(__fastcall d2GetCurrentInteractingNPC_t)(void);
typedef d2UnitAny_t*						(__stdcall	d2GetSelectedUnit_t)();
typedef d2UnitAny_t*						(__fastcall d2GetCursorItem_t)(void);
typedef void								(__fastcall d2GetSelectedUnit_I_t)(d2UnitAny_t* unit);
typedef BOOL								(__fastcall d2GetItemName_t)(d2UnitAny_t* item, wchar_t* buffer, DWORD bufferSize);
typedef BOOL								(__stdcall	d2LoadItemDescription_t)(d2UnitAny_t* item, int type);
typedef DWORD								(__fastcall d2GetMonsterOwner_t)(DWORD monsterID);
typedef DWORD								(__fastcall d2GetUnitHPPercent_t)(DWORD unitID);
typedef void								(__fastcall d2InitInventory_t)(void);
typedef DWORD								(__fastcall d2SetUIVariable_t)(DWORD variableNumber, DWORD howSet, DWORD unknown);
typedef int									(__fastcall d2GetUnitX_t)(d2UnitAny_t* unit);
typedef int									(__fastcall d2GetUnitY_t)(d2UnitAny_t* unit);

typedef void								(__fastcall d2ShopAction_t)(d2UnitAny_t* npc, d2UnitAny_t* item, DWORD sell, DWORD unknown, DWORD itemCost, DWORD mode, DWORD _2, DWORD _3);

typedef void								(__fastcall d2CloseNPCInteract_t)(void);
typedef void								(__fastcall d2CloseInteract_t)(void);

typedef DWORD								(__stdcall	d2GetAutomapSize_t)(void);
typedef d2AutomapCell_t*					(__fastcall d2NewAutomapCell_t)();
typedef void								(__fastcall d2AddAutomapCell_t)(d2AutomapCell_t* cell, d2AutomapCell_t** node);
typedef void								(_stdcall	d2RevealAutomapRoom_t)(d2Room1_t* room, DWORD clipFlag, d2AutomapLayer_t* layer);
typedef d2AutomapLayer_t*					(__fastcall d2InitAutomapLayer_I_t)(DWORD layerNumber);

typedef void								(__fastcall d2ClickMap_t)(DWORD mouseFlag, DWORD x, DWORD y, DWORD type);
typedef void								(__stdcall	d2LeftClickItem_I_t)(d2UnitAny_t* player, d2Inventory_t* inventory, int x, int y, DWORD clickType, d2InventoryLayout_t* layout, DWORD location);

typedef DWORD								(__fastcall d2GetMouseXOffset_t)(VOID);
typedef DWORD								(__fastcall d2GetMouseYOffset_t)(VOID);

typedef void								(__fastcall d2PrintGameString_t)(wchar_t* message, int color);
typedef void								(__fastcall d2PrintPartyString_t)(wchar_t* message, int color);

typedef void								(__fastcall d2LeaveParty_t)(void);

typedef void								(__fastcall d2AcceptTrade_t)(void);
typedef void								(__fastcall d2CancelTrade_t)(void);
typedef void								(__stdcall	d2TradeOK_t)(void);

typedef BYTE								(__stdcall	d2GetDifficulty_t)();
typedef void								(__fastcall d2ExitGame_t)(void);
typedef DWORD								(__fastcall d2GetUIVariable_I_t)(DWORD variableNumber);
typedef VOID								(__fastcall d2DrawRectFrame_t)(DWORD rect);
typedef void								(__fastcall d2PerformGoldDialogAction_t)(void);
typedef d2UnitAny_t*						(__stdcall	d2GetPlayerUnit_t)();
typedef void								(__fastcall d2ClearScreen_t)(void);
typedef DWORD								(__stdcall	d2CloseNPCTalk_t)(void* unknown);
typedef DWORD								(__fastcall d2TestPvpFlag_t)(DWORD unitId1, DWORD unitId2, DWORD flag);

typedef void								(__stdcall	d2InitLevel_t)(d2Level_t* level);
typedef unsigned							(__stdcall	d2UnloadAct_t)(d2Act_t* act);
typedef d2Act_t*							(__stdcall	d2LoadAct_t)(DWORD actNumber, DWORD mapId, DWORD _1, DWORD _2, DWORD _3, DWORD _4, DWORD townLevelId, DWORD func1, DWORD func2);

typedef d2LevelText_t*						(__stdcall	d2GetLevelText_t)(DWORD levelNumber);
typedef d2ObjectText_t*						(__stdcall	d2GetObjectText_t)(DWORD objectNumber);
typedef d2ItemText_t*						(__stdcall	d2GetItemText_t)(DWORD itemNumber);

typedef d2AutomapLayer2_t*					(__fastcall d2GetLayer_t)(DWORD levelNumber);
typedef d2Level_t*							(__fastcall d2GetLevel_t)(d2ActMisc_t* misc, DWORD levelNumber);

typedef d2StatList_t*						(__stdcall	d2GetStatList_t)(d2UnitAny_t* unit, DWORD unknown, DWORD maxEntries);
typedef DWORD								(__stdcall	d2CopyStatList_t)(d2StatList_t* statList, d2Stat_t* stats, DWORD maxEntries);
typedef DWORD								(__stdcall	d2GetUnitStat_t)(d2UnitAny_t* unit, DWORD stat, DWORD stat2);
typedef int									(__stdcall	d2GetUnitState_t)(d2UnitAny_t* unit, DWORD stateNumber);

typedef DWORD								(__stdcall	d2CheckUnitCollision_t)(d2UnitAny_t* a, d2UnitAny_t* b, DWORD bitMask);
typedef d2Room1_t*							(__stdcall	d2GetRoomFromUnit_t)(d2UnitAny_t* unit);
typedef d2Path_t*							(__stdcall	d2GetTargetUnitType_t)(d2Path_t* path);

typedef INT									(__stdcall	d2GetSkillLevel_t)(d2UnitAny_t* unit, d2Skill_t* skill, BOOL total);

typedef DWORD								(__stdcall	d2GetItemLevelRequirement_t)(d2UnitAny_t* item, d2UnitAny_t* player);

typedef DWORD								(__stdcall	d2GetItemPrice_t)(d2UnitAny_t* myUnit, d2UnitAny_t* item, DWORD _1, DWORD _2, DWORD _3, DWORD _4);
typedef DWORD								(__stdcall	d2GetRepairCost_t)(DWORD _1, d2UnitAny_t* unit, DWORD npcId, DWORD difficulty, DWORD itemPriceList, DWORD _2);
typedef char*								(__stdcall	d2GetItemMagicalMods_t)(DWORD prefixNumber);
typedef d2UnitAny_t*						(__stdcall	d2GetItemFromInventory_t)(d2Inventory_t* inventory);
typedef d2UnitAny_t*						(__stdcall	d2GetNextItemFromInventory_t)(d2UnitAny_t* item);

typedef d2OverheadMessage_t*				(__stdcall	d2GenerateOverheadMessage_t)(DWORD _1, CHAR* message, DWORD trigger);
typedef VOID								(__stdcall	d2FixOverheadMessage_t)(d2OverheadMessage_t* message, DWORD _1);

typedef void								(__stdcall	d2AddRoomData_t)(d2Act_t* act, int levelId, int x, int y, d2Room1_t* room);
typedef void								(__stdcall	d2RemoveRoomData_t)(d2Act_t* act, int levelId, int x, int y, d2Room1_t* room);

typedef int									(__stdcall	d2GetQuestFlag_t)(void* questInfo, DWORD act, DWORD quest);

typedef void								(__stdcall	d2MapToAbsScreen_t)(long* x, long* y);
typedef void								(__stdcall	d2AbsScreenToMap_t)(long* x, long* y);

typedef DWORD								(__stdcall	d2CheckWaypoint_t)(DWORD waypointTable, DWORD levelId);

typedef BOOL								(__stdcall	d2IsTownByLevelNumber_t)(DWORD levelNumber);
typedef BOOL								(__stdcall	d2GetLevelNumberFromRoom_t)(d2Room1_t* room);
typedef d2Room1_t*							(__stdcall	d2FindRoom1_t)(d2Act_t* act, int x, int y);
typedef int									(__stdcall	d2GetItemPalette_t)(d2UnitAny_t* player, d2UnitAny_t* item, BYTE* color, int transparencyType);

typedef void								(__stdcall	d2SendPacket_t)(size_t len, DWORD arg1, BYTE* packet);
typedef void								(__fastcall d2ReceivePacket_t)(BYTE* packet, DWORD len);
typedef void								(__fastcall d2ReceivePacket_I_t)(BYTE* packet, DWORD len);

typedef void								(__stdcall	d2DrawRectangle_t)(int x1, int y1, int x2, int y2, DWORD color, DWORD transparency);
typedef void								(__stdcall	d2DrawLine_t)(int x1, int y1, int x2, int y2, DWORD color, DWORD unknown);
typedef void								(__stdcall	d2DrawAutomapCell2_t)(d2CellContext_t* context, DWORD x, DWORD y, DWORD bright2, DWORD bright, BYTE* coltab);
typedef HWND								(__stdcall	d2GetHwnd_t)(void);
//typedef DWORD								(__stdcall	d2GetScreenSize_t)();

typedef void								(__fastcall d2DoChat_t)(void);
typedef void								(__fastcall d2PrintChannelText_t)(int _1, const char* text, DWORD color);

typedef VOID								(__stdcall	d2InitCellFile_t)(LPVOID file, d2CellFile_t** out, LPSTR sourceFile, DWORD line, DWORD fileVersion, LPSTR filename);
typedef void								(__stdcall	d2DeleteCellFile_t)(d2CellFile_t* file);
typedef wchar_t*							(__fastcall d2GetLocaleText_t)(WORD localeTextNumber);

typedef void*								(__fastcall d2SetControlText_t)(d2Control_t* box, wchar_t* text);
typedef void								(__fastcall d2DrawSprites_t)(void);
typedef d2CellFile_t*						(__fastcall d2LoadCellFile_t)(const char* file, int type);

typedef void								(__fastcall d2TakeScreenshot_t)();
typedef void								(__fastcall d2DrawText_t)(const wchar_t* str, int x, int y, DWORD color, DWORD unknown);
typedef DWORD								(__fastcall d2GetTextSize_t)(wchar_t* str, DWORD* width, DWORD* fileNo);
typedef DWORD								(__fastcall d2SetTextSize_t)(DWORD size);
typedef DWORD								(__fastcall d2GetTextWidthFileNumber_t)(wchar_t* str, DWORD* width, DWORD* fileNumber);
typedef DWORD								(__fastcall d2DestroyEditBox_t)(d2Control_t* control);
typedef VOID								(__stdcall	d2DestroyControl_t)(d2Control_t* control);

typedef BOOL								(__stdcall	d2EditBoxCallback_t)(d2Control_t* control, DWORD inputType, char* character);
typedef BOOL								(__stdcall	d2EditBoxProcedure_t)(d2Control_t* control, DWORD _1, DWORD _2);
typedef VOID								(__fastcall d2SetEditBoxCallback_t)(d2Control_t* control, d2EditBoxCallback_t* callback);
typedef void								(__fastcall d2SetEditBoxProcedure_t)(d2Control_t* control, d2EditBoxProcedure_t* procedure);
typedef void								(__fastcall d2SelectEditBoxText_t)(d2Control_t* control);
typedef DWORD								(__fastcall d2InitMPQ_t)(const char* mpqFile, char* mpqName, int v4, int v5);

typedef DWORD								(__fastcall d2Rand_t)(DWORD* seed);
typedef DWORD								(__fastcall d2Exit0_t)();

extern d2GetQuestInfo_t*					d2GetQuestInfo;
extern d2SubmitItem_t*						d2SubmitItem;
extern d2Transmute_t*						d2Transmute;

extern d2FindClientSideUnit_t*				d2FindClientSideUnit;
extern d2FindServerSideUnit_t*				d2FindServerSideUnit;
extern d2GetCurrentInteractingNPC_t*		d2GetCurrentInteractingNPC;
extern d2GetSelectedUnit_t*					d2GetSelectedUnit;
extern d2GetCursorItem_t*					d2GetCursorItem;
extern d2GetItemName_t*						d2GetItemName;
extern d2LoadItemDescription_t*				d2LoadItemDescription;
extern d2GetMonsterOwner_t*					d2GetMonsterOwner;
extern d2GetUnitHPPercent_t*				d2GetUnitHPPercent;
extern d2InitInventory_t*					d2InitInventory;
extern d2SetUIVariable_t*					d2SetUIVariable;
extern d2GetUnitX_t*						d2GetUnitX;
extern d2GetUnitY_t*						d2GetUnitY;

extern d2ShopAction_t*						d2ShopAction;

extern d2CloseNPCInteract_t*				d2CloseNPCInteract;
extern d2CloseInteract_t*					d2CloseInteract;

extern d2GetAutomapSize_t*					d2GetAutomapSize;
extern d2NewAutomapCell_t*					d2NewAutomapCell;
extern d2AddAutomapCell_t*					d2AddAutomapCell;
extern d2RevealAutomapRoom_t*				d2RevealAutomapRoom;
extern d2InitAutomapLayer_I_t*				d2InitAutomapLayer_I;

extern d2ClickMap_t*						d2ClickMap;
extern d2LeftClickItem_I_t*					d2LeftClickItem_I;

extern d2GetMouseXOffset_t*					d2GetMouseXOffset;
extern d2GetMouseYOffset_t*					d2GetMouseYOffset;

extern d2PrintGameString_t*					d2PrintGameString;
extern d2PrintPartyString_t*				d2PrintPartyString;

extern d2LeaveParty_t*						d2LeaveParty;

extern d2AcceptTrade_t*						d2AcceptTrade;
extern d2CancelTrade_t*						d2CancelTrade;
extern d2TradeOK_t*							d2TradeOK;

extern d2GetDifficulty_t*					d2GetDifficulty;
extern d2ExitGame_t*						d2ExitGame;
extern d2GetUIVariable_I_t*					d2GetUIVariable_I;
extern d2DrawRectFrame_t*					d2DrawRectFrame;
extern d2PerformGoldDialogAction_t*			d2PerformGoldDialogAction;
extern d2GetPlayerUnit_t*					d2GetPlayerUnit;
extern d2ClearScreen_t*						d2ClearScreen;
extern d2CloseNPCTalk_t*					d2CloseNPCTalk;
extern d2TestPvpFlag_t*						d2TestPvpFlag;

extern d2InitLevel_t*						d2InitLevel;
extern d2UnloadAct_t*						d2UnloadAct;
extern d2LoadAct_t*							d2LoadAct;

extern d2GetLevelText_t*					d2GetLevelText;
extern d2GetObjectText_t*					d2GetObjectText;
extern d2GetItemText_t*						d2GetItemText;

extern d2GetLayer_t*						d2GetLayer;
extern d2GetLevel_t*						d2GetLevel;

extern d2GetStatList_t*						d2GetStatList;
extern d2CopyStatList_t*					d2CopyStatList;
extern d2GetUnitStat_t*						d2GetUnitStat;
extern d2GetUnitState_t*					d2GetUnitState;

extern d2CheckUnitCollision_t*				d2CheckUnitCollision;
extern d2GetRoomFromUnit_t*					d2GetRoomFromUnit;
extern d2GetTargetUnitType_t*				d2GetTargetUnitType;

extern d2GetSkillLevel_t*					d2GetSkillLevel;

extern d2GetItemLevelRequirement_t*			d2GetItemLevelRequirement;

extern d2GetItemPrice_t*					d2GetItemPrice;
extern d2GetRepairCost_t*					d2GetRepairCost;
extern d2GetItemMagicalMods_t*				d2GetItemMagicalMods;
extern d2GetItemFromInventory_t*			d2GetItemFromInventory;
extern d2GetNextItemFromInventory_t*		d2GetNextItemFromInventory;

extern d2GenerateOverheadMessage_t*			d2GenerateOverheadMessage;
extern d2FixOverheadMessage_t*				d2FixOverheadMessage;

extern d2AddRoomData_t*						d2AddRoomData;
extern d2RemoveRoomData_t*					d2RemoveRoomData;

extern d2GetQuestFlag_t*					d2GetQuestFlag;

extern d2MapToAbsScreen_t*					d2MapToAbsScreen;
extern d2AbsScreenToMap_t*					d2AbsScreenToMap;

extern d2CheckWaypoint_t*					d2CheckWaypoint;

extern d2IsTownByLevelNumber_t*				d2IsTownByLevelNumber;
extern d2GetLevelNumberFromRoom_t*			d2GetLevelNumberFromRoom;
extern d2FindRoom1_t*						d2FindRoom1;
extern d2GetItemPalette_t*					d2GetItemPalette;

extern d2SendPacket_t*						d2SendPacket;
extern d2ReceivePacket_t*					d2ReceivePacket;
extern d2ReceivePacket_I_t*					d2ReceivePacket_I;

extern d2DrawRectangle_t*					d2DrawRectangle;
extern d2DrawLine_t*						d2DrawLine;
extern d2DrawAutomapCell2_t*				d2DrawAutomapCell2;
extern d2GetHwnd_t*							d2GetHwnd;
//extern d2GetScreenSize_t*					d2GetScreenSize;

extern d2DoChat_t*							d2DoChat;
extern d2PrintChannelText_t*				d2PrintChannelText;

extern d2InitCellFile_t*					d2InitCellFile;
extern d2DeleteCellFile_t*					d2DeleteCellFile;
extern d2GetLocaleText_t*					d2GetLocaleText;

extern d2SetControlText_t*					d2SetControlText;
extern d2DrawSprites_t*						d2DrawSprites;
extern d2LoadCellFile_t*					d2LoadCellFile;

extern d2TakeScreenshot_t*					d2TakeScreenshot;
extern d2DrawText_t*						d2DrawText;
extern d2GetTextSize_t*						d2GetTextSize;
extern d2SetTextSize_t*						d2SetTextSize;
extern d2GetTextWidthFileNumber_t*			d2GetTextWidthFileNumber;
extern d2DestroyEditBox_t*					d2DestroyEditBox;
extern d2DestroyControl_t*					d2DestroyControl;

extern d2SetEditBoxCallback_t*				d2SetEditBoxCallback;
extern d2SetEditBoxProcedure_t*				d2SetEditBoxProcedure;
extern d2SelectEditBoxText_t*				d2SelectEditBoxText;
extern d2InitMPQ_t*							d2InitMPQ;

extern d2Rand_t*							d2Rand;
extern d2Exit0_t*							d2Exit0;

//  variables
extern DWORD*								d2ScreenSizeX;
extern DWORD*								d2ScreenSizeY;
extern DWORD*								d2CursorHoverX;
extern DWORD*								d2CursorHoverY;
extern DWORD*								d2MouseX;
extern DWORD*								d2MouseY;
extern DWORD*								d2MouseOffsetY;
extern DWORD*								d2MouseOffsetX;
extern DWORD*								d2MouseOffsetZ;

extern DWORD*								d2AutomapOn;
extern int*									d2AutomapMode;
extern POINT*								d2Offset;
extern d2AutomapLayer_t**					d2AutomapLayer;

extern DWORD*								d2MercenaryReviveCost;

extern d2UnitHashTable_t*					d2ServerSideUnitHashTables;
extern d2UnitHashTable_t*					d2ClientSideUnitHashTables;

extern int*									d2ViewportX;
extern int*									d2ViewportY;

extern DWORD*								d2GoldDialogAction;
extern DWORD*								d2GoldDialogAmount;

extern d2NPCMenu_t**						d2NPCMenu;
extern DWORD*								d2NPCMenuAmount;

extern d2InventoryLayout_t**				d2TradeLayout;
extern d2InventoryLayout_t**				d2StashLayout;
extern d2InventoryLayout_t**				d2StoreLayout;
extern d2InventoryLayout_t**				d2CubeLayout;
extern d2InventoryLayout_t**				d2InventoryLayout;
extern d2InventoryLayout_t**				d2MercenaryLayout;

extern DWORD*								d2RegularCursorType;
extern DWORD*								d2ShopCursorType;

extern DWORD*								d2Ping;
extern DWORD*								d2Skip;
extern DWORD*								d2FPS;
extern int*									d2Divisor;

extern DWORD*								d2OverheadTrigger;
extern DWORD*								d2RecentInteractId;
extern DWORD*								d2ItemPriceList;

extern void**								d2TransactionDialog;
extern DWORD*								d2TransactionDialogs;
extern DWORD*								d2TransactionDialogs_2;
extern d2TransactionDialogsInfo_t**			d2TransactionDialogsInfo;

extern d2GameInfo_t**						d2GameInfo;
extern DWORD*								d2WaypointTable;

extern d2UnitAny_t**						d2PlayerUnit;
extern d2UnitAny_t**						d2SelectedInventoryItem;
extern d2RosterUnit_t**						d2PlayerUnitList;

extern DWORD*								d2WeaponSwitch;

extern DWORD*								d2TradeAccepted;
extern DWORD*								d2TradeBlock;
extern DWORD*								d2RecentTradeId;

extern DWORD*								d2ExpansionCharacterFlag;
extern DWORD*								d2MapId;

extern DWORD*								d2AlwaysRun;
extern DWORD*								d2NoPickup;

extern wchar_t**							d2ChatMessage;
extern DWORD*								d2OrificeId;
extern DWORD*								d2CursorItemMode;

extern DWORD*								d2SGPTDataTable;

extern char**								d2ChatBoxMessage;
extern d2Control_t**						d2GameListControl;

extern d2BattleNetData_t**					d2BattleNetData;

extern d2Control_t**						d2FirstControl;
extern d2Control_t**						d2FocusedControl;
extern DWORD**								d2ChatInputBox;

extern char**								d2ClassicKey;
extern char**								d2ExpansionKey;
extern char**								d2KeyOwner;
extern d2WindowHandlerHashTable_t*			d2WindowHandlers;

void initializeInterface(DWORD baseAddress);