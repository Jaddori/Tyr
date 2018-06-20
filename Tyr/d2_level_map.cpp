#include <algorithm>
#include <assert.h>
#include "d2_level_map.h"

namespace Mapping
{
	LevelMapList LevelMap::cache = LevelMapList();

	//LevelMap* LevelMap::GetMap(Level* level) // commit easier than fix error
	//{
	//	if(cache.count(level->dwLevelNo) > 0)
	//		return cache[level->dwLevelNo];
	//	LevelMap* map = new LevelMap(level);
	//	cache[level->dwLevelNo] = map;
	//	return map;
	//}
	void LevelMap::cleanUp() const
	{
		//Dummy Sub here because act map has it
	}

	void LevelMap::clearCache()
	{
		LevelMapList::iterator end = cache.end();
		for(LevelMapList::iterator it = cache.begin(); it != end; it++)
			delete it->second;

		cache.clear();
	}

	LevelMap::LevelMap(const d2Level_t* level)
	{
		//lock = new CRITICAL_SECTION;
		//InitializeCriticalSection(lock);

		assert(act != NULL);
		assert(level != NULL);

		this->level = level;
		this->act = level->misc->act;
		RoomList roomsAdded ;

		// get the map size
		height = level->width * 5;
		width  = level->height * 5;
		x   = (level->x == -1 ? 0 : level->x * 5);
		y   = (level->y == -1 ? 0 : level->y * 5);

		bool added = false;
		d2Room2_t* room = level->room2First;
		cachedLevel = room->level;
		if(!level->room2First->room1)
		{
			addRoomData(room);
			added = true;
		}

		build();

		if(added)
			removeRoomData(room);
	}

	LevelMap::~LevelMap(void)
	{
		//DeleteCriticalSection(lock);
		//delete lock;
		//lock = NULL;
	}

	void LevelMap::build(void)
	{
		/*EnterCriticalSection(lock);

		mapPoints = Matrix<CollisionFlag>(height, width, LevelMap::Avoid);

		RoomList addedRooms;
		UnitAny* player = GetPlayerUnit();
		AddRoom(level->pRoom2First, addedRooms, player);

		FillGaps();
		ThickenWalls();
		DrillExits();

		LeaveCriticalSection(lock);*/
	}

	void LevelMap::addRoom(d2Room2_t* const room, RoomList& rooms, d2UnitAny_t* player)
	{
		if(!room || room->level->levelNumber != level->levelNumber)
			return;

		// ignore rooms we've seen before
		if(std::find(rooms.begin(), rooms.end(), room) != rooms.end())
			return;

		rooms.push_back(room);

		// add the room if necessary
		bool added = false;
		if(!room->room1)
		{
			addRoomData(room);
			added = true;
		}

		// add the collision data to the map
		//if(room->pRoom1)
		//	AddCollisionMap(room->pRoom1);

		for(d2Room2_t* pRooms = level->room2First; pRooms; pRooms = pRooms->next)
			addRoom(pRooms, rooms, player);


		/*Room2** pRooms = room->pRoom2Near;
		for(DWORD i = 0; i < room->dwRoomsNear; i++)
		AddRoom(pRooms[i], rooms, player);*/

		// and remove the room afterwards if we added it
		if(added)
			removeRoomData(room);
	}

