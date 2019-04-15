#ifndef Game_h
#define Game_h

#include "Line.h"
#include "World.h"



class Game {


private:
    World* world;

    bool is_paused;
    
public:
    Game();
    void draw();
    void step();
    void click();
    void togglePause();
    
};

#endif



