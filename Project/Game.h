#ifndef Game_h
#define Game_h

#include "World.h"

class Game {

protected:
    World world;
    
public:
    Game();
    void step();
    void click();
    void togglePause();
    
};

#endif



