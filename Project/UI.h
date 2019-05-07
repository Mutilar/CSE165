#ifndef UI_h
#define UI_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <vector>

#include "Tool.h"
#include "Player.h"
#include "DrawTool.h"
#include "Camera.h"
#include "Line.h"
#include "TexRect.h"

class UI {

protected:
  TexRect *pen, *line, *eraser, *select, *move, *zoom;
  Tool *blue, *red, *green;
  DrawTool* draw_tool;
  Camera *camera;
  
  std::vector<Line *> lines;

public:
  UI();
  void draw();

  DrawTool* getDrawTool();
  std::vector<Line *> getLines();
  void setDrawState(bool state, int x, int y);
};

#endif
