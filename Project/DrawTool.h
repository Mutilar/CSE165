#ifndef DrawTool_h
#define DrawTool_h

#include "Line.h"
#include <vector>

class DrawTool {

private:
    Line* ghost_line;
    bool state;
    int start_x, start_y, current_x, current_y;

public:
    DrawTool();
    void draw(std::vector<Line*> lines, Point* camera_position); 
    void drag (int x, int y, Point* camera_position);
    void setState(std::vector<Line*> &lines, bool state, int x, int y, Point* camera_position); 
};

#endif



