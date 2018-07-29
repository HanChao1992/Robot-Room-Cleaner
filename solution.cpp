#include "solution.h"

void Solution::cleanRoom(Robot *rob, Room *room, Coordinate curPos) {
  //std::cout << "at "
  if (visited[curPos.x][curPos.y] == true) {
    //clearScreen();
    //room->displayRoom();
    return;
  }
  else {
    visited[curPos.x][curPos.y] = true;
    rob->clean();

    for (int i = 0; i < 4; i++) {
      if (rob->move()) {
        cleanRoom(rob,room, getPos(rob, curPos, true));
        rob->turnLeft();
        rob->turnLeft();
        rob->move();
        //clearScreen();
        //room->displayRoom();
        rob->turnLeft();
        rob->turnLeft();
        //getPos(rob, curPos, false);
      }
      rob->turnRight();
    }

  }
  //clearScreen();
  //room->displayRoom();
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


void Solution::clearScreen() {
  std::cout << "\x1B[2J\x1B[H";
}
