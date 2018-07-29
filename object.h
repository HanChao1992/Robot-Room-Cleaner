#ifndef _OBJECT_HEADER_
#define _OBJECT_HEADER_

// Item type
enum class Item {
  blank,
  wall,
  empty,
  dirt
};

class Object {
private:
  Item item;

public:
  Object();
  Object(Item item);
  Item getItem();
  void setItem(Item item);
  void itemInfo();
};

#endif
