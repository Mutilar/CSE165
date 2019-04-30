#include "Rect.h"

#include <vector>
#include <cmath>

void Rect::draw(float x, float y, float w, float h)
{
  glBegin(GL_LINES);

  glVertex2f(x, y);
  glVertex2f(x + w, y);

  glVertex2f(x + w, y);
  glVertex2f(x + w, y - h);

  glVertex2f(x + w, y - h);
  glVertex2f(x, y - h);

  glVertex2f(x, y - h);
  glVertex2f(x, y);

  glEnd();
}