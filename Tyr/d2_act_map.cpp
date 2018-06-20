#include <algorithm>
#include <assert.h>
#include "d2_act_map.h"

namespace Mapping
{
	ActMapList ActMap::cache = ActMapList();
	DWORD ActMap::previousLevelNo = 0;

	ActMap::ActMap(const d2Level_t* level)
	{
		//lock = new CRITICAL_SECTION;
		//InitializeCriticalSection(lock);
		//actCrit = new CriticalRoom;
		//actCrit->EnterSection();
		
		this->level = level;
		this->act = level->misc->act;

		assert(act != NULL);
		assert(level != NULL);

		// get the map size
		height	= level->width * 5;
		width	= level->height * 5;
		x		= level->x * 5;
		y		= level->y * 5;

		if(!level->room2First)
			//D2COMMON_InitLevel(const_cast<d2Level_t*> (level));
			d2InitLevel( const_cast<d2Level_t*>(level) );
		
		x   = (level->x == -1 ? 0 : level->x * 5);
		y   = (level->y == -1 ? 0 : level->y * 5);
	}

	ActMap::~ActMap(void)
	{
		//DeleteCriticalSection(lock);
		//delete lock;
		//delete actCrit;
		//lock = NULL;
		pathingPointList.clear();
	}

	ActMap* ActMap::getMap(d2Level_t* level)
	{
		ActMap* map = NULL;

		if (previousLevelNo != 0)
		{
			cache[0]->cleanUp();
			delete cache[0];
		}
		previousLevelNo = level->levelNumber;
		map = new ActMap(level);
		cache[0] = map;

		return map;
	}

	void ActMap::clearCache(void)
	{
		ActMapList::iterator end = cache.end();
		for(ActMapList::iterator it = cache.begin(); it != end; it++)
			delete it->second;
		cache.clear();
		ActMap::previousLevelNo = 0;
	}

	Point ActMap::absToRelative(const Point& point) const
	{
		return Point(point.first - x, point.second - y);
	}

	Point ActMap::relativeToAbs(const Point& point) const
	{
		return Point(point.first + x, point.second + y);
	}

	int ActMap::getMapData(const Point& point, bool abs) const
	{
		if(!abs) 
			return getMapData(relativeToAbs(point), true);

		//check in rooms we already read
		for(RoomList::iterator cRoom = roomCache.begin(); cRoom != roomCache.end(); cRoom++)
			if(isPointInRoom(*cRoom, point))
				return getCollFromRoom(*cRoom, point);

		const d2Level_t* currLevel = NULL;
		if (isPointInLevel(this->level, point))
		{
			currLevel = level;
		}
		if (!currLevel)
		{
			for(LevelList::iterator cLvl = levelCache.begin(); cLvl != levelCache.end(); cLvl++)
			{
				if(isPointInLevel(*cLvl, point))
					currLevel = *cLvl;
			}
		}
		if(!this->act || !this->act->misc || !this->act->room1)
		{
			//Print("c1ActMap Level Not Loaded");
			return ActMap::Avoid;
		}
		if(!currLevel)
		{
			for(d2Level_t* lvl = this->act->misc->levelFirst ; lvl ;lvl = lvl->next)
			{
				if(isPointInLevel(lvl, point)){
					if(!lvl->room2First)      
						//D2COMMON_InitLevel(lvl);
						d2InitLevel( lvl );
					levelCache.push_front(lvl);
					currLevel = lvl;
				}
			}
		}

		int value = ActMap::Avoid;  //Avoid if not found
		if (!currLevel)
			return value;

		//EnterCriticalSection(lock); // not sure if this is needed or its correct lock now


		for(d2Room2_t* room = currLevel->room2First; room; room = room->next)
		{
			if (isPointInRoom(room, point))
			{	
				roomCache.push_front(room);

				value = getCollFromRoom(room, point);
				break;
			}			
		}

		//LeaveCriticalSection(lock);

		return value;
	}

