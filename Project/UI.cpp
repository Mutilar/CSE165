#include "UI.h"
#include <iostream>

UI::UI()
{
  pen = new Tool();
  line = new Tool();
  eraser = new Tool();
  select = new Tool(); 
  move = new Tool();
  zoom = new Tool();
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
  float pen_points[] = {400, 2000, 100, 100};
  float line_points[] = {600, 2000, 100, 100};
  float eraser_points[] = {800, 2000, 100, 100};
  float select_points[] = {1000, 2000, 100, 100};
  float move_points[] = {1200, 2000, 100, 100};
  float zoom_points[] = {1400, 2000, 100, 100};
  float blue_points[] = {900, 1800, 50};
  float red_points[] = {1100, 1800, 50};
  float green_points[] = {1300, 1800, 50};

  pen->draw(pen_points, sizeof(pen_points) / sizeof(*pen_points), camera->getPosition(), 0, 0, 0);
  line->draw(line_points, sizeof(line_points) / sizeof(*line_points), camera->getPosition(), 0, 0, 0);
  eraser->draw(eraser_points, sizeof(eraser_points) / sizeof(*eraser_points), camera->getPosition(), 0, 0, 0);
  select->draw(select_points, sizeof(select_points) / sizeof(*select_points), camera->getPosition(), 0, 0, 0);
  move->draw(move_points, sizeof(move_points) / sizeof(*move_points), camera->getPosition(), 0, 0, 0);
  zoom->draw(zoom_points, sizeof(zoom_points) / sizeof(*zoom_points), camera->getPosition(), 0, 0, 0);
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
