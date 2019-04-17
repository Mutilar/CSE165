#include "Game.h"

Game::Game()
{
	world = new World();
}

void Game::draw()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	world->draw();

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glFlush();
	glutSwapBuffers();
}
void Game::step()
{
	world->step();
}

void Game::mouseDown(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON)
	{

		//Check for if clicked on UI element

		//else
		{

			world->getDrawTool()->setState( world->getLines(), !s, x, y);
		}
	}

	//
	//glutPostRedisplay();
}
void Game::mouseDrag(int x, int y)
{
	world->getDrawTool()->drag(x, y);
	//glutPostRedisplay();
}
