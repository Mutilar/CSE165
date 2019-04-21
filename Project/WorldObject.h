#ifndef WorldObject_h
#define WorldObject_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Point.h"

class WorldObject
{

protected:
  Point *position;

public:
  //  virtual void draw();n
  Point *getPosition();
  int getPositionX();
  int getPositionY();

  void setPosition(int x, int y);
  void setPosition(Point* point);
  void setPositionX(int x);
  void setPositionY(int y);
  void shift(Point* direction);
};

#endif
