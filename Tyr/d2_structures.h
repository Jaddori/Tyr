#pragma once

#include <Windows.h>

struct d2UnitAny_t;
struct d2Room1_t;
struct d2Room2_t;
struct d2Level_t;
struct d2Act_t;
struct d2ActMisc_t;
struct d2RosterUnit_t;
struct d2OverheadMessage_t;
struct d2Skill_t;

struct d2SplitText_t
{
	wchar_t* text;
	d2SplitText_t* next;
};

struct d2InventoryInfo_t
{
	int location;
	int maxCellsX;
	int maxCellsY;
};

struct d2GameInfo_t
{
	BYTE _1[31];
	char gameName[24];
	char gameServerIp[86];
	char accountName[48];
	char characterName[24];
	char realmName[24];
	BYTE _2[344];
	char gamePassword[24];
};

struct d2AutomapCell_t
{
	DWORD saved;
	WORD cellNumber;
	WORD pixelX;
	WORD pixelY;
	WORD weight;
	d2AutomapCell_t* more;
	d2AutomapCell_t* less;
};

struct d2GfxCell_t
{
	DWORD flags;
	DWORD width;
	DWORD height;
	DWORD offsetX;
	DWORD offsetY;
	DWORD _2;
	DWORD parent;
	DWORD length;
	BYTE columns;
};

struct d2UnitInteraction_t
{
	DWORD moveType;
	d2UnitAny_t* playerUnit;
	d2UnitAny_t* targetUnit;
	DWORD targetX;
	DWORD targetY;
	DWORD _1;
	DWORD _2;
	d2Skill_t* skill;
};

struct d2CellFile_t
{
	DWORD version;
	struct 
	{
		WORD flags;
		BYTE lastColumn;
		BYTE tabNumber:1;
	};
	DWORD format;
	DWORD termination;
	DWORD directionCount;
	DWORD cellCount;
	d2GfxCell_t* cells[255];
};

struct d2CellContext_t
{
	DWORD _1[13];
	d2CellFile_t* cellFile;
	DWORD _2[4];
};

struct d2AutomapLayer_t
{
	DWORD layerNumber;
	DWORD saved;
	d2AutomapCell_t* floors;
	d2AutomapCell_t* walls;
	d2AutomapCell_t* objects;
	d2AutomapCell_t* extras;
	d2AutomapCell_t* nextLayer;
};

struct d2AutomapLayer2_t
{
	DWORD _1[2];
	DWORD layerNumber;
};

struct d2LevelText_t
{
	DWORD levelNumber;
	DWORD _1[60];
	BYTE _2;
	char name[40];
	char entranceText[40];
	char levelDescription[41];
	wchar_t namew[40];
	wchar_t entranceTextw[40];
	BYTE objectGroup[8];
	BYTE objectProbe[8];
};

struct d2ControlText_t
{
	wchar_t* textw[5];
	DWORD color;
	DWORD align;
	d2ControlText_t* next;
};

struct d2Control_t
{
	DWORD type;
	DWORD* _1;
	DWORD disabled;
	DWORD x;
	DWORD y;
	DWORD width;
	DWORD height;
	DWORD* _2;
	DWORD _3;
	DWORD *_4;
	DWORD *_5;
	DWORD _6;
	DWORD *_7;
	DWORD *_8;
	DWORD _9;
	d2Control_t* next;
	DWORD _10;
	DWORD unknownState;
	d2ControlText_t* firstText;
	d2ControlText_t* lastText;
	d2ControlText_t* selectedText;
	DWORD selectEnd;
	DWORD selectStart;
	union
	{
		struct // Textboxes
		{
			wchar_t boxText[256];
			DWORD cursorPosition;
			DWORD isCloaked;
		};
		struct // Buttons
		{
			DWORD _12[2];
			wchar_t buttonText[256];
		};
	};
};

#pragma pack(push)
#pragma pack(1)

