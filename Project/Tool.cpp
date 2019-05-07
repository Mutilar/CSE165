#include <iostream>
#include <vector>
#include <math.h>

#include "Tool.h"

Tool::Tool()
{
	this->position = new Point(200, 2000);
	this->rotation = 0;
}

Point *Tool::toRelativeSpace(Point *point)
{
	return new Point(this->getPositionX() + cos(rotation) * point->getX() + sin(rotation) * point->getY(), this->getPositionY() + -sin(rotation) * point->getX() + cos(rotation) * point->getY());
}

void Tool::draw(float *points, int num_points, Point *camera_position, float r, float g, float b)
{
	glColor3f(r, g, b);

	switch (num_points)
	{
	case 2:
	{
		// line->draw(points[0], points[1]);
	}
	case 3:
	{
		circle->draw(points[0], points[1], points[2]);
		break;
	}
	case 4:
	{
		rect->Circle(points[0], points[1], points[2], points[3]);
		break;
	}
	default:
		break;
	}
}
