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
    DrawTool* draw_tool;
    Camera* camera;

    std::vector<Line*> lines;
    
public:
    World();
    void draw();
    void step();

    DrawTool* getDrawTool();
    
};

#endif



