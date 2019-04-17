#ifndef DrawTool_h
#define DrawTool_h

#include "Line.h"
#include <vector>

class DrawTool {

private:
    std::vector<Line> lines;
    bool state;

public:
    DrawTool();
    void draw(Point* camera_position); 
    void setState(bool state); 
    
};

#endif



