#include "WorldObject.h"

Point *WorldObject::getPosition()
{
    return this->position;
}
void WorldObject::setPosition(int x, int y)
{
    this->position->setX(x);
    this->position->setY(y);
}
void WorldObject::setPosition(Point *point)
{
    this->position->setX(point->getX());
    this->position->setY(point->getY());
}

int WorldObject::getPositionX()
{
    return this->position->getX();
}
int WorldObject::getPositionY()
{
    return this->position->getY();
}
void WorldObject::setPositionX(int x)
{
    this->position->setX(x);
}
void WorldObject::setPositionY(int y)
{
    this->position->setY(y);
}

void WorldObject::shift(Point *direction)
{
    this->position->shiftX(direction->getX());
    this->position->shiftY(direction->getY());
}