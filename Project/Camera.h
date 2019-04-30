#ifndef Camera_h
#define Camera_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "WorldObject.h"
#include "Point.h"

class Camera : public WorldObject {

private:
    
public:
    Camera();
    void draw();  
    void step();
};

#endif