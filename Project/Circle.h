#ifndef Circle_h
#define Circle_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Circle
{

public:
  Circle();

  void draw(float x, float y, float r);
};

#endif