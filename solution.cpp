#include "solution.h"

void Solution::cleanRoom(Robot *rob, Room *room, Coordinate curPos) {
  rob->clean();
  visited[curPos.x][curPos.y] = true;

  for (int i = 0; i < 4; i++) {
    Coordinate newPos = getPos(rob, curPos, true);
    if (!visited[newPos.x][newPos.y]) {
      if (rob->move()) {
        cleanRoom(rob, room, newPos);
      }
    }
    rob->turnRight();
  }

  rob->turnLeft();
  rob->turnLeft();
  rob->move();
  rob->turnLeft();
  rob->turnLeft();
}


Coordinate Solution::getPos(Robot *rob, Coordinate curPos, bool forward) {
  switch (rob->getDirection()) {
    case Direction::up: forward ? curPos.y-- : curPos.y++; break;
    case Direction::down: forward ? curPos.y++ : curPos.y--; break;
    case Direction::left: forward ? curPos.x-- : curPos.x--; break;
    case Direction::right: forward ? curPos.x++ : curPos.x--; break;
  }
  return curPos;
}
