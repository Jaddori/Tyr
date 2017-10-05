#pragma once

#include <Windows.h>

struct UnitAny;
struct Room1;
struct Room2;
struct Level;
struct Act;
struct ActMisc;
struct RosterUnit;
struct OverheadMessage;
struct Skill;

struct SplitText
{
	wchar_t* text;
	SplitText* next;
};

struct InventoryInfo
{
	int location;
	int maxCellsX;
	int maxCellsY;
};

struct GameInfo
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

struct AutomapCell
{
	DWORD saved;
	WORD cellNumber;
	WORD pixelX;
	WORD pixelY;
	WORD weight;
	AutomapCell* less;
	AutomapCell* more;
};

struct GfxCell
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

struct UnitInteraction
{
	DWORD moveType;
	UnitAny* playerUnit;
	UnitAny* targetUnit;
	DWORD targetX;
	DWORD targetY;
	DWORD _1;
	DWORD _2;
	Skill* skill;
};

struct CellFile
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
	GfxCell* cells[255];
};

struct CellContext
{
	DWORD _1[13];
	CellFile* cellFile;
	DWORD _2[4];
};

struct AutomapLayer
{
	DWORD layerNumber;
	DWORD saved;
	AutomapCell* floors;
	AutomapCell* walls;
	AutomapCell* objects;
	AutomapCell* extras;
	AutomapCell* nextLayer;
};

struct AutomapLayer2
{
	DWORD _1[2];
	DWORD layerNumber;
};

struct LevelText
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

struct ControlText
{
	wchar_t* textw[5];
	DWORD color;
	DWORD align;
	ControlText* next;
};

struct Control
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
	Control* next;
	DWORD _10;
	DWORD unknownState;
	ControlText* firstText;
	ControlText* lastText;
	ControlText* selectedText;
	DWORD selectEnd;
	DWORD selectStart;
	union
	{
		struct // Textboxes
		{
			wchar_t textw[256];
			DWORD cursorPosition;
			DWORD isCloaked;
		};
		struct // Buttons
		{
			DWORD _12[2];
			wchar_t textw[256];
		};
	};
};

#pragma pack(push)
#pragma pack(1)

struct BattleNetData
{
	DWORD id;
	DWORD id2;
	BYTE _1[0x10];
	DWORD id3;
	WORD _2;
	BYTE _3;
	char gameName[0x16];
	WORD _4;
	char gameIp[0x10];
	BYTE _5[0x42];
	DWORD id4;
	char accountName[0x30];
	char playerName[0x18];
	char realmName[0x8];
	BYTE _6[0x111];
	BYTE characterClass;
	BYTE characterFlags;
	BYTE maxDifference;
	BYTE _7[0x1F];
	BYTE createdGameDifficulty;
	void* _8;
	BYTE _9[0x15];
	WORD _12;
	BYTE _13;
	char realmName2[0x18];
	char gamePassword[0x18];
	char gameDescription[0x104];
	char channelName[0x20];
	BYTE _14[0x40];
	BYTE characterLevel;
	BYTE ladderFlag;
	DWORD passwordHash;
	BYTE passwordLength;
};

struct RoomTile
{
	Room2* room2;
	RoomTile* next;
	DWORD _2[2];
	DWORD* number;
};

struct RosterUnit
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
	RosterUnit* next;
};

struct QuestInfo
{
	void* buffer;
	DWORD _1;
};

struct Waypoint
{
	BYTE flags;
};

struct PlayerData
{
	char name[0x10];
	QuestInfo* normalQuest;
	QuestInfo* nightmareQuest;
	QuestInfo* hellQuest;
	Waypoint* normalWaypoint;
	Waypoint* nightmareWaypoint;
	Waypoint* hellWaypoint;
};

struct CollisionMap
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

struct PresetUnit
{
	DWORD _1;
	DWORD textFileNumber;
	DWORD x;
	PresetUnit* next;
	DWORD _2;
	DWORD type;
	DWORD y;
};

