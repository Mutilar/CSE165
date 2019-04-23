#include <iostream>
#include "App.h"

App *singleton;

void timer(int id)
{
    // This will get called every 16 milliseconds after
    // you call it once

    // If you want to manipulate the app in here
    // do it through the singleton pointer

        // std::cout<< singleton->explos_counter << "\n";
    if (singleton->up)
    {
        float ypos = singleton->projectile->getY();
        ypos += 0.05;
        singleton->projectile->setY(ypos);
        singleton->redraw();

        if (singleton->mushroom != NULL)
        {
            if (singleton->mushroom->contains(singleton->projectile->getX(), singleton->projectile->getY()))
            {
                singleton->mushroom->setX(10000);
                singleton->projectile->setX(10000);
                singleton->explosion = new AnimatedRect("fireball.bmp", 6, 6, 50, false, true,  -0.25, 0.9, .5, .5); // float x=0, float y=0, float w=0.5, float h=0.5);
                singleton->explos_counter++;
            }
        }
        if (singleton->explos_counter > 0) singleton->explos_counter++;
        if (singleton->explos_counter > 180) {
            // delete singleton->explosion;
        }
    }

    glutTimerFunc(16, timer, id);
}

App::App(int argc, char **argv, int width, int height, const char *title) : GlutApp(argc, argv, width, height, title)
{

    mushroom = new TexRect("mushroom.png", -0.25, 0.9, 0.5, 0.5);
    projectile = new Rect(-0.05, -0.8, 0.1, 0.1);
    up = false;
    explos_counter = 0;
    singleton = this;

    timer(1);
}

void App::draw()
{
    if (singleton->mushroom != NULL)
    {
        mushroom->draw(0.1);
    }
    projectile->draw();
    if (singleton->explosion != NULL)
    {
        singleton->explosion->draw(1);
    }
}

void App::keyDown(unsigned char key, float x, float y)
{
    if (key == 27)
    {
        exit(0);
    }
    if (key == ' ')
    {
        up = true;
    }
}

App::~App()
{
    delete mushroom;
    std::cout << "Exiting..." << std::endl;
}