struct d2BattleNetData_t
{
	DWORD id;
	DWORD id2;
	BYTE _1[16];
	DWORD id3;
	WORD _2;
	BYTE _3;
	char gameName[22];
	WORD _4;
	char gameIp[13];
	BYTE _5[66];
	DWORD id4;
	char accountName[48];
	char playerName[24];
	char realmName[8];
	BYTE _6[273];
	BYTE characterClass;
	BYTE characterFlags;
	BYTE maxDifference;
	BYTE _7[31];
	BYTE createdGameDifficulty;
	void* _8;
	BYTE _9[21];
	WORD _12;
	BYTE _13;
	char realmName2[24];
	char gamePassword[24];
	char gameDescription[260];
	char channelName[32];
	BYTE _14[64];
	BYTE characterLevel;
	BYTE ladderFlag;
	DWORD passwordHash;
	BYTE passwordLength;
};

struct d2RoomTile_t
{
	d2Room2_t* room2;
	d2RoomTile_t* next;
	DWORD _2[2];
	DWORD* number;
};

struct d2RosterUnit_t
{
	char name[16];
	DWORD unitId;
	DWORD partyLife;
	DWORD _1;
	DWORD classId;
	WORD level;
	WORD partyId;
	DWORD levelId;
	DWORD x;
	DWORD y;
	DWORD partyFlags;
	BYTE* _2;
	DWORD _3[11];
	WORD _4;
	char name2[16];
	WORD _5;
	DWORD _6;
	d2RosterUnit_t* next;
};

struct d2QuestInfo_t
{
	void* buffer;
	DWORD _1;
};

struct d2Waypoint_t
{
	BYTE flags;
};

struct d2PlayerData_t
{
	char name[16];
	d2QuestInfo_t* normalQuest;
	d2QuestInfo_t* nightmareQuest;
	d2QuestInfo_t* hellQuest;
	d2Waypoint_t* normalWaypoint;
	d2Waypoint_t* nightmareWaypoint;
	d2Waypoint_t* hellWaypoint;
};

struct d2CollisionMap_t
{
	DWORD gameX;
	DWORD gameY;
	DWORD gameWidth;
	DWORD gameHeight;
	DWORD roomX;
	DWORD roomY;
	DWORD roomWidth;
	DWORD roomHeight;
	WORD* mapStart;
	WORD* mapEnd;
};

struct d2PresetUnit_t
{
	DWORD _1;
	DWORD textFileNumber;
	DWORD x;
	d2PresetUnit_t* next;
	DWORD _2;
	DWORD type;
	DWORD y;
};

struct d2Level_t
{
	DWORD _1[4];
	d2Room2_t* room2First;
	DWORD _2[2];
	DWORD x;
	DWORD y;
	DWORD width;
	DWORD height;
	DWORD _3[96];
	d2Level_t* next;
	DWORD _4;
	d2ActMisc_t* misc;
	DWORD _5[6];
	DWORD levelNumber;
	DWORD _6[3];
	union
	{
		DWORD roomCenterX[9];
		DWORD warpX[9];
	};
	union
	{
		DWORD roomCenterY[9];
		DWORD warpY[9];
	};
	DWORD roomEntries;
};

struct d2Room2_t
{
	DWORD _1[2];
	d2Room2_t** room2Near;
	DWORD _2[5];
	struct
	{
		DWORD roomNumber;
		DWORD _1;
		DWORD* subNumber;
	} *type2Info_t;
	d2Room2_t* next;
	DWORD roomFlags;
	DWORD roomsNear;
	d2Room1_t* room1;
	DWORD x;
	DWORD y;
	DWORD width;
	DWORD height;
	DWORD _3;
	DWORD presetType;
	d2RoomTile_t* roomTiles;
	DWORD _4[2];
	d2Level_t* level;
	d2PresetUnit_t* preset;
};

#pragma pack(pop)

