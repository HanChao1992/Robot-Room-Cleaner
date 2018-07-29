#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include "room.h"
#include <stdlib.h>

Room::Room() {
  std::ifstream inFile;

  try {
    inFile.open("room1.txt");
    std::string line;
    int lineCount = 0;
    while(getline(inFile, line)) {
      lineCount++;
      if (lineCount == 1) {
        maxWidth = std::stoi(line);
      }
      else if (lineCount == 2) {
        maxDepth = std::stoi(line);
        layout = std::vector<std::vector<Grid*>> (maxDepth, std::vector<Grid*> (maxWidth, NULL));
      }
      else {
        for (size_t i = 0; i < line.length(); ++i) {
          layout[lineCount - 3][i] = new Grid(new Coordinate(lineCount - 3, i), line[i]);
        }
        for (int i = line.length(); i < maxWidth; ++i) {
          layout[lineCount - 3][i] = new Grid(new Coordinate(lineCount - 3, i), ' ');
        }
      }
    }
  }
  catch(int e) {
    std::cout << "Failed to find room file." << std::endl;
  }
  robot = new Robot(this);
  placeRobot();
  inFile.close();

}

void Room::displayRoom() {
  for (auto row : layout) {
    for (auto cell : row) {
      std::cout << cell->getRep();
    }
    std::cout << std::endl << std::flush;
  }
  std::string faceString;
  switch (robot->getDirection()) {
    case Direction::up: faceString = "up"; break;
    case Direction::down: faceString = "down"; break;
    case Direction::left: faceString = "left"; break;
    case Direction::right: faceString = "right"; break;
  }
  std::cout << std::endl<< "Robot is at (" << robotPos->x << ", " << robotPos->y << ") facing " << faceString << '\r' << std::endl;
  std::cout << "Robot has moved " << robotStep << " steps."<< std::flush;
}

Robot* Room::getRobot() {
  return robot;
}

bool Room::robotCanMove() {
  switch (robot->getDirection()) {
    case Direction::down:
      if (robotPos->y + 1 < maxDepth && (layout[robotPos->y + 1][robotPos->x]->getRep() == '.' || layout[robotPos->y + 1][robotPos->x]->getRep() == 'O')) {
        setRobot(false);
        robotPos->y++;
        setRobot(true);
        robotStep++;
        return true;
      }
      return false;
    case Direction::up:
      if (robotPos->y - 1 >= 0 && (layout[robotPos->y - 1][robotPos->x]->getRep() == '.' || layout[robotPos->y - 1][robotPos->x]->getRep() == 'O')) {
        setRobot(false);
        robotPos->y--;
        setRobot(true);
        robotStep++;
        return true;
      }
      return false;
    case Direction::left:
      if (robotPos->x - 1 >= 0 && (layout[robotPos->y][robotPos->x - 1]->getRep() == '.' || layout[robotPos->y][robotPos->x - 1]->getRep() == 'O')) {
        setRobot(false);
        robotPos->x--;
        setRobot(true);
        robotStep++;
        return true;
      }
      return false;
    case Direction::right:
      if (robotPos->x + 1 < maxWidth && (layout[robotPos->y][robotPos->x + 1]->getRep() == '.' || layout[robotPos->y][robotPos->x + 1]->getRep() == 'O')) {
        setRobot(false);
        robotPos->x++;
        setRobot(true);
        robotStep++;
        return true;
      }
      return false;
  }
  return false;
}

void Room::robotClean() {
  if (layout[robotPos->y][robotPos->x]->getObject()->getItem() == Item::dirt) {
    layout[robotPos->y][robotPos->x]->setObject(Item::empty);
  }
}

void Room::placeRobot(Direction dir) {
  bool placed = false;
  while(!placed) {
    srand(time(NULL));
    int x = rand() % maxWidth;
    int y = rand() % maxDepth;
    if (layout[y][x]->getRep() == '.' || layout[y][x]->getRep() == 'O') {
      robotPos = new Coordinate(x, y);
      setRobot(true);
      placed = true;
    }
  }
}

void Room::setRobot(bool b) {
  layout[robotPos->y][robotPos->x]->setRobot(b);
}

Room::~Room() {
  std::vector<std::vector<Grid*>>::iterator it;
  std::vector<Grid*>::iterator it2;
  delete robot;
  delete robotPos;
  for (it = layout.begin(); it != layout.end(); ++it) {
    for (it2 = it->begin(); it2 != it->end(); ++it2) {
      delete (*it2);
    }
  }
  layout.clear();
}
