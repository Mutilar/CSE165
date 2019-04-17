#include "Line.h"

Line::Line() {
	//this->start = start;
	//this->end = end;
}

void Line::draw(Point* camera_position) {

    glColor3f(1, 1, 1);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(start->getX() + camera_position->getX(), start->getY() + camera_position->getY());
    glVertex2f(end->getX() + camera_position->getX(), end->getY() + camera_position->getY());
    
    glEnd();
}