struct Level
{
	DWORD _1[4];
	Room2* room2First;
	DWORD _2[2];
	DWORD x;
	DWORD y;
	DWORD width;
	DWORD height;
	DWORD _3[96];
	Level* next;
	DWORD _4;
	ActMisc* misc;
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

struct Room2
{
	DWORD _1[2];
	Room2** room2Near;
	DWORD _2[5];
	struct
	{
		DWORD roomNumber;
		DWORD _1;
		DWORD* subNumber;
	} *type2Info;
	Room2* next;
	DWORD roomFlags;
	DWORD roomsNear;
	Room1* room1;
	DWORD x;
	DWORD y;
	DWORD width;
	DWORD height;
	DWORD _3;
	DWORD presetType;
	RoomTile* roomTiles;
	DWORD _4[2];
	Level* level;
	PresetUnit* preset;
};

#pragma pack(pop)

struct Room1
{
	Room1** roomsNear;
	DWORD _1[3];
	Room2* room2;
	DWORD _2[3];
	CollisionMap* collision;
	DWORD roomsNear;
	DWORD _3[9];
	DWORD x;
	DWORD y;
	DWORD width;
	DWORD height;
	DWORD _4[6];
	UnitAny* unitFirst;
	DWORD _5;
	Room1* next;
};

struct ActMisc
{
	DWORD _1[37];
	DWORD staffTombLevel;
	DWORD _2[245];
	Act* act;
	DWORD _3[3];
	Level* levelFirst;
};

struct Act
{
	DWORD _1[3];
	DWORD mapSeed;
	Room1* room1;
	DWORD act;
	DWORD _2[12];
	ActMisc* misc;
};

struct Path
{
	WORD xoffset;
	WORD x;
	WORD yoffset;
	WORD y;
	DWORD _1[2];
	WORD xtarget;
	WORD ytarget;
	DWORD _2[2];
	Room1* room1;
	Room1* room1Unknown;
	DWORD _3[3];
	UnitAny* unit;
	DWORD flags;
	DWORD _4;
	DWORD pathType;
	DWORD prevPathType;
	DWORD unitSize;
	DWORD _5[4];
	UnitAny* targetUnit;
	DWORD targetType;
	DWORD targetId;
	BYTE direction;
};

struct ItemPath
{
	DWORD _1[3];
	DWORD x;
	DWORD y;
};

struct Stat
{
	WORD subIndex;
	WORD statIndex;
	DWORD statValue;
};

struct StatVector
{
	Stat* stats;
	WORD count;
	WORD size;
};

struct StatList
{
	DWORD _1;
	UnitAny* unit;
	DWORD unitType;
	DWORD unitId;
	DWORD flags;
	DWORD _2[4];
	StatVector statVector;
	StatList* prevLink;
	DWORD _3;
	StatList* prev;
	DWORD _4;
	StatList* next;
	StatList* setList;
	DWORD _5;
	StatVector setStatVector;
	DWORD _6[2];
	DWORD stateBits[6];
};

struct Inventory
{
	DWORD signature;
	BYTE* game1C;
	UnitAny* owner;
	UnitAny* firstItem;
	UnitAny* lastItem;
	DWORD _1[2];
	DWORD leftItemUid;
	UnitAny* cursorItem;
	DWORD ownerId;
	DWORD itemCount;
};

struct Light
{
	DWORD _1[3];
	DWORD type;
	DWORD _2[7];
	DWORD staticValid;
	int* staticMap;
};

struct SkillInfo
{
	WORD skillId;
};

struct Skill
{
	SkillInfo* info;
	Skill* next;
	DWORD _1[8];
	DWORD skillLevel;
	DWORD _2[2];
	DWORD itemId;
	DWORD chargesLeft;
	DWORD isCharge;
};

struct Info
{
	BYTE* game1C;
	Skill* firstSkill;
	Skill* leftSkill;
	Skill* rightSkill;
};

struct ItemData
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
	Inventory* ownerInventory;
	DWORD _10;
	UnitAny* nextInventoryItem; // next item in socketed item if OwnerInventory is set
	BYTE gameLocation;
	BYTE nodePage;
	WORD _12;
	WORD _13[12];
	UnitAny* owner;
};

struct ItemText
{
	wchar_t namew[0x40];
	union
	{
		DWORD code;
		char code[4];
	};
	BYTE _2[0x70];
	WORD localTextNumber;
	BYTE _3[0x19];
	BYTE width;
	BYTE height;
	BYTE _4[13];
	BYTE type;
	BYTE _5[0xD];
	BYTE quest;
};

