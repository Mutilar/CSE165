#ifndef World_h
#define World_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


#include <vector>
#include "Player.h"
#include "DrawTool.h"
#include "Camera.h"
#include "Line.h"

class World {

protected:
    Player* player;
    Camera* camera;
    std::vector<Line*> lines;
    
public:

    DrawTool* draw_tool;
    World();
    void draw();
    void step(bool state);
    void moveCamera(char input);
    Point* getCamera();
    DrawTool* getDrawTool();
    std::vector<Line*> getLines();
    void setDrawState (bool state, int x, int y);    
};

#endif



