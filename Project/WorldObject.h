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

class WorldObject {

protected:
    Point* position;
    
    
public:
  //  virtual void draw();
   Point* getPosition();
    
};

#endif


