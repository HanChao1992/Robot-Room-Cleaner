#include <iostream>
#include "object.h"


Object::Object() {
  item = Item::blank;
}

Object::Object(Item item) : item(item) {}

Item Object::getItem() {
  return item;
}

void Object::setItem(Item item) {
  this->item = item;
}

void Object::itemInfo() {
  switch (item) {
    case Item::blank : std::cout << "This is a blank tile." << std::endl; break;
    case Item::wall : std::cout << "This is a wall tile." << std::endl; break;
    case Item::empty : std::cout << "This is a empty tile." << std::endl; break;
    case Item::dirt : std::cout << "This is a dirt tile." << std::endl; break;
  }
}
