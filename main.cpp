#include "object.h"
#include "grid.h"
#include "room.h"
#include <iostream>
#include <unistd.h>

const int sleepTime = 200000;

void clearScreen() {
  std::cout << "\x1B[2J\x1B[H";
}

int main() {

  Room r1;

  r1.displayRoom();

  Robot *rob = r1.getRobot();


  while(true) {
    //char c1;
    while(true) {
      clearScreen();
      if(!rob->move()) {
          rob->turnLeft();
      }
      rob->clean();
      r1.displayRoom();
      usleep(sleepTime);
    }
  }
  return 0;
}
