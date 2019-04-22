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
#include <vector>
#include "Line.h"

class Player : public WorldObject
{

  private:
    float rotation; //in degrees, probably
    Point* velocity;

    Point *left_raycast_start;
    Point *middle_raycast_start;
    Point *right_raycast_start;

    Point *left_raycast_end;
    Point *middle_raycast_end;
    Point *right_raycast_end;

    void drawSet(int *points, int num_points, Point *camera_position, int r, int g, int b);

  public:
    Player();
    Point getPosition();
    // void setPosition(Point position);
    void draw(Point *camera_position);
    void step(std::vector<Line *> &lines); //adjusts rotation, velocity based on raycasts

    bool IsIntersecting(Point *a, Point *b, Point *c, Point *d);
    void drawRaycast(Point *start, Point *end, Point *camera_position);

    Point* toRelativeSpace(Point *point);
};

#endif
