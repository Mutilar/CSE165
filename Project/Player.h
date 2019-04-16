#ifndef Player_h
#define Player_h

#include "Point.h"

class Player {

private:
    Point* position;
    float rotation; //in degrees, probably
    
public:
    Player(Point* position);
    Point getPosition();
    void setPosition(Point position);
    void draw(Point camera_position);    
};

#endif