struct d2Room1_t
{
	d2Room1_t** roomsNear;
	DWORD _1[3];
	d2Room2_t* room2;
	DWORD _2[3];
	d2CollisionMap_t* collision;
	DWORD roomsNearCount;
	DWORD _3[9];
	DWORD x;
	DWORD y;
	DWORD width;
	DWORD height;
	DWORD _4[6];
	d2UnitAny_t* unitFirst;
	DWORD _5;
	d2Room1_t* next;
};

struct d2ActMisc_t
{
	DWORD _1[37];
	DWORD staffTombLevel;
	DWORD _2[245];
	d2Act_t* act;
	DWORD _3[3];
	d2Level_t* levelFirst;
};

struct d2Act_t
{
	DWORD _1[3];
	DWORD mapSeed;
	d2Room1_t* room1;
	DWORD act;
	DWORD _2[12];
	d2ActMisc_t* misc;
};

struct d2Path_t
{
	WORD xoffset;
	WORD x;
	WORD yoffset;
	WORD y;
	DWORD _1[2];
	WORD xtarget;
	WORD ytarget;
	DWORD _2[2];
	d2Room1_t* room1;
	d2Room1_t* room1Unknown;
	DWORD _3[3];
	d2UnitAny_t* unit;
	DWORD flags;
	DWORD _4;
	DWORD pathType;
	DWORD prevPathType;
	DWORD unitSize;
	DWORD _5[4];
	d2UnitAny_t* targetUnit;
	DWORD targetType;
	DWORD targetId;
	BYTE direction;
};

struct d2ItemPath_t
{
	DWORD _1[3];
	DWORD x;
	DWORD y;
};

struct d2Stat_t
{
	WORD subIndex;
	WORD statIndex;
	DWORD statValue;
};

struct d2StatVector_t
{
	d2Stat_t* stats;
	WORD count;
	WORD size;
};

struct d2StatList_t
{
	DWORD _1;
	d2UnitAny_t* unit;
	DWORD unitType;
	DWORD unitId;
	DWORD flags;
	DWORD _2[4];
	d2StatVector_t statVector;
	d2StatList_t* prevLink;
	DWORD _3;
	d2StatList_t* prev;
	DWORD _4;
	d2StatList_t* next;
	d2StatList_t* setList;
	DWORD _5;
	d2StatVector_t setStatVector;
	DWORD _6[2];
	DWORD stateBits[6];
};

struct d2Inventory_t
{
	DWORD signature;
	BYTE* game1C;
	d2UnitAny_t* owner;
	d2UnitAny_t* firstItem;
	d2UnitAny_t* lastItem;
	DWORD _1[2];
	DWORD leftItemUid;
	d2UnitAny_t* cursorItem;
	DWORD ownerId;
	DWORD itemCount;
};

struct d2Light_t
{
	DWORD _1[3];
	DWORD type;
	DWORD _2[7];
	DWORD staticValid;
	int* staticMap;
};

struct d2SkillInfo_t
{
	WORD skillId;
};

struct d2Skill_t
{
	d2SkillInfo_t* info;
	d2Skill_t* next;
	DWORD _1[8];
	DWORD skillLevel;
	DWORD _2[2];
	DWORD itemId;
	DWORD chargesLeft;
	DWORD isCharge;
};

struct d2Info_t
{
	BYTE* game1C;
	d2Skill_t* firstSkill;
	d2Skill_t* leftSkill;
	d2Skill_t* rightSkill;
};

