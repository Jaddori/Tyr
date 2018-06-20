#pragma once

#include "d2_map.h"

#include <list>
#include <map>

#include "d2_structures.h"
#include "d2_helpers.h"

namespace Mapping
{
	enum ExitType
	{
		Linkage = 1,
		Tile = 2
	};

	struct Exit
	{
	public:
		DWORD		target;
		Point		position;
		ExitType	type;
		DWORD		tileId;

		Exit(Point _location, DWORD _levelId, ExitType _type, DWORD _tileId) :
			target(_levelId), position(_location), type(_type), tileId(_tileId) {}
	};

	class LevelMap;

	typedef std::vector<Exit> ExitArray;
	typedef std::map<DWORD, LevelMap*> LevelMapList;
	typedef std::list<d2Room2_t*> RoomList;
	typedef std::list<d2Level_t*> LevelList;

	static RoomList		roomsAdded;
	static RoomList		roomCache;
	static LevelList	levelCache;

	class LevelMap : public Map
	{
	public:
		enum CollisionFlag
		{
			None				= 0x0000,
			BlockWalk			= 0x0001,
			BlockLineOfSight	= 0x0002,
			Wall				= 0x0004,
			BlockPlayer			= 0x0008,
			AlternateTile		= 0x0010,
			Blank				= 0x0020,
			Missile				= 0x0040,
			Player				= 0x0080,
			NPCLocation			= 0x0100,
			Item				= 0x0200,
			Object				= 0x0400,
			ClosedDoor			= 0x0800,
			NPCCollision		= 0x1000,
			FriendlyNPC			= 0x2000,
			Unknown				= 0x4000,
			DeadBody			= 0x8000, // also portal
			ThickenedWall		= 0xfefe,
			Avoid				= 0xffff
		};

	private:
		static LevelMapList		cache;

		d2Act_t*				act;
		const d2Level_t*		level;
		int						width, height;
		int						x, y;
		Matrix<CollisionFlag>	mapPoints;
		RoomList				addedRooms;

		d2Level_t*				cachedLevel;
		//CRITICAL_SECTION* lock;

		void build(void);

		static inline int getLevelNo(d2Room2_t* room, DWORD tile) { return getTileLevelNo(room, tile); }

		void addRoom(d2Room2_t* const room, RoomList& rooms, d2UnitAny_t* player);
		void addCollisionMap(d2Room1_t* pRoom1);
		void setCollisionData(int x, int y, int value);
		bool isGap(int x, int y, bool abs) const;
		void fillGaps(void);
		void shrinkMap(void);
		void thickenWalls(void);

		bool roomSpaceIsWalkable(d2Room1_t *pRoom1, const Point& point, bool abs) const;
		bool valueIsWalkable(const WORD *value) const;
		bool valueHasFlag(int flag, const WORD *value) const;

		bool edgeIsWalkable(const Point& edgePoint, const Point& offsetPoint, d2Room1_t *pRoom1Adjecent, bool abs) const;

		void findRoomTileExits(d2Room2_t* room, ExitArray& exits) const;
		void findRoomLinkageExits(ExitArray& exits, RoomList& added) const;
		Point getEdgeCenterPoint(const Point &currentPoint, const Point &edgeDirection) const;
		bool exitExists(Point loc, ExitArray& exits) const;
		bool exitExists(DWORD dwLevelNo, ExitArray& exits) const;
		bool isPointInRoom(d2Room2_t* room, const Point& pt) const;
		bool isPointInLevel(d2Level_t* level, const Point& pt) const;
		WORD getCollFromRoom(d2Room2_t* room, const Point& pt) const;

		void drillExits();

		LevelMap(const d2Level_t* level);
		~LevelMap(void);

	public:
		static LevelMap* getMap(d2Level_t* level);
		static void clearCache(void);
		void dump(const char* file, const PointList& points) const;
		void cleanUp(void) const;
		Point absToRelative(const Point& point) const;
		Point relativeToAbs(const Point& point) const;

		inline int getWidth(void) const { return width; }
		inline int getHeight(void) const { return height; }
		inline int getPosX(void) const { return x; }
		inline int getPosY(void) const { return y; }
		/* If these are backwards, it's not me. */
		inline int getMaxX(void) const { return x + height; }
		inline int getMaxY(void) const { return y + width; }

		int getMapData(const Point& point, bool abs = true) const;
		bool isValidPoint(const Point& point, bool abs = true) const;

		void getExits(ExitArray&) const;

		bool spaceHasFlag(int flag, const Point& point, bool abs = true) const;
		bool pathHasFlag(int flag, const PointList& points, bool abs = true) const;

		bool spaceIsWalkable(const Point& point, bool abs = true) const;
		bool spaceIsWalkableForExit(const Point& point, bool abs = true) const;
		bool spaceHasLineOfSight(const Point& point, bool abs = true) const;
		bool spaceIsInvalid(const Point& point, bool abs = true) const;
		bool spaceIsThickenedWall(const Point& point, bool abs = true) const;

		bool pathIsWalkable(const PointList& points, bool abs = true) const;
		bool pathHasLineOfSight(const PointList& points, bool abs = true) const;
	};

}
