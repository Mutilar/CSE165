#include "UI.h"
#include <iostream>

UI::UI()
{
  pen = new TexRect("images/pencil-alt-solid.png", 400, 2000, 75, 75);
  line = new TexRect("images/pen-solid.png", 600, 2000, 75, 75);
  eraser = new TexRect("images/eraser-solid.png", 800, 2000, 75, 75);
  select = new TexRect("images/mouse-pointer-solid.png", 1000, 2000, 75, 75); 
  move = new TexRect("images/expand-arrows-alt-solid.png", 1200, 2000, 75, 75);
  zoom = new TexRect("images/search-solid.png", 1400, 2000, 75, 75);

  blue = new Tool();
  red = new Tool();
  green = new Tool();

  camera = new Camera();
  draw_tool = new DrawTool();
}

void UI::draw()
{

  // White Background
  glClearColor(1.0, 1.0, 1.0, 1.0);

  // bottom left :: (0,0)
  // top right :: (2480, 2000)
  float blue_points[] = {700, 1800, 50};
  float red_points[] = {900, 1800, 50};
  float green_points[] = {1100, 1800, 50};

  pen->draw(1.0);
  line->draw(1.0);
  eraser->draw(1.0);
  select->draw(1.0);
  move->draw(1.0);
  zoom->draw(1.0);
  blue->draw(blue_points, sizeof(blue_points) / sizeof(*blue_points), camera->getPosition(), 57.0/255.0, 149.0/255.0, 253.0/255.0);
  red->draw(red_points, sizeof(red_points) / sizeof(*red_points), camera->getPosition(), 253.0/255.0, 79.0/255.0, 55.0/255.0);
  green->draw(green_points, sizeof(green_points) / sizeof(*green_points), camera->getPosition(), 5.0/255.0, 167.0/255.0, 35.0/255.0);
}

DrawTool *UI::getDrawTool()
{
  return this->draw_tool;
}

std::vector<Line*> UI::getLines()
{
  return this->lines;
}

void UI::setDrawState(bool state, int x, int y)
{

}
