#ifndef _GRID_HEADER_
#define _GRID_HEADER_

#include "object.h"

struct Coordinate {
  int x, y;
  Coordinate(int x, int y) : x(x), y(y) {}
};

class Grid {
private:
  Coordinate const *coordinate;
  Object *object;
  char rep;
  bool hasRobot;

public:
  Grid(Coordinate* coord, Object *object);
  Grid(Coordinate* coord, char rep);
  Coordinate const* getCoordinate();
  Object *getObject();
  void setObject(Item item);
  void generateObject();
  void setRep();
  char getRep();
  void setRobot(bool b);
  void gridInfo();
  ~Grid();
};

#endif
