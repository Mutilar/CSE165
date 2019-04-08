#include <iostream>
#include "App.h"

App* singleton;

void timer(int id){
    singleton->draw();
    glutTimerFunc(16, timer, id);
}

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
   singleton = this;
   x_animated = 0;
   cat = new AnimatedRect("cat.png", 4, 2, 100,true,false, -.25, -.25, 1, .5);
   cat->playLoop();
   timer(0);
}

void App::draw() {
	x_animated += .1;
 	TexRect* tex_1  = new TexRect("bg.png", -2 + x_animated, 1, 4, 2);
 	TexRect* tex_2  = new TexRect("bg.png", -6 + x_animated, 1, 4, 2);
 	tex_1->draw(0);
 	tex_2->draw(0);
	cat->draw(1);
 	if (x_animated >= 4) x_animated = 0;
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
}
