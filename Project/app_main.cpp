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

using namespace std;

// Store the width and height of the window
int width = 640, height = 640;

// Game* game;

void appDrawScene()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 1.0, 0.0, 1.0);

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(144, 38);
	glVertex2f(148, 30);
	glVertex2f(155, 27);
	glVertex2f(162, 30);
	glVertex2f(166, 38);
	glVertex2f(162, 46);
	glVertex2f(159, 48);
	glVertex2f(151, 48);
	glVertex2f(147, 46);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(109, 88);
	glVertex2f(111, 83);
	glVertex2f(116, 80);
	glVertex2f(119, 71);
	glVertex2f(128, 59);
	glVertex2f(136, 53);
	glVertex2f(149, 49);
	glVertex2f(165, 49);
	glVertex2f(176, 53);
	glVertex2f(184, 59);
	glVertex2f(194, 71);
	glVertex2f(197, 80);
	glVertex2f(202, 83);
	glVertex2f(204, 88);
	glVertex2f(202, 92);
	glVertex2f(199, 95);
	glVertex2f(204, 104);
	glVertex2f(209, 118);
	glVertex2f(209, 126);
	glVertex2f(206, 131);
	glVertex2f(199, 135);
	glVertex2f(191, 136);
	glVertex2f(191, 243);
	glVertex2f(175, 243);
	glVertex2f(218, 287);
	glVertex2f(240, 281);
	glVertex2f(246, 288);
	glVertex2f(216, 316);
	glVertex2f(141, 243);
	glVertex2f(122, 243);
	glVertex2f(122, 136);
	glVertex2f(119, 135);
	glVertex2f(119, 95);
	glVertex2f(114, 94);
	glVertex2f(111, 92);
	glEnd();

	glColor3f(1, 0, 0);

	glBegin(GL_POLYGON);
	glVertex2f(5, 155);
	glVertex2f(35, 160);
	glVertex2f(30, 188);
	glVertex2f(0, 180);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(50, 160);
	glVertex2f(74, 145);
	glVertex2f(88, 166);
	glVertex2f(66, 180);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(95, 142);
	glVertex2f(118, 136);
	glVertex2f(118, 133);
	glVertex2f(133, 133);
	glVertex2f(133, 163);
	glVertex2f(118, 163);
	glVertex2f(102, 166);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(150, 133);
	glVertex2f(163, 133);
	glVertex2f(163, 163);
	glVertex2f(150, 163);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(179, 133);
	glVertex2f(194, 133);
	glVertex2f(194, 163);
	glVertex2f(179, 163);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(206, 109);
	glVertex2f(237, 121);
	glVertex2f(209, 128);
	glEnd();

	glColor3f(1, 1, 1);

	glBegin(GL_POLYGON);
	glVertex2f(119, 80);
	glVertex2f(124, 68);
	glVertex2f(130, 61);
	glVertex2f(143, 53);
	glVertex2f(153, 51);
	glVertex2f(161, 51);
	glVertex2f(175, 56);
	glVertex2f(188, 68);
	glVertex2f(194, 80);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(154, 96);
	glVertex2f(197, 96);
	glVertex2f(205, 113);
	glVertex2f(207, 120);
	glVertex2f(207, 125);
	glVertex2f(204, 130);
	glVertex2f(198, 133);
	glVertex2f(188, 240);
	glVertex2f(125, 240);
	glVertex2f(125, 133);
	glVertex2f(154, 133);
	glEnd();


	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(172, 112);
	glVertex2f(174, 107);
	glVertex2f(179, 105);
	glVertex2f(184, 107);
	glVertex2f(187, 112);
	glVertex2f(185, 117);
	glVertex2f(179, 119);
	glVertex2f(174, 117);
	glEnd();
	// game->step();
	// game->draw();

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments:
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float &x, float &y)
{
	x = (2.0f * (x / float(width))) - 1.0f;
	y = 1.0f - (2.0f * (y / float(height)));
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
	const double appXmax = 350.0;
	const double appYmin = 0.0;
	const double appYmax = 350.0;

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

	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments:
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y)
{

	// Again, we redraw the scene
	glutPostRedisplay();
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

	if (key == 27)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			delete shapes[i];
		}
		exit(0);
	}

	// After all the state changes, redraw the scene
	glutPostRedisplay();
}

void idle()
{
}

int main(int argc, char **argv)
{

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("LineRider++");

	// game = new Game();

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
