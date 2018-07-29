#include "robot.h"
#include "room.h"
#include <iostream>


Robot::Robot(Room* room) {
  dir = Direction::up;
  this->room = room;
}

Robot::Robot(Direction dir, Room* room) : dir(dir), room(room) {}

bool Robot::move() {
  usleep(sleepTime);
  clearScreen();
  room->displayRoom();
  return room->robotCanMove();
}

void Robot::clean() {
  room->robotClean();
}

void Robot::turnLeft() {
  switch (dir) {
    case Direction::up: dir = Direction::left; break;
    case Direction::left: dir = Direction::down; break;
    case Direction::down: dir = Direction::right; break;
    case Direction::right: dir = Direction::up; break;
  }
}

void Robot::turnRight() {
  switch (dir) {
    case Direction::up: dir = Direction::right; break;
    case Direction::left: dir = Direction::up; break;
    case Direction::down: dir = Direction::left; break;
    case Direction::right: dir = Direction::down; break;
  }
}

void Robot::clearScreen() {
  std::cout << "\x1B[2J\x1B[H";
}

Direction Robot::getDirection() {
  return dir;
}

void Robot::setDirection(Direction dir) {
  this->dir = dir;
}
