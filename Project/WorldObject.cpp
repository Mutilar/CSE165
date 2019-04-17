#include "WorldObject.h"

Point* WorldObject::getPosition() {
    return this->position;
}
void WorldObject::setPosition(int x, int y) {
    this->position->setX(x);
    this->position->setY(y);
}
