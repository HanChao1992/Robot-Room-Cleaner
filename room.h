#ifndef _ROOM_HEADER_
#define _ROOM_HEADER_

#include <vector>
#include "grid.h"
#include "robot.h"

class Room {
private:
  std::vector<std::vector<Grid*>> layout;
  int maxWidth;
  int maxDepth;
  int robotStep = 0;

  Robot *robot;
  Coordinate *robotPos;

public:
  Room();
  void displayRoom();
  ~Room();
  Robot *getRobot();
  bool robotCanMove();
  void robotClean();
  void placeRobot(Direction dir=Direction::up);
  void setRobot(bool b);
};

#endif
