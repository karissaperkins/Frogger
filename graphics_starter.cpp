#include "Graphics.h"
#include "Button.h"
#include "Rectangle_shape.h"
#include "Circle.h"
#include "shapes.h"
#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include "time.h"
#include "SOIL.h"
#include <fstream>
#include <memory>
using namespace std;


// GLOBAL VARIABLES
GLdouble width, height;
int wd;
Quad rect({0.7, 0.5, 1.0}, {260, 200}, 100, 40);
Button startButton(rect, "Start Game");
Button againButton(rect, "Play Again");
enum screen {start, game, final};
screen mode;
vector<GLuint> textures;
vector<const char*> filenames = {"elephant.jpg", "alligator.jpg", "giraffe.jpg", "hedgehog.jpg", "rhino.jpg",
                                 "camel.jpg", "sloth.jpg", "orca.jpg", "ostricth.jpg", "frog.jpg"};

void loadImages() {
    // load each image from the filename vector into a textures vector
    GLuint texture;
    for (int i=0; i<filenames.size(); i++) {
        texture = SOIL_load_OGL_texture(filenames[i], SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
                                        SOIL_FLAG_COMPRESS_TO_DXT);
        textures.push_back(texture);
    }
    cout << "images loaded" << endl;

}

void clickToStart() {
    mode = game;
}

void clickToPlayAgain() {
    mode = game;
}

void displayString(string message, int x, int y) {
    glRasterPos2i(x, y);
    for (char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
    }
}

void init() {
    width = 510;
    height = 570;
    srand(time(0));
    mode = start;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void displayStart() {
    glColor3f(0.7, 0.0, 0.5);
    string welcome = "Frogger";
    displayString(welcome, 220, 150);
    startButton.draw();
}

void displayFacts() {
    // DISPLAY SHAPES using polymorphism with draw function
    vector<Shape*> shapes;
    Rectangle_shape *startRec = new Rectangle_shape({255,545}, {0.7, 0.0, 0.5}, {520, 50});
    Rectangle_shape *logA = new Rectangle_shape({340,75}, {0.4, 0.2, 0.0}, {100, 30});
    Circle *lilypadA = new Circle({25,115}, {0.0, 0.8, 0.0}, 15);
    Rectangle_shape *logB = new Rectangle_shape({240,155}, {0.4, 0.2, 0.0}, {100, 30});
    Rectangle_shape *logC = new Rectangle_shape({340,195}, {0.4, 0.2, 0.0}, {100, 30});
    Circle *lilypadB = new Circle({450,235}, {0.0, 0.8, 0.0}, 15);
    Rectangle_shape *middleRec = new Rectangle_shape({255,285}, {0.7, 0.0, 0.5}, {520, 50});
    Rectangle_shape *endRec = new Rectangle_shape({255,25}, {0.7, 0.0, 0.5}, {520, 50});

    shapes.push_back(startRec);
    shapes.push_back(logA);
    shapes.push_back(lilypadA);
    shapes.push_back(logB);
    shapes.push_back(logC);
    shapes.push_back(lilypadB);
    shapes.push_back(middleRec);
    shapes.push_back(endRec);
    for (int i=0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    // DISPLAY ANIMAL IMAGE
    glEnable(GL_TEXTURE_2D);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    // create quad for image
    //Rectangle_shape *animalImage = new Rectangle_shape({600,125}, {1.0,1.0,1.0}, {200, 150});
    //animalImage->draw();
    // bind texture to the quad and then disable it for future draws
    //glBindTexture( GL_TEXTURE_2D, textures[animalNum-1] );
    glDisable(GL_TEXTURE_2D);

}

void displayFinal() {
    glColor3f(0.7, 0.0, 0.5);
    string gameEnd = "Game Over";
    displayString(gameEnd, 205, 150);
    againButton.draw();
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */
    switch (mode) {
        case start:
            displayStart();
            break;
        case game:
            displayFacts();
            break;
        case final:
            displayFinal();
            break;
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    //'q'
    if (key == 'q'){
        mode = final;
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {
    if (startButton.isOverlapping(x, y)) {
        startButton.hover();
    } else {
        startButton.release();
    }

    if (againButton.isOverlapping(x, y)) {
        againButton.hover();
    } else {
        againButton.release();
    }

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN &&
        button == GLUT_LEFT_BUTTON &&
        startButton.isOverlapping(x, y)) {
        startButton.pressDown();
    } else {
        startButton.release();
    }

    if (state == GLUT_UP &&
        button == GLUT_LEFT_BUTTON &&
        startButton.isOverlapping(x, y) && mode == start) {
        startButton.click(clickToStart);
    }

    if (state == GLUT_DOWN &&
        button == GLUT_LEFT_BUTTON &&
        againButton.isOverlapping(x, y)) {
        againButton.pressDown();
    } else {
        againButton.release();
    }

    if (state == GLUT_UP &&
        button == GLUT_LEFT_BUTTON &&
        againButton.isOverlapping(x, y) && mode == final) {
        startButton.click(clickToPlayAgain);
    }

    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Frogger" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // load in all images into a textures vector
    loadImages();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