	bool ActMap::isPointInRoom(const d2Room2_t* room, const Point& pt)const
	{
		DWORD nX = pt.first;
		DWORD nY = pt.second;

		return (nX >= room->x *5  &&  nY >= room->y *5 &&
			nX < (room->x *5 + room->width *5) &&  nY < (room->y *5 + room->height *5));
	}

	bool ActMap::isPointInLevel(const d2Level_t* level, const Point& pt)const
	{
		DWORD x = pt.first;
		DWORD y = pt.second;
		return (x >= level->x *5  &&  y >= level->y *5 &&
			x < (level->x *5 + level->width *5) &&  y < (level->y *5 + level->height *5));			
	}

	WORD ActMap::getAvoidLayerPoint(d2Room2_t* room, const Point& pt) const
	{
		RoomPointSet::iterator it;
		it = avoidRoomPointSet.find(room); 
		if (it == avoidRoomPointSet.end())
		{
			PointSet pointSet;
			for(d2PresetUnit_t* preset = room->preset; preset; preset = preset->next)
			{
				Point loc((room->x*5)+preset->x, (room->y*5)+preset->y);
				if (preset->textFileNumber == 435) // barricade tower
				{
					pointSet.insert(loc);
				}			
			}

			avoidRoomPointSet[room] = pointSet;
			it = avoidRoomPointSet.find(room);
		}
		if (it->second.find(pt) == it->second.end())
		{
			return 0;
		}
		return ActMap::Avoid;
	}

	WORD ActMap::getCollFromRoom( d2Room2_t* room, const Point& pt) const
	{
		if(!room->room1)
		{
			addRoomData(room);
			roomsAdded.push_back(room);
		}

		d2CollisionMap_t* map = room->room1->collision;
		WORD val = *(map->mapStart+(pt.second - map->gameY) * (map->gameWidth) + (pt.first - map->gameX));

		// todo: avoid layer could be used in every area, we can add unwalkable objects like torches, chests etc
		// but for now, just try it with barricade wall in Frigid Highlands (111), Arreat Plateau (112) and Frozen Tundra (117)
		if (room->level->levelNumber == 111 || room->level->levelNumber == 112 || room->level->levelNumber == 117 || room->level->levelNumber == 74 )
		{
			val |= getAvoidLayerPoint(room, pt);
		}
		return val;
	}

	void ActMap::cleanUp() const
	{	
		for(RoomList::iterator it = roomsAdded.begin(); it != roomsAdded.end(); it++)
			removeRoomData(*it);

		roomsAdded.clear();
		levelCache.clear();
		roomCache.clear();
		avoidRoomPointSet.clear();
		//actCrit->LeaveSection();
	}

	void ActMap::allowCritSpace() const
	{	
		cleanUp();
		//actCrit->LeaveSection();
		//Sleep(5);
		//actCrit->EnterSection();
	}

	void ActMap::getExits(ExitArray& exits) const
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
		findRoomLinkageExits(exits);

		RoomList::iterator start = added.begin(), last = added.end();
		for( RoomList::iterator it = start; it != last; it++ )
			removeRoomData(*it);

