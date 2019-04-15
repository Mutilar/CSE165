#ifndef Game_h
#define Game_h

#include "World.h"

class Game {


private:
    World world;

    bool is_paused;
    
public:
    Game();
    void step();
    void click();
    void togglePause();
    
};

#endif



