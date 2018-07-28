#ifndef _ROBOT_HEADER_
#define _ROBOT_HEADER_

//#include "room.h"

class Room;

enum class Direction {
  up,
  down,
  left,
  right
};


class Robot{
private:
  Direction dir;
  Room* room;

public:
  Robot(Room *room);
  Robot(Direction dir, Room *room);
  bool move();
  void turnLeft();
  void turnRight();
  void clean();
  Direction getDirection();
  void setDirection(Direction dir);
};

#endif
