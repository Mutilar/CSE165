#include "Game.h"

Game::Game()
{
	world = new World();
	ui = new UI();
}

void Game::draw()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	world->draw();
	ui->draw();

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glFlush();
	glutSwapBuffers();
}

void Game::step(bool state)
{
	world->step(state);
}

void Game::mouseDown(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON)
	{
		bool is_on_ui = false;
		if (x > 775 - 50 && x < 775 + 50)
		{
			if (y > 1950 - 50 && y < 1950 + 50)
			{
				is_on_ui = true;
				cout << "Selected Pencil....\n";
				world.draw_tool.erasing = false;
			}
		}
		if (x > 875 - 50 && x < 875 + 50)
		{
			if (y > 1950 - 50 && y < 1950 + 50)
			{
				is_on_ui = true;
				cout << "Selected Eraser....\n";
				world.draw_tool.erasing = true;
			}
		}
		if (!is_on_ui)
		{
			world->setDrawState(!s, x, y);
		}
	}
}

void Game::mouseDrag(int x, int y)
{
	world->getDrawTool()->drag(x, y, world->getCamera());
}

void Game::moveCamera(char input)
{
	world->moveCamera(input);
}