#include "Game.h"

Game::Game() {
   world = new World();
}

void Game::draw() {

   world->draw();
   
}
void Game::step() {

}
