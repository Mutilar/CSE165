#include "World.h"
#include <iostream>

World::World() {
   player = new Player();
   camera = new Camera();
}

void World::draw() {

   // White Background
   glClearColor(1.0, 1.0, 1.0, 1.0);

   player->draw(camera->getPosition());
   camera->setPosition(camera->getPosition()->getX() + 1, 100);
   // std::cout << camera->getPosition()->getX() << "\n";
//	for line in lines
//
//		line->draw();
}

void World::step() {
   
}






