#include "Circle.h"

#include <vector>
#include <cmath>

void Circle::draw(float x, float y, float r)
{
  glBegin(GL_LINES);

  float inc = 0.1;

  for (float theta = 0; theta < 2 * M_PI; theta += inc)
  {
    glVertex2f(r * cos(theta) + x, r * sin(theta) + y);
    glVertex2f(r * cos(theta + inc) + x, r * sin(theta + inc) + y);
  }

  glEnd();
}