	void LevelMap::addCollisionMap(d2Room1_t* pRoom1)
	{
		d2CollisionMap_t* map = pRoom1->collision;
		if(map == NULL)
			return;

		int	curx = map->gameX - x, 
			cury = map->gameY - y,
			height = map->gameX + map->gameWidth - x, 
			width = map->gameY + map->gameHeight - y;

		WORD* p = map->mapStart;

		for(int i = cury; i < width && p != map->mapEnd; i++)
		{
			for(int j = curx; j < height && p != map->mapEnd; j++, p++)
			{
				if ((*p & LevelMap::ClosedDoor) == LevelMap::ClosedDoor || (*p & LevelMap::Player) == LevelMap::Player)
				{
					setCollisionData(j, i, 0);
				}
				else if
					(
					(
						(*p & LevelMap::FriendlyNPC)  == LevelMap::FriendlyNPC ||
						(*p & LevelMap::NPCCollision) == LevelMap::NPCCollision ||
						(*p & LevelMap::NPCLocation)  == LevelMap::NPCLocation ||
						(*p & LevelMap::DeadBody)     == LevelMap::DeadBody ||
						(*p & LevelMap::Item)         == LevelMap::Item

						)
						&&	
						(*p & LevelMap::BlockWalk) != LevelMap::BlockWalk &&
						(*p & LevelMap::Wall)      != LevelMap::Wall &&
						(*p & LevelMap::Object)    != LevelMap::Object
						)
				{
					setCollisionData(j, i, 0);
				}
				else if (
					(*p & LevelMap::AlternateTile) == LevelMap::AlternateTile  &&
					(*p & LevelMap::BlockWalk) != LevelMap::BlockWalk &&
					(*p & LevelMap::Wall)      != LevelMap::Wall
					)
				{
					setCollisionData(j, i, 0);
				}
				else
				{
					setCollisionData(j, i, *p);
				}
			}
		}

		for(d2UnitAny_t* pUnit = pRoom1->unitFirst; pUnit; pUnit = pUnit->roomNext)
		{
			char tmp[128] = "";
			getUnitName(pUnit, tmp, 128);
			if (
				pUnit->type == 2 && (
					0 == strcmp(tmp, "Barrel") ||
					0 == strcmp(tmp, "Door") ||
					0 == strcmp(tmp, "door") ||
					0 == strcmp(tmp, "Urn") ||
					0 == strcmp(tmp, "LargeUrn")
					)
				)
			{
				Point loc(d2GetUnitX(pUnit), d2GetUnitY(pUnit));
				setCollisionData(loc.first - x, loc.second - y, 0);
			}
		}
	}

	void LevelMap::setCollisionData(int x, int y, int value)
	{
		// sync this to ensure that we don't try to add to a dead map or something
		//EnterCriticalSection(lock);

		assert(isValidPoint(Point(x, y), false));
		mapPoints.setPoint(x, y, (CollisionFlag)value);

		//LeaveCriticalSection(lock);
	}

	bool LevelMap::isGap(int x, int y, bool abs) const
	{
		const int gapSize = 3;
		Point pt(x, y);
		assert(isValidPoint(pt, abs));
		if(spaceIsWalkable(pt, abs))
			return false;

		int spaces = 0;

		for(int i = x-gapSize-1; i <= x+gapSize+1 && spaces < gapSize; i++)
		{
			Point pt(i, y);
			if(isValidPoint(pt, abs))
				spaces = (spaceIsWalkable(pt, abs) ? 0 : spaces+1);
		}

		if(spaces < gapSize)
			return true;

		for(int i = y-gapSize-1, spaces = 0; i <= y+gapSize+1 && spaces < gapSize; i++)
		{
			Point pt(x, i);
			if(isValidPoint(pt, abs))
				spaces = (spaceIsWalkable(pt, abs) ? 0 : spaces+1);
		}

		return spaces < gapSize;
	}

	void LevelMap::fillGaps(void)
	{
		//EnterCriticalSection(lock);

		for(int i = 0; i < height; i++)
			for(int j = 0; j < width; j++)
				if(isGap(i, j, false))
					setCollisionData(i, j, LevelMap::Avoid);

		//LeaveCriticalSection(lock);
	}

