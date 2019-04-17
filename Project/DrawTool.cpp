#include "DrawTool.h"
#include <iostream>

DrawTool::DrawTool() {
    ghost_line = new Line();
    // this.lines = new
}
void DrawTool::draw(std::vector<Line*> lines, Point* camera_position) {
    ghost_line->draw(camera_position);
    for(std::vector<Line*>::iterator it = lines.begin(); it != lines.end(); ++it) {
       std::cout << "test\n";
       Line* temp_line = *it;
       temp_line->draw(camera_position);
    }
}
void DrawTool::drag(int x, int y) {
    ghost_line->setEndPoint(x, y);
}


void DrawTool::setState(std::vector<Line*> &lines, bool state, int x, int y) {
    this->state = state;
    if (state == true) {
        ghost_line->setStartPoint(x, y);
    }
    else {
        lines.push_back(new Line(ghost_line->getStartPoint()->getX(), ghost_line->getStartPoint()->getY(), ghost_line->getEndPoint()->getX(), ghost_line->getEndPoint()->getY()));
        std::cout << "pushing";
    }
} 
