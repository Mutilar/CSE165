#ifndef Game_h
#define Game_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

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



