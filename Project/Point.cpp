#include "Point.h"

Point::Point(float  x, float  y)
{
	this->x = x;
	this->y = y;
}

float  Point::getX()
{
	return this->x;
}
float  Point::getY()
{
	return this->y;
}
void Point::setX(float  x)
{
	this->x = x;
}
void Point::setY(float  y)
{
	this->y = y;
}
void Point::shiftX(float  x_adj)
{
	this->x += x_adj;
}
void Point::shiftY(float  y_adj)
{
	this->y += y_adj;
}
