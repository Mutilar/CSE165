#include "Line.h"
#include <iostream>

Line::Line()
{
    this->start = new Point(0, 0);
    this->end = new Point(0, 0);
}

Line::Line(float  x1, float  y1, float  x2, float  y2)
{
    this->start = new Point(x1, y1);
    this->end = new Point(x2, y2);
}
Line::Line(Point* start, Point* end)
{
    this->start = start;
    this->end = end;
}

void Line::draw(Point *camera_position)
{
    glLineWidth(1000);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(start->getX() + camera_position->getX(), start->getY() + camera_position->getY());
    glVertex2f(end->getX() + camera_position->getX(), end->getY() + camera_position->getY());
    glEnd();
}
void Line::setStartPoint(float x, float y)
{
    this->start->setX(x);
    this->start->setY(y);
}
void Line::setEndPoint(float x, float y)
{
    this->end->setX(x);
    this->end->setY(y);
}
Point* Line::getStartPoint() {
    return this->start;
}
Point* Line::getEndPoint() {
    return this->end;
}
