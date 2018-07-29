#include "solution.h"







int main() {

  Room r1;

  //r1.displayRoom();

  Robot *rob = r1.getRobot();

  Solution s;
  s.cleanRoom(rob, &r1, Coordinate(0, 0));

  return 0;
}
