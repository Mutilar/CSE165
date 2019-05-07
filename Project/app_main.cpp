#include <iostream>
#include <vector>
#include <cmath>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Game.h"

using namespace std;

// Store the width and height of the window
int width = 2000, height = 2000;

Game *game;
bool is_running = true;

void appDrawScene()
{
	game->draw();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments:
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float &x, float &y)
{
	x = x / float(width) * 2000;

	y = y / float(height) * 2000;
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h)
{
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = 0.0;
	const double appXmax = 2000.0;
	const double appYmin = 0.0;
	const double appYmax = 2000.0;

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

//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y)
{
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	// cout << "button: " << b << endl;
	// cout << "state: " << s << endl;
	// cout << "x: " << mx << endl;
	// cout << "y: " << my << endl;

	game->mouseDown(b, s, (int)mx, 2000 - (int)my);
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments:
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y)
{
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	game->mouseDrag((int)mx, 2000 - (int)my);
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments:
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case ' ':
		// TODO: restart game and make a new blank drawing board
		game = new Game();
		cout << "restarting the world" << endl;
		break;
	case 'p':
		is_running = false;
		cout << "pausing the game" << endl;
		break;
	case 'o':
		is_running = true;
		cout << "unpausing the game" << endl;
		break;
	case 'w':
	case 'a':
	case 's':
	case 'd':
		// TODO: check for arrow, wasd keys to shift camera position manually (versus staying on player)
		// camera->rePosition();
		cout << "moving camera" << endl;
		break;
	}

	// After all the state changes, redraw the scene
	glutPostRedisplay();
}

void idle() {}

void timer(int id)
{
	game->step(is_running);
	game->draw();
	glutTimerFunc(50, timer, id);
}

int main(int argc, char **argv)
{

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("LineRider++");

	game = new Game();
	timer(0);

	// glutSetOption(GLUT_MULTISAMPLE, 8);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glPointSize(5);
	glutDisplayFunc(appDrawScene);
	glutReshapeFunc(appReshapeFunc);
	glutMouseFunc(appMouseFunc);
	glutIdleFunc(idle);
	glutMotionFunc(appMotionFunc);
	glutKeyboardFunc(appKeyboardFunc);
	glutMainLoop();
}