		//LeaveCriticalSection(lock);
	}

	bool ActMap::exitExists(Point loc, ExitArray& exits) const
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

	bool ActMap::exitExists(DWORD dwLevelNo, ExitArray& exits) const
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

	void ActMap::findRoomTileExits( d2Room2_t* room, ExitArray& exits ) const
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

	void ActMap::findRoomLinkageExits(ExitArray& exits) const
	{
		using namespace std;

		multimap<int, std::pair<Point, std::pair<Point, int>>> exitMap; // <level, <rooms[i], <middlepoint, size> > >

		for(d2Room2_t* room = level->room2First; room; room = room->next)
		{
			d2Room2_t** rooms = room->room2Near;
			for(DWORD i = 0; i < room->roomsNear; i++)
			{
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
					// Print("c1d2bsc3ActMap::GetExitsc0 adjecent room is out of reach - it's not even touching local room in corner!");
					continue;
				}
				if (overlappingX > 0 && overlappingY > 0)
				{
					// Print("c1d2bsc3ActMap::GetExitsc0 WTF local and adjecent rooms are overlapping (they share some points)!!!");
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
					isPointWalkable = edgeIsWalkable(currentPoint, orthogonalDirection, true);
					if (isPointWalkable)
					{
						lastWalkablePoint = currentPoint;
						spaces++;
					}
					if (false == isPointWalkable || j + 1 == edgeSize)
					{
						if (spaces > 0)
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

	Point ActMap::getEdgeCenterPoint(const Point &currentPoint, const Point &edgeDirection) const
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
	bool ActMap::edgeIsWalkable(const Point& edgePoint, const Point& offsetPoint, bool abs) const
	{
		int k;
		const int distanceLocal    = -1;
		const int distanceAdjecent =  2;
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
				if (false == spaceIsWalkableForExit(currentPoint, abs))
				{
					break;
				}
			}
		}
		return k > distanceAdjecent;
	}

	bool ActMap::isValidPoint(const Point& point, bool abs) const
	{
		if(abs) return isValidPoint(absToRelative(point), false);
		return !!(point.first >= 0 && point.second >= 0 && point.first < height && point.second < width);
	}

	bool ActMap::oneSpaceHasFlag(int flag, const Point& point, bool abs) const
	{
		if(!abs) 
			return oneSpaceHasFlag(flag, relativeToAbs(point), true);

		int val = getMapData(point, abs);
		return ((val & flag) == flag);
	}

	bool ActMap::spaceHasFlag(int flag, const Point& point, bool abs) const
	{
		if(!abs) 
			return spaceHasFlag(flag, relativeToAbs(point), true);

		int val = getMapData(point, abs)
			| getMapData(Point(point.first - 1, point.second), abs)
			| getMapData(Point(point.first + 1, point.second), abs)
			| getMapData(Point(point.first, point.second - 1), abs)
			| getMapData(Point(point.first, point.second + 1), abs);
		return ((val & flag) == flag);
	}

	bool ActMap::pathHasFlag(int flag, const PointList& points, bool abs) const
	{
		int count = points.size();
		for(int i = 0; i < count; i++)
			if(!spaceHasFlag(flag, points[i], abs))
				return false;
		return true;
	}

	bool ActMap::spaceIsWalkable(const Point& point, bool abs) const
	{
		// ignore closed doors here, because we want to path through them
		//(!IsValidPoint(point, abs)                        ||
		return !(spaceHasFlag(ActMap::Avoid, point, abs)        ||
			spaceHasFlag(ActMap::BlockWalk, point, abs)    ||
			spaceHasFlag(ActMap::BlockPlayer, point, abs)  ||
			spaceHasFlag(ActMap::NPCCollision, point, abs) ||
			spaceHasFlag(ActMap::Object, point, abs)   //    ||
													   // SpaceHasFlag(ActMap::ThickenedWall, point, abs)
			);
	}

	bool ActMap::spaceIsWalkableForExit(const Point& point, bool abs) const
	{
		// ignore almost everything
		return !(
			spaceHasFlag(ActMap::Avoid, point, abs)      ||
			spaceHasFlag(ActMap::BlockWalk, point,  abs) ||
			spaceHasFlag(ActMap::BlockPlayer, point, abs)
			);
	}

	bool ActMap::spaceHasLineOfSight(const Point& point, bool abs) const
	{
		return !spaceHasFlag(ActMap::Avoid, point, abs) && !spaceHasFlag(ActMap::BlockLineOfSight, point, abs);
	}

	bool ActMap::spaceIsInvalid(const Point& point, bool abs) const { return spaceHasFlag(ActMap::Avoid, point, abs); }

	bool ActMap::pathIsWalkable(const PointList& points, bool abs) const
	{
		int count = points.size();
		for(int i = 0; i < count; i++)
			if(!spaceIsWalkable(points[i], abs))
				return false;
		return true;
	}

	bool ActMap::pathHasLineOfSight(const PointList& points, bool abs) const
	{
		int count = points.size();
		for(int i = 0; i < count; i++)
			if(!spaceHasLineOfSight(points[i], abs))
				return false;
		return true;
	}

	void ActMap::dump(const char* file, const PointList& points) const
	{
		//EnterCriticalSection(lock);

		FILE* f = NULL;
		fopen_s(&f, file, "wt+");
		if(!f) return;
		fprintf(f, "Map (%d x %d) at (%d, %d) for area %s (id %d):\n", width, height, x, y, getLevelName(level), level->levelNumber);

		fprintf(f, "\n");
		typedef std::map<Point, char> PointMap;
		PointMap pathMap;
		if (points.size() > 0)
		{
			PointList::const_iterator it = points.begin(), end = points.end(), end1 = points.end()-1;
			int i = 0;
			while(it != end)
			{
				if (i == 0)
					pathMap.insert(std::pair<Point, char>(*it, 'S')); // start
				else if (it == end1)
					pathMap.insert(std::pair<Point, char>(*it, 'E')); // end
				else
					pathMap.insert(std::pair<Point, char>(*it, 49 + (i % 9))); // 1 - 9 (0 is too close to O)
				i++;
				it++;
			}
		}
		for(int j = 0; j < width; j++)
		{
			for(int i = 0; i < height; i++)
			{
				// skipping group of Avoid points at the end of row
				bool onlyAvoid = true;
				int k;
				for (k = i; k < height; k++)
				{
					Point pt(k, j);
					if (!oneSpaceHasFlag(ActMap::Avoid, pt, false))
					{
						onlyAvoid = false;
						break;
					}
				}
				if (onlyAvoid)
				{
					break;
				}
				for (; i < k; i++)
				{
					fprintf(f, "A");
				}

				Point pt(i, j);
				char c = '.';
				if (oneSpaceHasFlag(ActMap::ClosedDoor, pt, false))
					c = 'D';
				if (oneSpaceHasFlag(ActMap::Object, pt, false))
					c = 'O';
				if (oneSpaceHasFlag(ActMap::NPCCollision, pt, false))
					c = 'N';
				if (oneSpaceHasFlag(ActMap::BlockPlayer, pt, false))
					c = 'P';
				if (oneSpaceHasFlag(ActMap::BlockWalk, pt, false))
					c = 'W';
				if(oneSpaceHasFlag(ActMap::Avoid, pt, false))
					c = 'A';
				if(pathMap.find(relativeToAbs(pt)) != pathMap.end())
					c = pathMap.find(relativeToAbs(pt))->second;
				fprintf(f, "%c", c);
			}
			fprintf(f, "\n");
		}
		fclose(f);
		//LeaveCriticalSection(lock);
	}


	void ActMap::dumpLevel(const char* file) const
	{
		//EnterCriticalSection(lock);

		FILE* f = NULL;
		fopen_s(&f, file, "wt+");
		if(!f) return;
		fprintf(f, "Map (%d x %d) at (%d, %d) for area %s (id %d):\n", width, height, x, y, getLevelName(level), level->levelNumber);

		fprintf(f, "--------------------------\n");
		fprintf(f, "Presets:\n");
		RoomList added;
		int i = 1;
		for(d2Room2_t* room = level->room2First; room; room = room->next)
		{
			for(d2PresetUnit_t* preset = room->preset; preset; preset = preset->next)
			{
				Point loc((room->x*5)+preset->x, (room->y*5)+preset->y);
				Point rel = absToRelative(loc);
				char *wName = "";

				if (preset->type == 2 && preset->textFileNumber <= 574)
				{
					//ObjectTxt *obj = D2COMMON_GetObjectText(preset->dwTxtFileNo);
					d2ObjectText_t* obj = d2GetObjectText( preset->textFileNumber );
					if (obj != NULL)
					{
						wName = obj->name;
					}
				}
				fprintf(f, "Preset %d: at (%d, %d, relative: %d, %d) of type %d, txtFile %d, _1 %d, _3 %d, room (%d, %d) %s\n",
					i++, loc.first, loc.second, rel.first, rel.second, preset->type, preset->textFileNumber, preset->_1, preset->_2, room->x, room->y, wName);
			}
		}

		fprintf(f, "--------------------------\n");
		fprintf(f, "Units:\n");
		i = 1;
		for(d2Room2_t* room = level->room2First; room; room = room->next)
		{
			if(!room->room1)
			{
				addRoomData(room);
				added.push_back(room);
			}

			for(d2UnitAny_t* pUnit = room->room1->unitFirst; pUnit; pUnit = pUnit->roomNext)
			{
				//Point loc(D2CLIENT_GetUnitX(pUnit),D2CLIENT_GetUnitY(pUnit));
				Point loc( d2GetUnitX( pUnit ), d2GetUnitY( pUnit ) );
				Point rel = absToRelative(loc);

				char tmp[128] = "";
				getUnitName(pUnit, tmp, 128);
				fprintf(f, "Unit %d: at (%d, %d, relative: %d, %d) of type %d, txtFile %d, %s, %d, %d\n", 

					i++, loc.first, loc.second, rel.first, rel.second, pUnit->type, pUnit->textFileNumber, tmp, pUnit->x, pUnit->y);
			}
		}

		RoomList::iterator start = added.begin(), last = added.end();
		for(RoomList::iterator it = start; it != last; it++)
			removeRoomData(*it);

		fprintf(f, "--------------------------\n");
		fprintf(f, "Exits:\n");
		ExitArray exits;
		getExits(exits);
		std::set<Point> exitPoints;
		i = 1;
		for(ExitArray::iterator it = exits.begin(); it != exits.end(); it++)
		{
			Point rel = absToRelative(it->position);

			fprintf(f, "Exit %d: at (%d, %d, relative: %d, %d) of type %s linkage to area %s (id: %d, tile id: %d)\n", i++,
				it->position.first, it->position.second, rel.first, rel.second,
				it->type == Linkage ? "Area" : "Tile", getLevelIdName(it->target), it->target, it->tileId);

			exitPoints.insert(rel);
		}
		fprintf(f, "\n");

		for(int j = 0; j < width; j++)
		{
			for(int i = 0; i < height; i++)
			{
				// skipping group of Avoid points at the end of row
				bool onlyAvoid = true;
				int k;
				for (k = i; k < height; k++)
				{
					Point pt(k, j);
					if (!oneSpaceHasFlag(ActMap::Avoid, pt, false))
					{
						onlyAvoid = false;
						break;
					}
				}
				if (onlyAvoid)
				{
					break;
				}
				for (; i < k; i++)
				{
					fprintf(f, "A");
				}

				Point pt(i, j);
				char c = '.';
				if (oneSpaceHasFlag(ActMap::ClosedDoor, pt, false))
					c = 'D';
				if (oneSpaceHasFlag(ActMap::Object, pt, false))
					c = 'O';
				if (oneSpaceHasFlag(ActMap::NPCCollision, pt, false))
					c = 'N';
				if (oneSpaceHasFlag(ActMap::BlockPlayer, pt, false))
					c = 'P';
				if (oneSpaceHasFlag(ActMap::BlockWalk, pt, false))
					c = 'W';
				if(oneSpaceHasFlag(ActMap::Avoid, pt, false))
					c = 'A';
				if(exitPoints.end() != exitPoints.find(pt))
					c = '%';
				fprintf(f, "%c", c);
			}
			fprintf(f, "\n");
		}
		fclose(f);
		//LeaveCriticalSection(lock);
	}

}