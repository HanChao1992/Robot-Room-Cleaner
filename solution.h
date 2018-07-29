#ifndef _SOLUTION_HEADER_
#define _SOLUTION_HEADER_

#include "room.h"
#include <iostream>
#include <unistd.h>
#include <unordered_map>

class Solution {
private:
  std::unordered_map<int, std::unordered_map<int, bool>> visited;

  //Coordinate curPos = Coordinate(0, 0);

public:
  void cleanRoom(Robot *rob, Room *room, Coordinate curPos);
  Coordinate getPos(Robot *rob, Coordinate curPos, bool forward);
};

#endif
