#ifndef World_h
#define World_h

#include <vector>
#include "Player.h"
#include "DrawTool.h"
#include "Line.h"

class World {

protected:
    Player* player;
    DrawTool* draw_tool;
    Line line;
//    std::vector<Line> lines;
    
public:
    World();
    void draw();
    
};

#endif