struct MonsterText
{
	BYTE _1[0x6];
	WORD localTextNumber;
	WORD flag;
	WORD _1;
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
	BYTE _2[0x22];
	WORD velocity;
	BYTE _3[0x52];
	WORD tcs[3][4];
	BYTE _4[0x52];
	wchar_t descriptor[0x3c];
	BYTE _5[0x1a0];
};

struct MonsterData
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

struct ObjectText
{
	char name[0x40];
	wchar_t namew[0x40];
	BYTE _1[4];
	BYTE selectable;
	BYTE _2[0x87];
	BYTE orientation;
	BYTE _3[0x19];
	BYTE subClass;
	BYTE _4[0x11];
	BYTE parm0;
	BYTE _4[0x39];
	BYTE populateFunction;
	BYTE operateFunction;
	BYTE _5[8];
	DWORD automap;
};

struct ObjectData
{
	ObjectText* text;
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
	char owner[0x10];
};

struct ObjectPath
{
	Room1* room1;
	DWORD _1[2];
	DWORD x;
	DWORD y;
	// INCOMPLETE
};

struct UnitAny
{
	DWORD type;
	DWORD textFileNumber;
	DWORD _1;
	DWORD unitId;
	DWORD mode;
	union
	{
		PlayerData* playerData;
		ItemData* itemData;
		MonsterData* monsterData;
		ObjectData* objectData;
	};
	DWORD actId;
	Act* act;
	DWORD seed[2];
	DWORD _2;
	union
	{
		Path* path;
		ItemPath* itemPath;
		ObjectPath* objectPath;
	};
	DWORD _3[5];
	DWORD gfxFrame;
	DWORD frameRemain;
	WORD frameRate;
	WORD _4;
	BYTE* gfxUnknown;
	DWORD* gfxInfo;
	DWORD _5;
	StatList* stats;
	Inventory* inventory;
	Light* light;
	DWORD startLightRadius;
	WORD pl2ShiftIndex;
	WORD updateType;
	UnitAny* updateUnit;
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
	OverheadMessage* overheadMessage;
	Info* info;
	DWORD _9[6];
	DWORD flags;
	DWORD flags2;
	DWORD _10[5];
	UnitAny* changedNext;
	UnitAny* listNext;
	UnitAny* roomNext;
};

struct UnitHashTable
{
	UnitAny* table[128];
};

struct WardenClientRegion
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

struct SMemBlock
{
	DWORD _1[6];
	DWORD size;
	DWORD _2[31];
	BYTE data[1];
};

struct WardenClient
{
	WardenClientRegion* wardenRegion;
	DWORD size;
	DWORD moduleCount;
	DWORD parameters;
	DWORD setupWardenFunction;
};

struct WardenIATInfo
{
	DWORD offsetModuleName;
	DWORD offsetImportTable;
};

#pragma pack(push)
#pragma pack(1)

struct NPCMenu
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

struct OverheadMessage
{
	DWORD _1;
	DWORD trigger;
	DWORD _2[2];
	char message[232];
};

#pragma pack(pop)

struct d2Message
{
	HWND hwnd;
	char buffer[256];
};

struct InventoryLayout
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

struct MPQTable;

struct sqgpDataTable
{
	MPQTable*	playerClass;
	DWORD		playerClassRecords;
	MPQTable*	bodyLocations;
	DWORD		bodyLocationRecords;
	MPQTable*	storePage;
	DWORD		storePageRecords;
	MPQTable*	elementTypes;
};

struct MessageHandlerList
{
	DWORD message;
	DWORD _1;
	DWORD (__stdcall *handler)(void*);
	MessageHandlerList* next;
};

struct MessageHandlerHashTable
{
	MessageHandlerList** table;
	DWORD length;
};

struct WindowHandlerHashTable
{
	WindowHandlerList** table;
	DWORD length;
};

struct WindowHandlerList
{
	DWORD _1;
	HWND hwnd;
	DWORD _2;
	MessageHandlerHashTable* messageHandlers;
	WindowHandlerList* next;
};

struct TransactionDialogsLine
{
	wchar_t textw[120];
	DWORD _1[6];
	void (__stdcall *handler)();
	DWORD maybeSelectable;
};

struct TransactionDialogsInfo
{
	DWORD _1[0x14];
	DWORD numLines;
	DWORD _2[0x5];
	TransactionDialogsLine dialogLines[10];
	void* _3;
};