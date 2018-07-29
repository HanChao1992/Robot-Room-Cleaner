#include "solution.h"

// Implement this
void Solution::cleanRoom(Robot *rob) {
  cleanRoom(rob, Coordinate(0, 0));
}

void Solution::cleanRoom(Robot *rob, Coordinate curPos) {
  rob->clean();
  visited[curPos.x][curPos.y] = true;

  for (int i = 0; i < 4; i++) {
    Coordinate newPos = getNextPos(rob, curPos);
    if (!visited[newPos.x][newPos.y]) {
      if (rob->move()) {
        cleanRoom(rob, newPos);
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


Coordinate Solution::getNextPos(Robot *rob, Coordinate curPos) {
  switch (rob->getDirection()) {
    case Direction::up: curPos.y--; break;
    case Direction::down: curPos.y++; break;
    case Direction::left: curPos.x--; break;
    case Direction::right: curPos.x++; break;
  }
  return curPos;
}
