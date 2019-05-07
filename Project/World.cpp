#include "World.h"
#include <iostream>

World::World()
{
   player = new Player();
   camera = new Camera();
   draw_tool = new DrawTool();
}

void World::draw()
{

   // White Background
   glClearColor(1.0, 1.0, 1.0, 1.0);


   draw_tool->draw(this->lines, camera->getPosition());

   player->draw(camera->getPosition());
   // camera->setPosition(camera->getPosition()->getX() + 1, 100);
}

DrawTool *World::getDrawTool()
{
   return this->draw_tool;
}

void World::step(bool state)
{
   if (state)
   {
      player->step(this->lines);
      camera->step();
   }
}

std::vector<Line *> World::getLines()
{
   return this->lines;
}

void World::setDrawState(bool state, int x, int y)
{
   this->draw_tool->setState(this->lines, state, x, y, camera->getPosition());
}


void World::moveCamera(char input) {
	switch (input) {
      case 'w':
      this->camera->shift(new Point(0,-100));
      break;
      case 'a':
      this->camera->shift(new Point(100,0));
      break;
      case 's':
      this->camera->shift(new Point(0,100));
      break;
      case 'd':
      this->camera->shift(new Point(-100,0));
      break;
   }
   

}


Point* World::getCamera() {
   return this->camera->getPosition();
}