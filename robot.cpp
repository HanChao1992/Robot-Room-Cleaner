#include "robot.h"
#include "room.h"


Robot::Robot(Room* room) {
  dir = Direction::up;
  this->room = room;
}

Robot::Robot(Direction dir, Room* room) : dir(dir), room(room) {}

bool Robot::move() {
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

Direction Robot::getDirection() {
  return dir;
}

void Robot::setDirection(Direction dir) {
  this->dir = dir;
}
