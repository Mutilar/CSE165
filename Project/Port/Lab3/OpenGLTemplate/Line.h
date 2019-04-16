#ifndef Line_h
#define Line_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif



#include "Point.h"
#include "WorldObject.h"

class Line : public WorldObject {

private:
    Point* start;
    Point* end;
    
public:
    Line();    
    void draw();
};

#endif



