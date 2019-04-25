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
vector<Shape*> shapes;
vector<GLuint> textures;
vector<const char*> filenames = {"frog.jpg"};
Rectangle_shape frog({300, 550}, {1.0, 1.0, 1.0}, {65, 40});

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

void startGame() {
    mode = game;
    shapes.clear();

    Rectangle_shape *medLogA = new Rectangle_shape({0,75}, {0.4, 0.2, 0.0}, {150, 30});
    Rectangle_shape *medLogB = new Rectangle_shape({200,75}, {0.4, 0.2, 0.0}, {150, 30});
    Rectangle_shape *medLogC = new Rectangle_shape({460,75}, {0.4, 0.2, 0.0}, {150, 30});
    Circle *lilypadA1 = new Circle({25,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadA2 = new Circle({55,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadA3 = new Circle({85,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadB1 = new Circle({185,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadB2 = new Circle({215,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadB3 = new Circle({245,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadC1 = new Circle({345,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadC2 = new Circle({375,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadC3 = new Circle({405,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadD1 = new Circle({505,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadD2 = new Circle({535,115}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadD3 = new Circle({565,115}, {0.0, 0.8, 0.0}, 15);
    Rectangle_shape *longLogA = new Rectangle_shape({20,155}, {0.4, 0.2, 0.0}, {200, 30});
    Rectangle_shape *longLogB = new Rectangle_shape({240,155}, {0.4, 0.2, 0.0}, {200, 30});
    Rectangle_shape *longLogC = new Rectangle_shape({500,155}, {0.4, 0.2, 0.0}, {200, 30});
    Rectangle_shape *shortLogA = new Rectangle_shape({0,195}, {0.4, 0.2, 0.0}, {100, 30});
    Rectangle_shape *shortLogB = new Rectangle_shape({140,195}, {0.4, 0.2, 0.0}, {100, 30});
    Rectangle_shape *shortLogC = new Rectangle_shape({320,195}, {0.4, 0.2, 0.0}, {100, 30});
    Rectangle_shape *shortLogD = new Rectangle_shape({510,195}, {0.4, 0.2, 0.0}, {100, 30});
    Circle *lilypadE1 = new Circle({15,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadE2 = new Circle({45,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadE3 = new Circle({75,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadF1 = new Circle({175,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadF2 = new Circle({205,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadF3 = new Circle({235,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadG1 = new Circle({335,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadG2 = new Circle({365,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadG3 = new Circle({395,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadH1 = new Circle({495,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadH2 = new Circle({525,235}, {0.0, 0.8, 0.0}, 15);
    Circle *lilypadH3 = new Circle({555,235}, {0.0, 0.8, 0.0}, 15);

    shapes.push_back(medLogA);
    shapes.push_back(medLogB);
    shapes.push_back(medLogC);
    shapes.push_back(lilypadA1);
    shapes.push_back(lilypadA2);
    shapes.push_back(lilypadA3);
    shapes.push_back(lilypadB1);
    shapes.push_back(lilypadB2);
    shapes.push_back(lilypadB3);
    shapes.push_back(lilypadC1);
    shapes.push_back(lilypadC2);
    shapes.push_back(lilypadC3);
    shapes.push_back(lilypadD1);
    shapes.push_back(lilypadD2);
    shapes.push_back(lilypadD3);
    shapes.push_back(longLogA);
    shapes.push_back(longLogB);
    shapes.push_back(longLogC);
    shapes.push_back(shortLogA);
    shapes.push_back(shortLogB);
    shapes.push_back(shortLogC);
    shapes.push_back(shortLogD);
    shapes.push_back(lilypadE1);
    shapes.push_back(lilypadE2);
    shapes.push_back(lilypadE3);
    shapes.push_back(lilypadF1);
    shapes.push_back(lilypadF2);
    shapes.push_back(lilypadF3);
    shapes.push_back(lilypadG1);
    shapes.push_back(lilypadG2);
    shapes.push_back(lilypadG3);
    shapes.push_back(lilypadH1);
    shapes.push_back(lilypadH2);
    shapes.push_back(lilypadH3);
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

void displayGame() {
    // DISPLAY SHAPES using polymorphism with draw function

    vector<Shape*> bars;
    Rectangle_shape *startRec = new Rectangle_shape({255,545}, {0.7, 0.0, 0.5}, {520, 50});
    Rectangle_shape *middleRec = new Rectangle_shape({255,285}, {0.7, 0.0, 0.5}, {520, 50});
    Rectangle_shape *endRec = new Rectangle_shape({255,25}, {0.7, 0.0, 0.5}, {520, 50});

    bars.push_back(startRec);
    bars.push_back(middleRec);
    bars.push_back(endRec);

    for (Shape*  b: bars) {
        b->draw();
    }
    for (Shape*  s: shapes) {
        s->draw();
    }


    // DISPLAY ANIMAL IMAGE
    glEnable(GL_TEXTURE_2D);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    // create quad for image
    //Rectangle_shape *animalImage = new Rectangle_shape({600,125}, {1.0,1.0,1.0}, {200, 150});
    frog.draw();
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
            displayGame();
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
            if (mode == game){
                frog.move(0,10);
                if (frog.get_center_y() > (height - (frog.get_width()/2.0))) {
                        frog.move(0, -10);
                }
            }
            break;
        case GLUT_KEY_LEFT:
            if (mode == game){
                frog.move(-10,0);
                cout << frog.get_length()/2.0 << endl;
                cout << frog.get_center_x() << endl;
                if (frog.get_center_x() < (frog.get_length()/2.0)) {
                    frog.move(10,0);
                }
            }
            break;
        case GLUT_KEY_RIGHT:
            if (mode == game){
                frog.move(10,0);
                if (frog.get_center_x() > (width - (frog.get_length()/2.0))) {
                    frog.move(-10,0);
                }
            }
            break;
        case GLUT_KEY_UP:
            if (mode == game){
                frog.move(0,-10);
                if (frog.get_center_y() < (frog.get_width()/2.0)) {
                    frog.move(0, 10);
                }
            }
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

//    glutPostRedisplay();
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
        startButton.click(startGame);
    }

    if (state == GLUT_UP &&
        button == GLUT_LEFT_BUTTON &&
        againButton.isOverlapping(x, y) && mode == final) {
        startButton.click(startGame);
    }

    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
    for (Shape*  s: shapes) {
        if (s->get_center_y() == 75) {
            s->move(-2, 0);
        } else if (s->get_center_y() == 115) {
            s->move(4, 0);
        } else if (s->get_center_y() == 155) {
            s->move(-5, 0);
        } else if (s->get_center_y() == 195) {
            s->move(-3, 0);
        } else if (s->get_center_y() == 235) {
            s->move(2, 0);
        }

        if (s->isOffScreen()) {
            s->flipSide();
        }
    }
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
    glutTimerFunc(30, timer, 30);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
