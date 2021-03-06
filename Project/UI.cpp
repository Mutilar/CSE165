#include "UI.h"
#include <iostream>

UI::UI()
{
  // pen = new TexRect("images/pencil-alt-solid.png", 675, 1950, 50, 50);
  line = new TexRect("images/pen-solid.png", 775, 1950, 50, 50);
  eraser = new TexRect("images/eraser-solid.png", 875, 1950, 50, 50);
  select = new TexRect("images/text.png", 2000-785, 2000, 785, 400); 
  // move = new TexRect("images/expand-arrows-alt-solid.png", 1075, 1950, 50, 50);
  // zoom = new TexRect("images/search-solid.png", 1175, 1950, 50, 50);

  // blue = new Tool();
  // red = new Tool();
  // green = new Tool();

  // camera = new Camera();
  // draw_tool = new DrawTool();
}

void UI::draw()
{

  // White Background
  glClearColor(1.0, 1.0, 1.0, 1.0);

  // float blue_points[] = {850, 1850, 25};
  // float red_points[] = {950, 1850, 25};
  // float green_points[] = {1050, 1850, 25};

  // pen->draw(1.0);
  line->draw(1.0);
  eraser->draw(1.0);
  select->draw(1.0);
  // move->draw(1.0);
  // zoom->draw(1.0);
  // blue->draw(blue_points, sizeof(blue_points) / sizeof(*blue_points), new Point(0,0), 57.0/255.0, 149.0/255.0, 253.0/255.0);
  // red->draw(red_points, sizeof(red_points) / sizeof(*red_points), new Point(0,0), 253.0/255.0, 79.0/255.0, 55.0/255.0);
  // green->draw(green_points, sizeof(green_points) / sizeof(*green_points), new Point(0,0), 5.0/255.0, 167.0/255.0, 35.0/255.0);
}

void UI::setDrawState(bool state, int x, int y)
{

}
