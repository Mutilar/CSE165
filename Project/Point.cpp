#include "Point.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getX()
{
	return this->x;
}
int Point::getY()
{
	return this->y;
}
void Point::setX(int x)
{
	this->x = x;
}
void Point::setY(int y)
{
	this->y = y;
}
void Point::shiftX(int x_adj)
{
	this->x += x_adj
}
void Point::shiftY(int y_adj)
{
	this->y += y_adj;
}
