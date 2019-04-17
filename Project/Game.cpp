#include "Game.h"

Game::Game() {
   world = new World();
   timer(0);
}

void Game::draw() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   world->draw();

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glFlush();
	glutSwapBuffers();
  
   
}
void Game::step() {
   world->step();
}

void Game::timer(int id) {
    
   this->step();
	this->draw();
	cout << "...\n";
   glutTimerFunc(1000, this->timer, id);
}