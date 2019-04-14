#ifndef World_h
#define World_h

#include "Player.h"
#include "Line.h"

class World {

protected:
    Player player;
    vector<Line> lines;
    
public:
    World();
    
};

#endif



