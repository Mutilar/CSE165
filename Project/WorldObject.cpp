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

int WorldObject::getPositionX() {
    return this->position->getX();
}
int WorldObject::getPositionY() {
    return this->position->getY();
}
