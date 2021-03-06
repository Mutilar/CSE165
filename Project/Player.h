#ifndef Player_h
#define Player_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "WorldObject.h"
#include "Point.h"
#include "Line.h"
#include "TexRect.h"

#include <vector>

class Player : public WorldObject
{
  private:
    float rotation; //in degrees, probably
    Point* velocity;
    Line *clipping_ray;
    Line *ground_check_ray;
    TexRect* PlayerBody;

  public:
    Player();
    Point getPosition();
    void draw(Point *camera_position);
    void step(std::vector<Line *> &lines);
    Line* getIntersectingLine(std::vector<Line *> &lines, Line* ray);
    bool IsIntersecting(Line* a, Line* b);
    bool IsIntersecting(Point *a, Point *b, Point *c, Point *d);
    void drawRaycast(Point *start, Point *end, Point *camera_position);
    Point* toRelativeSpace(Point *point);
    Line* toRelativeSpace(Line *line);
};

#endif
