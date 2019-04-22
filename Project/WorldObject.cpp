#include "WorldObject.h"

Point *WorldObject::getPosition()
{
    return this->position;
}
void WorldObject::setPosition(float x, float y)
{
    this->position->setX(x);
    this->position->setY(y);
}
void WorldObject::setPosition(Point *point)
{
    this->position->setX(point->getX());
    this->position->setY(point->getY());
}

float WorldObject::getPositionX()
{
    return this->position->getX();
}
float WorldObject::getPositionY()
{
    return this->position->getY();
}
void WorldObject::setPositionX(float x)
{
    this->position->setX(x);
}
void WorldObject::setPositionY(float y)
{
    this->position->setY(y);
}

void WorldObject::shift(Point *direction)
{
    this->position->shiftX(direction->getX());
    this->position->shiftY(direction->getY());
}