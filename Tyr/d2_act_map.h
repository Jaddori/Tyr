#pragma once

#include "d2_map.h"

#include <list>
#include <map>
#include <set>

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
		DWORD target;
		Point position;
		ExitType type;
		DWORD tileId;

		Exit(Point _location, DWORD _levelId, ExitType _type, DWORD _tileId) :
			target(_levelId), position(_location), type(_type), tileId(_tileId) {}
	};

	class ActMap;

	typedef std::vector<Exit>				ExitArray;
	typedef std::map<DWORD, ActMap*>		ActMapList;
	typedef std::list<d2Room2_t*>			RoomList;
	typedef std::list<d2Level_t*>			LevelList;
	typedef std::set<Point>					PointSet;
	typedef std::map<d2Room2_t*, PointSet>	RoomPointSet;

	static RoomPointSet avoidRoomPointSet;
	static RoomList		roomsAdded;
	static RoomList		roomCache;
	static LevelList	levelCache;


	class ActMap : public Map
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
			//ThickenedWall		= 0xfefe,
			Avoid				= 0xffff,
			Special				= 0xf000
		};

	private:
		static DWORD			previousLevelNo;
		static ActMapList		cache;

		d2Act_t*				act;
		const d2Level_t*		level;
		int						width, height;
		int						x, y;
		Matrix<CollisionFlag>	mapPoints;
		RoomList				addedRooms;

		//CRITICAL_SECTION* lock;

		void build(void);

		static inline int getLevelNo(d2Room2_t* room, DWORD tile) { return getTileLevelNo(room, tile); }

		void shrinkMap(void);

		bool edgeIsWalkable(const Point& edgePoint, const Point& offsetPoint, bool abs) const;

		void findRoomTileExits(d2Room2_t* room, ExitArray& exits) const;
		void findRoomLinkageExits(ExitArray& exits) const;
		Point getEdgeCenterPoint(const Point &currentPoint, const Point &edgeDirection) const;
		bool exitExists(Point loc, ExitArray& exits) const;
		bool exitExists(DWORD dwLevelNo, ExitArray& exits) const;
		bool isPointInRoom(const d2Room2_t* room, const Point& pt) const;
		bool isPointInLevel(const d2Level_t* level, const Point& pt) const;

		WORD getAvoidLayerPoint(d2Room2_t* room, const Point& pt) const;

		WORD getCollFromRoom(d2Room2_t* room, const Point& pt) const;

		ActMap( const d2Level_t* level );
		~ActMap();

	public:
		std::set<Point>			pathingPointList;

		void					cleanUp(void) const;
		void					allowCritSpace(void) const;
		//CriticalRoom* actCrit;	
		static ActMap*			getMap(d2Level_t* level);
		static void				clearCache(void);
		void					dump(const char* file, const PointList& points) const;
		void					dumpLevel(const char* file) const;

		Point					absToRelative(const Point& point) const;
		Point					relativeToAbs(const Point& point) const;

		inline const d2Level_t* getLevel(void) const { return level; }
		inline int				getWidth(void) const { return width; }
		inline int				getHeight(void) const { return height; }
		inline int				getPosX(void) const { return x; }
		inline int				getPosY(void) const { return y; }
		/* If these are backwards, it's not me. */
		inline int				getMaxX(void) const { return x + height; }
		inline int				getMaxY(void) const { return y + width; }

		int						getMapData(const Point& point, bool abs = true) const;
		bool					isValidPoint(const Point& point, bool abs = true) const;

		void					getExits(ExitArray&) const;

		bool					spaceHasFlag(int flag, const Point& point, bool abs = true) const;
		bool					oneSpaceHasFlag(int flag, const Point& point, bool abs = true) const;
		bool					pathHasFlag(int flag, const PointList& points, bool abs = true) const;

		bool					spaceIsWalkable(const Point& point, bool abs = true) const;
		bool					spaceIsWalkableForExit(const Point& point, bool abs = true) const;
		bool					spaceHasLineOfSight(const Point& point, bool abs = true) const;
		bool					spaceIsInvalid(const Point& point, bool abs = true) const;
		bool					spaceIsThickenedWall(const Point& point, bool abs = true) const;

		bool					pathIsWalkable(const PointList& points, bool abs = true) const;
		bool					pathHasLineOfSight(const PointList& points, bool abs = true) const;
	};
}