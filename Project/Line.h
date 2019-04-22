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

class Line : public WorldObject
{

  private:
    Point *start;
    Point *end;

  public:
    Line();
    Line(float x1, float y1, float x2, float y2);
    Line(Point* start, Point* end);
    void draw(Point *camera_position);
    void setStartPoint(float x, float y);
    void setEndPoint(float x, float y);

    Point* getStartPoint();
    Point* getEndPoint();
};

#endif
