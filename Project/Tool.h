#ifndef Tool_h
#define Tool_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <vector>

#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

class Tool : public WorldObject
{

  private:
    float rotation;
    Circle *circle;
    Rect *rect;
    Line *line;

  public:
    Tool();

    void draw(float *points, int num_points, Point *camera_position, float r, float g, float b);
    void drawImage(const char*, float *points, int num_points, Point *camera_position, float r, float g, float b);

    Point* toRelativeSpace(Point *point);
};

#endif
