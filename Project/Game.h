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
#include "UI.h"

class Game
{
private:
    World *world;
    UI *ui;
    bool is_paused;

public:
    Game();
    void draw();
    void step(bool state);
    void moveCamera(char input);
    void mouseDown(int b, int s, int x, int y);
    void mouseDrag(int x, int y);
    void togglePause();
};

#endif