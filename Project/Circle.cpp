#include "Circle.h"

#include <vector>
#include <cmath>

void Circle::draw(float x, float y, float r)
{
  glEnable(GL_POINT_SMOOTH);
  glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(x, y, 0.0f);
  static const int circle_points = 100;
  static const float angle = 2.0f * 3.1416f / circle_points;

  glBegin(GL_POLYGON);
  double angle1 = 0.0;
  glVertex2d(r * cos(0.0), r * sin(0.0));
  int i;
  for (i = 0; i < circle_points; i++)
  {
    glVertex2d(r * cos(angle1), r * sin(angle1));
    angle1 += angle;
  }
  glEnd();
  glPopMatrix();
}