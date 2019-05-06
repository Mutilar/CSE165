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

   player->draw(camera->getPosition());

   draw_tool->draw(this->lines, camera->getPosition());

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
   this->draw_tool->setState(this->lines, state, x, y);
}