	void LevelMap::thickenWalls(void)
	{
		const int thickenAmount = 1;

		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				Point pt(i, j);
				if(spaceIsWalkable(pt, false) || getMapData(pt, false) == LevelMap::ThickenedWall)
					continue;

				for(int k=-1, x = i-thickenAmount; x <= i+thickenAmount; k++, x++)
				{
					for(int l=-1, y = j-thickenAmount; y <= j+thickenAmount; l++, y++)
					{
						if ((k == 0 && l == 0) || (k != 0 && l != 0))
							continue;

						Point point(x, y);
						if(isValidPoint(point, false) && spaceIsWalkable(point, false))
							setCollisionData(x, y, LevelMap::ThickenedWall);
					}
				}
			}
		}
	}

	Point LevelMap::absToRelative(const Point& point) const
	{
		return Point(point.first - x, point.second - y);
	}
	Point LevelMap::relativeToAbs(const Point& point) const
	{
		return Point(point.first + x, point.second + y);
	}

	int LevelMap::getMapData(const Point& point, bool abs) const
	{
		if(abs) return getMapData(absToRelative(point), false);

		assert(isValidPoint(point, abs));

		//EnterCriticalSection(lock);
		CollisionFlag value = mapPoints.getPoint(point.first, point.second);
		//LeaveCriticalSection(lock);

		return value;
	}

	bool LevelMap::isValidPoint(const Point& point, bool abs) const
	{
		if(abs) return isValidPoint(absToRelative(point), false);
		return !!(point.first >= 0 && point.second >= 0 && point.first < height && point.second < width);
	}

	void LevelMap::getExits(ExitArray& exits) const
	{
		static const Point empty(0,0);
		//EnterCriticalSection(lock);

		RoomList added;

		for(d2Room2_t* room = level->room2First; room; room = room->next)
		{
			if(!room->room1)
			{
				addRoomData(room);
				added.push_back(room);
			}

			if(room->level->levelNumber != level->levelNumber)
				continue;

			findRoomTileExits(room, exits);
		}

		findRoomLinkageExits(exits, added);

		RoomList::iterator start = added.begin(), last = added.end();
		for(RoomList::iterator it = start; it != last; it++)
			removeRoomData(*it);

		//LeaveCriticalSection(lock);
	}

	void LevelMap::drillExits()
	{
		ExitArray exits;

		getExits(exits);
		ExitArray::iterator begin = exits.begin(), last = exits.end();
		for(ExitArray::iterator it = begin; it != last; it++)
		{
			setCollisionData(it->position.first - x, it->position.second - y, 0);
			bool blind = true;
			for(int x = -1; x <= 1; x++)
			{
				for (int y = -1; y <= 1; y++)
				{
					if (x == 0 && y == 0)
					{
						continue;
					}
					if (isValidPoint(Point(it->position.first + x, it->position.second + y), true) && spaceIsWalkable(Point(it->position.first + x, it->position.second + y), true))
					{
						blind = false;
						break;
					}
				}
				if (blind == false)
				{
					break;
				}
			}
			if (blind == false)
			{
				continue;
			}
			for(int x = -1; x <= 1; x++)
			{
				for (int y = -1; y <= 1; y++)
				{
					if ((x != 0 && y != 0) || (x == 0 && y == 0))
					{
						continue;
					}
					if (isValidPoint(Point(it->position.first + x, it->position.second + y), true))
					{
						setCollisionData(it->position.first + x - x, it->position.second + y - y, 0);
					}
				}
			}
			for(int x = -2; x <= 2; x++)
			{
				for (int y = -2; y <= 2; y++)
				{
					if (((x < -1 || x > 1)  && (y < -1 || y > 1)) || (x == 0 && y == 0))
					{
						continue;
					}
					if (isValidPoint(Point(it->position.first + x, it->position.second + y), true) && spaceHasFlag(LevelMap::ThickenedWall, Point(it->position.first + x, it->position.second + y), true))
					{
						setCollisionData(it->position.first + x - x, it->position.second + y - y, 0);
					}
				}
			}
		}
	}

	bool LevelMap::exitExists(Point loc, ExitArray& exits) const
	{
		ExitArray::iterator start = exits.begin(), end = exits.end();
		for(ExitArray::iterator it = start; it != end; it++)
		{
			if(it->position == loc)
			{
				return true;
			}
		}
		return false;
	}

	bool LevelMap::exitExists(DWORD dwLevelNo, ExitArray& exits) const
	{
		ExitArray::iterator begin = exits.begin(), last = exits.end();
		for(ExitArray::iterator it = begin; it != last; it++)
		{
			if(it->target == dwLevelNo)
			{
				return true;
			}
		}
		return false;
	}

	void LevelMap::findRoomLinkageExits(ExitArray& exits, RoomList& added) const
	{
		using namespace std;
		static const Point empty(0,0);

		d2UnitAny_t* player = d2GetPlayerUnit();
		const Point playerOrigin(player->path->x - x, player->path->y - y);

		multimap<int, std::pair<Point, std::pair<Point, int>>> exitMap; // <level, <rooms[i], <middlepoint, size> > >

		for(d2Room2_t* room = level->room2First; room; room = room->next)
		{
			d2Room2_t** rooms = room->room2Near;
			for(DWORD i = 0; i < room->roomsNear; i++)
			{
				if(!rooms[i]->room1)
				{
					addRoomData(rooms[i]);
					added.push_back(rooms[i]);
				}

				if(rooms[i]->level->levelNumber == level->levelNumber)
					continue;

				// does this link already exist?
				bool exists = false;
				ExitArray::iterator begin = exits.begin(), last = exits.end();
				for(ExitArray::iterator it = begin; it != last; it++)
				{
					if(it->target == rooms[i]->level->levelNumber)
					{
						exists = true;
						break;
					}
				}
				if(exists)
					continue;

				// A -> origin of local room, B -> opposite corner from origin in local room ... X, Y -> like local but for adjecent room
				Point A, B, X, Y, startPoint, edgeDirection, orthogonalDirection;
				int overlappingX, overlappingY, edgeSize;
				// this could be enum
				bool startLeft = false, startRight = false, startTop = false, startBottom = false;

				A = Point(room->x * 5, room->y * 5);
				B = Point(room->x * 5 + room->width * 5, room->y * 5 + room->height * 5);

				X = Point(rooms[i]->x * 5, rooms[i]->y * 5);
				Y = Point(rooms[i]->x * 5 + rooms[i]->width * 5, rooms[i]->y * 5 + rooms[i]->height * 5);

				overlappingX = min(B.first,  Y.first)  - max(A.first,  X.first);
				overlappingY = min(B.second, Y.second) - max(A.second, X.second);

				if (overlappingX > 0) // top or bottom edge
				{
					if (A.second < X.second) // bottom edge
					{
						startPoint = Point(max(A.first, X.first), B.second-1);
						startBottom = true;
					}
					else
					{
						startPoint = Point(max(A.first, X.first), A.second);
						startTop = true;
					}
				}
				else if (overlappingY > 0) // left or right edge
				{
					if (A.first < X.first) // right edge
					{
						startPoint = Point(B.first-1, max(A.second, X.second));
						startRight = true;
					}
					else
					{
						startPoint = Point(A.first, max(A.second, X.second));
						startLeft = true;
					}
				}

				if (overlappingX < 0 || overlappingY < 0)
				{
					// Print("ÿc1d2bsÿc3LevelMap::GetExitsÿc0 adjecent room is out of reach - it's not even touching local room in corner!");
					continue;
				}
				if (overlappingX > 0 && overlappingY > 0)
				{
					// Print("ÿc1d2bsÿc3LevelMap::GetExitsÿc0 WTF local and adjecent rooms are overlapping (they share some points)!!!");
					continue;             
				}
				if (overlappingX < 3 && overlappingY < 3)
				{
					// edge is not large enough to even bother to check for exit (exit should be at least 3 points wide)
					continue;
				}

				if (startLeft || startRight) // -> going down
				{
					edgeSize = overlappingY; // number of vertical touched points
					edgeDirection = Point(0, 1); // down
					orthogonalDirection = Point((startLeft ? -1 : 1), 0); // checking adjecent spaces -> left / right
				}
				else // startTop || startBottom -> going right
				{
					edgeSize = overlappingX; // number of horizontal touched points
					edgeDirection = Point(1, 0); // right
					orthogonalDirection = Point(0, (startTop ? -1 : 1)); // checking adjecent spaces -> up / down
				}

				Point currentPoint, lastWalkablePoint;
				bool isPointWalkable = false;
				int spaces = 0, j;
				for (j = 0; j < edgeSize; j++)
				{
					// would be nice to convert this line to => currentPoint = startPoint + edgeDirection * j;
					currentPoint = Point(startPoint.first + j * edgeDirection.first, startPoint.second + j * edgeDirection.second);
					isPointWalkable = edgeIsWalkable(currentPoint, orthogonalDirection, rooms[i]->room1, true);
					if (isPointWalkable)
					{
						lastWalkablePoint = currentPoint;
						spaces++;
					}
					if (false == isPointWalkable || j + 1 == edgeSize)
					{
						if (spaces > 2)
						{
							Point centerEdgePoint = getEdgeCenterPoint(currentPoint, edgeDirection);
							currentPoint = Point(lastWalkablePoint.first - edgeDirection.first * spaces / 2, lastWalkablePoint.second - edgeDirection.second * spaces / 2);
							exitMap.insert(make_pair(rooms[i]->level->levelNumber, make_pair(centerEdgePoint, make_pair(currentPoint, spaces))));
						}
						spaces = 0;
					}
				}
			}
		}

		std::pair<Point, std::pair<Point, int>> currentExit;
		std::multimap<int, std::pair<Point, std::pair<Point, int>>>::iterator it = exitMap.begin();
		int level = 0;
		double minDistance = -1, tmpDistance;
		do
		{
			if (level == 0 && it == exitMap.end())
			{
				break;
			}
			if (level == 0)
			{
				level = it->first;
				currentExit = it->second;
			}
			if (it == exitMap.end() || level != it->first)
			{
				exits.push_back(Exit(currentExit.second.first, level, Linkage, 0));
				if (it == exitMap.end())
				{
					break;
				}
				level = it->first;
				currentExit = it->second;
				minDistance = -1;
			}

			tmpDistance = getDistance(
				it->second.first.first,
				it->second.first.second,
				it->second.second.first.first,
				it->second.second.first.second
			);
			if (minDistance == -1 || minDistance > tmpDistance)
			{
				currentExit = it->second;
				minDistance = tmpDistance;
			}
		} while(it++ != exitMap.end());
	}

	Point LevelMap::getEdgeCenterPoint(const Point &currentPoint, const Point &edgeDirection) const
	{
		Point startPoint = Point(currentPoint.first, currentPoint.second);
		Point left = startPoint, right = startPoint;
		for (int i = -1; isValidPoint(startPoint, true); i--)
		{
			if (spaceIsWalkableForExit(startPoint, true))
			{
				left = startPoint;
			}
			startPoint = Point(currentPoint.first + edgeDirection.first * i, currentPoint.second + edgeDirection.second * i);
		}
		startPoint = Point(currentPoint.first, currentPoint.second);
		for (int i = 1; isValidPoint(startPoint, true); i++)
		{
			if (spaceIsWalkableForExit(startPoint, true))
			{
				right = startPoint;
			}
			startPoint = Point(currentPoint.first + edgeDirection.first * i, currentPoint.second + edgeDirection.second * i);
		}
		return Point((left.first + right.first) / 2, (left.second + right.second) / 2);
	}

	void LevelMap::findRoomTileExits(d2Room2_t* room, ExitArray& exits) const
	{
		for(d2PresetUnit_t* preset = room->preset; preset; preset = preset->next)
		{
			if(preset->type == 5) // UNIT_TILE
			{
				DWORD levelId = getLevelNo(room, preset->textFileNumber);
				if(levelId != 0)
				{
					Point loc((room->x*5)+preset->x, (room->y*5)+preset->y);

					if(!exitExists(loc, exits))
					{
						exits.push_back(Exit(loc, levelId, Tile, preset->textFileNumber));
					}
				}
			}
		}
	}

	/**
	*    This method will check six points - orthogonal to area-crossing-edge
	*    * 3 points from local room
	*    * 3 points from adjecent room (room behind area-crossing-edge)
	*
	*                            __                              
	*    distanceLocal       -2    |                             i    3
	*                        -1    +--- pRoom1Local              n    2
	*    edgePoint           (0) __|                            -->   1
	*                                                            o 
	*    -------------[ area join edge ]----------------         r
	*                            __                              d 
	*                         1    |                             e    4
	*                         2    +--- pRoom1Adjecent           r    5
	*    distanceAdjecent     3  __|                                  6
	*/
	bool LevelMap::edgeIsWalkable(const Point& edgePoint, const Point& offsetPoint, d2Room1_t* pRoom1Adjecent, bool abs) const
	{
		int k;
		const int distanceLocal    = -2;
		const int distanceAdjecent =  3;
		for (k = distanceLocal; k <= distanceAdjecent; k++)
		{
			if (k <= 0)  // simulation of character-size (3 point in width/height) staying in local room
			{
				const Point currentPoint = Point(edgePoint.first + offsetPoint.first * (distanceLocal-k), edgePoint.second + offsetPoint.second * (distanceLocal-k));
				if (false == spaceIsWalkableForExit(currentPoint, abs))
				{
					break;
				}
			}

			// -------------[ area join edge ]---------------- 

			else // simulation of character-size (3 point in width/height) staying in adjecent room
			{
				const Point currentPoint = Point(edgePoint.first + offsetPoint.first * k, edgePoint.second + offsetPoint.second * k);
				if (false == roomSpaceIsWalkable(pRoom1Adjecent, currentPoint, abs))
				{
					break;
				}
			}
		}
		return k > distanceAdjecent;
	}

	bool LevelMap::spaceHasFlag(int flag, const Point& point, bool abs) const
	{
		int val = 	getMapData(point, abs) |  
			getMapData(Point(point.first-1,point.second), abs) | 
			getMapData(Point(point.first+1,point.second), abs) |
			getMapData(Point(point.first,point.second-1), abs) | 
			getMapData(Point(point.first,point.second+1), abs);
		return ((val & flag) == flag);
	}
	bool LevelMap::pathHasFlag(int flag, const PointList& points, bool abs) const
	{
		int count = points.size();
		for(int i = 0; i < count; i++)
			if(!spaceHasFlag(flag, points[i], abs))
				return false;
		return true;
	}

	bool LevelMap::spaceIsWalkable(const Point& point, bool abs) const
	{
		// ignore closed doors here, because we want to path through them
		return !(spaceHasFlag(LevelMap::Avoid, point, abs)        ||
			spaceHasFlag(LevelMap::BlockWalk, point, abs)    ||
			spaceHasFlag(LevelMap::BlockPlayer, point, abs)  ||
			spaceHasFlag(LevelMap::NPCCollision, point, abs) ||
			spaceHasFlag(LevelMap::Object, point, abs)       ||
			spaceHasFlag(LevelMap::ThickenedWall, point, abs)
			);
	}

	bool LevelMap::spaceIsWalkableForExit(const Point& point, bool abs) const
	{
		// ignore almost everything
		return !(!isValidPoint(point, abs)                        ||
			spaceHasFlag(LevelMap::Avoid, point, abs)        ||
			spaceHasFlag(LevelMap::BlockWalk, point,  abs)   ||
			spaceHasFlag(LevelMap::BlockPlayer, point, abs)
			);
	}

	bool LevelMap::roomSpaceIsWalkable(d2Room1_t* pRoom1, const Point& point, bool abs)const
	{
		unsigned int x = point.first, y = point.second;
		if (abs)
		{
			// convert to origin
			x -= pRoom1->collision->gameX; // already x5
			y -= pRoom1->collision->gameY; // already x5
		}
		// out of room?
		if (x >= pRoom1->collision->gameWidth || y >= pRoom1->collision->gameHeight || x < 0 || y < 0)
		{
			return false;
		}
		// p = pointer to space in room1 - by relative coords
		WORD *p = pRoom1->collision->mapStart // origin
			+ x // x
			+ pRoom1->collision->gameWidth * y; // y
		bool output = valueIsWalkable(p);
		return output;
	}

	bool LevelMap::valueIsWalkable(const WORD *value) const
	{
		return !(
			valueHasFlag(LevelMap::BlockWalk, value) ||
			valueHasFlag(LevelMap::BlockPlayer, value) ||
			valueHasFlag(LevelMap::Object, value)
			);
	}

	bool LevelMap::valueHasFlag(int flag, const WORD *value) const
	{
		return ((*value & flag) == flag);
	}

	bool LevelMap::spaceHasLineOfSight(const Point& point, bool abs) const
	{
		return !spaceHasFlag(LevelMap::Avoid, point, abs) && !spaceHasFlag(LevelMap::BlockLineOfSight, point, abs);
	}

	bool LevelMap::spaceIsInvalid(const Point& point, bool abs) const { return spaceHasFlag(LevelMap::Avoid, point, abs); }

	bool LevelMap::spaceIsThickenedWall(const Point& point, bool abs) const { return spaceHasFlag(LevelMap::ThickenedWall, point, abs); }

	bool LevelMap::pathIsWalkable(const PointList& points, bool abs) const
	{
		int count = points.size();
		for(int i = 0; i < count; i++)
			if(!spaceIsWalkable(points[i], abs))
				return false;
		return true;
	}
	bool LevelMap::pathHasLineOfSight(const PointList& points, bool abs) const
	{
		int count = points.size();
		for(int i = 0; i < count; i++)
			if(!spaceHasLineOfSight(points[i], abs))
				return false;
		return true;
	}

	void LevelMap::dump(const char* file, const PointList& points) const
	{
		FILE* f = NULL;
		fopen_s(&f, file, "wt+");
		if(!f) return;
		fprintf(f, "Map (%d x %d) at (%d, %d) for area %s (id %d):\n", width, height, x, y, getLevelName(level), level->levelNumber);

		fprintf(f, "Exits:\n");

		ExitArray exits;
		getExits(exits);
		int i = 1;
		for(ExitArray::iterator it = exits.begin(); it != exits.end(); it++)
		{
			Point rel = absToRelative(it->position);
			fprintf(f, "Exit %d: at (%d, %d, relative: %d, %d) of type %s linkage to area %s (id: %d, tile id: %d)\n", i++,
				it->position.first, it->position.second, rel.first, rel.second,
				it->type == Linkage ? "Area" : "Tile", getLevelIdName(it->target), it->target, it->tileId);
		}

		fprintf(f, "\n");

		PointList::const_iterator begin = points.begin(), end = points.end();
		Point first, last;
		if(points.size() == 0)
		{
			first = Point(-1, -1);
			last = Point(-1, -1);
		}
		else
		{
			first = *begin;
			last = *(end-1);
		}

		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				Point pt(i, j);
				char c = '.';
				if(spaceHasFlag(LevelMap::Avoid, pt, false))
					c = 'A';
				else if(pt == first)
					c = 'S';
				else if(pt == last)
					c = 'E';
				else if(std::find(begin, end, pt) != end)
					c = 'P';
				else if(spaceIsInvalid(pt, false))
					c = '?';
				else if(getMapData(pt, false) == LevelMap::ThickenedWall)
					c = 'T';
				else if(!spaceIsWalkable(pt, false))
					c = 'X';
				fprintf(f, "%c", c);
			}
			fprintf(f, "\n");
		}
		fclose(f);
	}
}