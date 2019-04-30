#ifndef Rect_h
#define Rect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Rect
{

public:
  Rect();

  void draw(float x, float y, float w, float h);
};

#endif