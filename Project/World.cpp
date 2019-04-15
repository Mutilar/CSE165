#include "World.h"

World::World() {
   player = new Player();
}

void World::draw() {

   // White Background
   glClearColor(1.0, 1.0, 1.0, 1.0);

   player->draw();//camera->getPosition());
//	for line in lines
//
//		line->draw();
}








