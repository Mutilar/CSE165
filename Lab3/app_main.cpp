#include <iostream>
#include <cmath>
#include <list>
#include <stdlib.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

int width = 640, height = 640;

struct Position {
    float x, y;
    float r,g,b;
    float radius;

} last_point, draw_location,erase_point;

bool operator==(const Position a, const Position& b) {
    return (a.x == b.x && a.y == b.y);
}

class Brush 
{ 
    private:
    float r,g,b;
    float radius;
    
    std::list<Position> points;

    bool drawing; 
    bool erasing;
    bool willDraw;

    bool rainbow_effect = false;
    bool size_effect = false;
  
    public: 
    void setRainbow(bool flag) { rainbow_effect = flag; }
    void setSizeEffect(bool flag) { size_effect = flag; }
    void setRGB(float r_in, float g_in, float b_in) { r = r_in; g = g_in; b = b_in; }
    void setRadius(float radius_in) { radius = radius_in; }
    float getRadius() { return radius; }
    void draw (bool flag) { drawing = flag; }
    void erase (bool flag) { erasing = flag; }
    bool isDrawing() { return drawing; }
    bool isErasing() { return erasing; }
    bool isFarEnough(float x, float y) {
        if (distance(x, last_point.x, y, last_point.y) >= radius / 2) {
            last_point.x = x;
            last_point.y = y;
            last_point.r = r;
            last_point.g = g;
            last_point.b = b;
            last_point.radius = radius;
            if (rainbow_effect) { setRGB((rand() % 255) / 255.0,(rand() % 255) / 255.0,(rand() % 255) / 255.0); }
            if (size_effect) { setRadius((rand() % 255) / 2550.0); }
            points.push_front(last_point);
            return true;
        }
        return false;
    }
    void erase(float x, float y) {
        std::list<Position> shift_points;
        for (std::list<Position>::iterator it = points.begin(); it!=points.end(); ++it) {
            if (distance(x, (*it).x, y, (*it).y) > (*it).radius) {
                shift_points.push_back(*it);
            }
        }
        points = shift_points;
    }

    list<Position> getPoints() { return points; }


    protected:
    float distance(float x1, float x2, float y1, float y2) { return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); }

}; 
Brush *brush;


void appDrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float theta;
    float thetaInc = M_PI / 20;

    list<Position> points_to_draw = brush->getPoints();
    while (points_to_draw.empty() == false) {
        draw_location = points_to_draw.front();
        glColor3f(draw_location.r, draw_location.g, draw_location.b);
        glBegin(GL_POLYGON);
        for (theta = 0; theta < 2.0 * M_PI; theta += thetaInc)
        {
            glVertex2f((draw_location.radius)*cos(theta) + draw_location.x, (draw_location.radius)*sin(theta) + draw_location.y);
        }
        glEnd();

        points_to_draw.pop_front();
    }
    glFlush();
    glutSwapBuffers();
}

void windowToScene(float &x, float &y)
{
    x = (2.0f * (x / float(width))) - 1.0f;
    y = 1.0f - (2.0f * (y / float(height)));
}
void appReshapeFunc(int w, int h)
{
    // Window size has changed
    width = w;
    height = h;

    double scale, center;
    double winXmin, winXmax, winYmin, winYmax;

    // Define x-axis and y-axis range
    const double appXmin = -1.0;
    const double appXmax = 1.0;
    const double appYmin = -1.0;
    const double appYmax = 1.0;

    // Define that OpenGL should use the whole window for rendering
    glViewport(0, 0, w, h);

    // Set up the projection matrix using a orthographic projection that will
    // maintain the aspect ratio of the scene no matter the aspect ratio of
    // the window, and also set the min/max coordinates to be the disered ones
    w = (w == 0) ? 1 : w;
    h = (h == 0) ? 1 : h;

    if ((appXmax - appXmin) / w < (appYmax - appYmin) / h)
    {
        scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
        center = (appXmax + appXmin) / 2;
        winXmin = center - (center - appXmin) * scale;
        winXmax = center + (appXmax - center) * scale;
        winYmin = appYmin;
        winYmax = appYmax;
    }
    else
    {
        scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
        center = (appYmax + appYmin) / 2;
        winYmin = center - (center - appYmin) * scale;
        winYmax = center + (appYmax - center) * scale;
        winXmin = appXmin;
        winXmax = appXmax;
    }

    // Now we use glOrtho to set up our viewing frustum
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}
void appMouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        brush->draw(!state);
    }
    if (button == GLUT_RIGHT_BUTTON) {
        brush->erase(!state);
    }
    appDrawScene();
    glutPostRedisplay();
}
void appMotionFunc(int x, int y)
{
    float mx = (float)x;
    float my = (float)y;
    windowToScene(mx, my);
    if (brush->isDrawing()) {
        if (brush->isFarEnough(mx, my)) { }
    }
    if (brush->isErasing()) {
        brush->erase(mx, my);
    }
    glutPostRedisplay();
}
void appKeyboardFunc(unsigned char key, int x, int y)
{
    float r, g, b;
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'r':
	   cout << "ENTER RADIUS VALUE:\n";
       cin >> r;
       brush->setRadius(r);
    break;
    case 'c':
        cout << "ENTER R, G, B on separate lines:\n";
        cin >> r;
        cin >> g;
        cin >> b;
        brush->setRGB(r, g, b);
    break;
    default:
	   cout << key;
    break;
    }
    // After all the state changes, redraw the scene
    glutPostRedisplay();
}

void idle()
{
}

int main(int argc, char **argv)
{
    cout << "Welcome to GLPaint\n";
    
    brush = new Brush();

    brush->setRGB(1,.5,.25); 
    brush->setRadius(.05);

    // brush->setRainbow(true);
    // brush->setSizeEffect(true);

    //brush ;

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    // Setup window position, size, and title
    glutInitWindowPosition(20, 60);
    glutInitWindowSize(width, height);
    glutCreateWindow("CSE165 GL Paint");

    // Setup some OpenGL options
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);

    // Set callback for drawing the scene
    glutDisplayFunc(appDrawScene);

    // Set callback for resizing th window
    glutReshapeFunc(appReshapeFunc);

    // Set callback to handle mouse clicks
    glutMouseFunc(appMouseFunc);

    // Set callback to handle mouse dragging
    glutMotionFunc(appMotionFunc);

    // Set callback to handle keyboad events
    glutKeyboardFunc(appKeyboardFunc);

    glutIdleFunc(idle);

    // Start the main loop
    glutMainLoop();
}
