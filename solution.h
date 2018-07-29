#ifndef _SOLUTION_HEADER_
#define _SOLUTION_HEADER_

#include "room.h"
#include <iostream>
#include <unistd.h>
#include <unordered_map>

class Solution {
private:
  std::unordered_map<int, std::unordered_map<int, bool>> visited;

public:
  void cleanRoom(Robot *rob);
  void cleanRoom(Robot *rob, Coordinate curPos);
  Coordinate getNextPos(Robot *rob, Coordinate curPos);
};

#endif
