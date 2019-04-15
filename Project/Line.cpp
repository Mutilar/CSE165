#include "Line.h"

Line::Line() {
	//this->start = start;
	//this->end = end;
}

void Line::draw() {

    glColor3f(1, 1, 1);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(start->getX(), start->getY());
    glVertex2f(end->getX(), end->getY());
    
    glEnd();
}












