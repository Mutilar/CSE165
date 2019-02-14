#include <iostream>
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

int board[3][3];

bool singlePlayer = true;
int turnNumber = 1;
bool gameOver = false;
//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene()
{
    if (!gameOver)
    {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set background color to black
        glClearColor(0.0, 0.0, 0.0, 1.0);

        // Set up the transformations stack
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        // Drawing parameters for circles
        float theta = 0;
        float thetaInc = M_PI / 100;
        float radius = 0.15;

        // Drawing #
        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(1000);
        for (double spacing = -.33; spacing < .5; spacing += .66)
        {
            glBegin(GL_LINES);
            glVertex3f(spacing, -1, 1);
            glVertex3f(spacing, 1, 1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-1, spacing, 1);
            glVertex3f(1, spacing, 1);
            glEnd();
        }
        // Drawing any Xs or Os on the board
        double centerX, centerY;
        for (int x = 0; x < 3; x++)
        {
            centerX = x - 1; //-1, 0, 1
            centerX *= .66;  //-.66, 0, .66
            for (int y = 0; y < 3; y++)
            {
                centerY = y - 1; //-1, 0, 1
                centerY *= .66;  //-.66, 0, .66
                if (board[x][y] == 1)
                { //Draw O
                    glBegin(GL_POLYGON);
                    for (theta = 0; theta < 2.0 * M_PI; theta += thetaInc)
                    {
                        glVertex2f((radius)*cos(theta) + centerX, (radius)*sin(theta) + centerY);
                    }
                    glEnd();
                }
                if (board[x][y] == 2)
                { //Draw X
                    glBegin(GL_LINES);
                    glVertex3f(centerX - radius, centerY - radius, 1);
                    glVertex3f(centerX + radius, centerY + radius, 1);
                    glEnd();
                    glBegin(GL_LINES);
                    glVertex3f(centerX + radius, centerY - radius, 1);
                    glVertex3f(centerX - radius, centerY + radius, 1);
                    glEnd();
                }
            }
        }
        // Check for a Win
        glColor3f(1.0, 0.0, 0.0);
        double center;
        int winner = 0;
        for (int i = 0; i < 3; i++)
        {
            center = i - 1; //-1, 0, 1
            center *= .66;  //-.66, 0, .66
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                winner = board[i][0];
                glBegin(GL_LINES);
                glVertex3f(center, -1, 1);
                glVertex3f(center, 1, 1);
                glEnd();
            }
            if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                winner = board[0][i];
                glBegin(GL_LINES);
                glVertex3f(1, center, 1);
                glVertex3f(-1, center, 1);
                glEnd();
            }
        }
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            winner = board[0][0];
            glBegin(GL_LINES);
            glVertex3f(-1, -1, 1);
            glVertex3f(1, 1, 1);
            glEnd();
        }
        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            winner = board[0][2];
            glBegin(GL_LINES);
            glVertex3f(-1, 1, 1);
            glVertex3f(1, -1, 1);
            glEnd();
        }
        if (winner != 0)
        {
            gameOver = true;
            cout << "WINNER:\n";
            if (winner == 1)
            {
                cout << "O has won!\n";
            }
            if (winner == 2)
            {
                cout << "X has won!\n";
            }
        }

        // Really dumb AI
        bool placed = false;
        if (singlePlayer && (turnNumber % 2 == 0))
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (board[x][y] == 0 && placed == false)
                    {
                        board[x][y] = (turnNumber++) % 2 + 1;
                        placed = true;
                        break;
                    }
                }
            }
        }

        // Check for a Cats Game
        bool isBoardFull = true;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (board[x][y] == 0)
                {
                    isBoardFull = false;
                    break;
                }
            }
        }
        if (isBoardFull)
            gameOver = true;

        // We have been drawing everything to the back buffer
        // Swap the buffers to see the result of what we drew
        glFlush();
        glutSwapBuffers();
    }
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

//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        // Convert from Window to Scene coordinates
        float mx = (float)x;
        float my = (float)y;

        windowToScene(mx, my); //mx,my are from -1 to 1

        mx *= 1.5;               //mx is from -1.5 to 1.5
        mx += 1.5;               //mx is from 0 to 3
        int x_index = floor(mx); //0-1 == 0, 1-2 == 1, 2-3 == 2 (index x of 3x3 matrix)

        my *= 1.5;               //my is from -1.5 to 1.5
        my += 1.5;               //my is from 0 to 3
        int y_index = floor(my); //0-1 == 0, 1-2 == 1, 2-3 == 2 (index y of 3x3 matrix)

        if (board[x_index][y_index] == 0)
        {
            board[x_index][y_index] = (turnNumber++ % 2) + 1; //Odd turns == Xs, even turns == Os

            appDrawScene();
        }
        // Redraw the scene by calling appDrawScene above
        // so that the point we added above will get painted
        glutPostRedisplay();
    }
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
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 's':
        cout << "SINGLEPLAYER = true\n";
        singlePlayer = true;
        break;
    case 'p':
        cout << "SINGLEPLAYER = false\n";
        singlePlayer = false;
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
    cout << "WELCOME TO TIC TAC TOE\n~~~~~~~~~~~~~~~~~~~~~~\nPress 's' for SINGLEPLAYER.\nPress 'p' for MULTIPLAYER\n";
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    // Setup window position, size, and title
    glutInitWindowPosition(20, 60);
    glutInitWindowSize(width, height);
    glutCreateWindow("CSE165 Tic Tac Toe");

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