struct d2ItemData_t
{
	DWORD quality;
	DWORD seed[2];
	DWORD itemFlags; // 1 = Owned by player, 0xFFFFFFFF = Not owned
	DWORD fingerPrint; // Initial seed
	DWORD _1;
	DWORD flags;
	DWORD _2[2];
	DWORD actionStamp;
	DWORD fileIndex;
	DWORD itemLevel;
	WORD itemFormat;
	WORD rarePrefix;
	WORD rareSuffix;
	WORD autoPrefix;
	WORD magicPrefix[3];
	WORD magicSuffix[3];
	BYTE bodyLocation;
	BYTE itemLocation;
	WORD _4;
	BYTE earLevel;
	BYTE inverseGfxIdx;
	char playerName[16]; // Personalized / ear name
	d2Inventory_t* ownerInventory;
	DWORD _10;
	d2UnitAny_t* nextInventoryItem; // next item in socketed item if OwnerInventory is set
	BYTE gameLocation;
	BYTE nodePage;
	WORD _12;
	WORD _13[12];
	d2UnitAny_t* owner;
};

struct d2ItemText_t
{
	wchar_t namew[64];
	union
	{
		DWORD codeId;
		char code[4];
	};
	BYTE _2[112];
	WORD localTextNumber;
	BYTE _3[25];
	BYTE width;
	BYTE height;
	BYTE _4[13];
	BYTE type;
	BYTE _5[13];
	BYTE quest;
};

struct d2MonsterText_t
{
	BYTE _1[6];
	WORD localTextNumber;
	WORD flag;
	WORD _2;
	union
	{
		DWORD flag2;
		struct
		{
			BYTE flag2a;
			BYTE flag2b;
			BYTE flag3c[2];
		};
	};
	BYTE _3[34];
	WORD velocity;
	BYTE _4[82];
	WORD tcs[3][4];
	BYTE _5[82];
	wchar_t descriptor[60];
	BYTE _6[416];
};

struct d2MonsterData_t
{
	BYTE _1[22];
	struct
	{
		BYTE unknown:1;
		BYTE normal:1;
		BYTE champion:1;
		BYTE boss:1;
		BYTE minion:1;
	};
	BYTE _2[5];
	BYTE enchants[9];
	WORD uniqueNumber;
	DWORD _5;
	struct
	{
		wchar_t namew[28];
	};
};

struct d2ObjectText_t
{
	char name[64];
	wchar_t namew[64];
	BYTE _1[4];
	BYTE selectable;
	BYTE _2[135];
	BYTE orientation;
	BYTE _3[25];
	BYTE subClass;
	BYTE _4[17];
	BYTE parm0;
	BYTE _5[57];
	BYTE populateFunction;
	BYTE operateFunction;
	BYTE _6[8];
	DWORD automap;
};

struct d2ObjectData_t
{
	d2ObjectText_t* text;
	union
	{
		BYTE type;
		struct
		{
			BYTE _1:7;
			BYTE chestLocked:1;
		};
	};
	DWORD _2[8];
	char owner[16];
};

struct d2ObjectPath_t
{
	d2Room1_t* room1;
	DWORD _1[2];
	DWORD x;
	DWORD y;
	// INCOMPLETE
};

struct d2UnitAny_t
{
	DWORD type;
	DWORD textFileNumber;
	DWORD _1;
	DWORD unitId;
	DWORD mode;
	union
	{
		d2PlayerData_t* playerData;
		d2ItemData_t* itemData;
		d2MonsterData_t* monsterData;
		d2ObjectData_t* objectData;
	};
	DWORD actId;
	d2Act_t* act;
	DWORD seed[2];
	DWORD _2;
	union
	{
		d2Path_t* path;
		d2ItemPath_t* itemPath;
		d2ObjectPath_t* objectPath;
	};
	DWORD _3[5];
	DWORD gfxFrame;
	DWORD frameRemain;
	WORD frameRate;
	WORD _4;
	BYTE* gfxUnknown;
	DWORD* gfxInfo;
	DWORD _5;
	d2StatList_t* stats;
	d2Inventory_t* inventory;
	d2Light_t* light;
	DWORD startLightRadius;
	WORD pl2ShiftIndex;
	WORD updateType;
	d2UnitAny_t* updateUnit;
	DWORD* questRecord;
	DWORD sparklyChest;
	DWORD* timerArguments;
	DWORD soundSync;
	DWORD _6[2];
	WORD x;
	WORD y;
	DWORD _7;
	DWORD ownerType;
	DWORD ownerId;
	DWORD _8[2];
	d2OverheadMessage_t* overheadMessage;
	d2Info_t* info;
	DWORD _9[6];
	DWORD flags;
	DWORD flags2;
	DWORD _10[5];
	d2UnitAny_t* changedNext;
	d2UnitAny_t* listNext;
	d2UnitAny_t* roomNext;
};

