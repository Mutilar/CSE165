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

class Player: public WorldObject {

private:
    float rotation; //in degrees, probably
    
public:
    Player();
    Point getPosition();
    void setPosition(Point position);
    void draw();  
    void draw(Point* camera_position);    
};

#endif



