#include "DrawTool.h"

DrawTool::DrawTool() {
    // this.lines = new
}
void DrawTool::draw(Point* camera_position) {
    for(std::vector<Line>::iterator it = this->lines.begin(); it != this->lines.end(); ++it) {
        it->draw(camera_position);
    }
}
void DrawTool::setState(bool state) {
    this->state = state;
} 