struct d2UnitHashTable_t
{
	d2UnitAny_t* table[128];
};

struct d2WardenClientRegion_t
{
	DWORD allocSize;
	DWORD offsetFunction;
	DWORD offsetRelocationAddressTable;
	DWORD relocationCount;
	DWORD offsetWardenSetup;
	DWORD _2[2];
	DWORD offsetImportAddressTable;
	DWORD importDllCount;
	DWORD sectionCount;
};

struct d2SMemBlock_t
{
	DWORD _1[6];
	DWORD size;
	DWORD _2[31];
	BYTE data[1];
};

struct d2WardenClient_t
{
	d2WardenClientRegion_t* wardenRegion;
	DWORD size;
	DWORD moduleCount;
	DWORD parameters;
	DWORD setupWardenFunction;
};

struct d2WardenIATInfo_t
{
	DWORD offsetModuleName;
	DWORD offsetImportTable;
};

#pragma pack(push)
#pragma pack(1)

struct d2NPCMenu_t
{
	DWORD classId;
	DWORD entryAmount;
	WORD id1;
	WORD id2;
	WORD id3;
	WORD id4;
	WORD _1;
	DWORD func1;
	DWORD func2;
	DWORD func3;
	DWORD func4;
	BYTE _2[5];
};

struct d2OverheadMessage_t
{
	DWORD _1;
	DWORD trigger;
	DWORD _2[2];
	char message[232];
};

#pragma pack(pop)

struct d2d2Message_t
{
	HWND hwnd;
	char buffer[256];
};

struct d2InventoryLayout_t
{
	BYTE slotWidth;
	BYTE slotHeight;
	BYTE _1;
	BYTE _2;
	DWORD left;
	DWORD right;
	DWORD top;
	DWORD bottom;
	BYTE slotPixelWidth;
	BYTE slotPixelHeight;
};

struct d2MPQTable_t;

struct d2sqgpDataTable_t
{
	d2MPQTable_t*	playerClass;
	DWORD			playerClassRecords;
	d2MPQTable_t*	bodyLocations;
	DWORD			bodyLocationRecords;
	d2MPQTable_t*	storePage;
	DWORD			storePageRecords;
	d2MPQTable_t*	elementTypes;
};

struct d2MessageHandlerList_t
{
	DWORD message;
	DWORD _1;
	DWORD (__stdcall *handler)(void*);
	d2MessageHandlerList_t* next;
};

struct d2MessageHandlerHashTable_t
{
	d2MessageHandlerList_t** table;
	DWORD length;
};

struct d2WindowHandlerList_t
{
	DWORD _1;
	HWND hwnd;
	DWORD _2;
	d2MessageHandlerHashTable_t* messageHandlers;
	d2WindowHandlerList_t* next;
};

struct d2WindowHandlerHashTable_t
{
	d2WindowHandlerList_t** table;
	DWORD length;
};

struct d2TransactionDialogsLine_t
{
	wchar_t textw[120];
	DWORD _1[6];
	void (__stdcall *handler)();
	DWORD maybeSelectable;
};

struct d2TransactionDialogsInfo_t
{
	DWORD _1[20];
	DWORD numLines;
	DWORD _2[5];
	d2TransactionDialogsLine_t dialogLines[10];
	void* _3;
};