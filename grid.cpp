#include <iostream>
#include "grid.h"


Grid::Grid(Coordinate* coord, Object *object) {
  coordinate = coord;
  this->object = object;
  hasRobot = false;
  setRep();
}

Grid::Grid(Coordinate* coord, char rep) {
  coordinate = coord;
  this->rep = rep;
  hasRobot = false;
  generateObject();
}

Coordinate const* Grid::getCoordinate() {
  return coordinate;
}

Object* Grid::getObject() {
  return object;
}

void Grid::setObject(Item item) {
  object->setItem(item);
}


void Grid::generateObject() {
  switch (rep) {
    case ' ' : object = new Object(Item::blank); break;
    case 'W' : object = new Object(Item::wall); break;
    case '.' : object = new Object(Item::empty); break;
    case 'O' : object = new Object(Item::dirt); break;
  }
}

void Grid::setRep() {
  if (hasRobot) {
    rep = '@';
  }
  else {
    switch (object->getItem()) {
      case Item::blank : rep = ' '; break;
      case Item::wall : rep = 'W'; break;
      case Item::empty : rep = '.'; break;
      case Item::dirt : rep = 'O'; break;
    }
  }
}

char Grid::getRep() {
  return rep;
}

void Grid::setRobot(bool b) {
  hasRobot = b;
  setRep();
}

void Grid::gridInfo() {
  std::cout << "A " << rep << " at (" << coordinate->x << ", " << coordinate->y << ")." << std::endl;
}

Grid::~Grid() {
  delete coordinate;
  delete object;
}
