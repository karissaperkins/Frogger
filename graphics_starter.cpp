#include "Graphics.h"
#include "Button.h"
#include "Rectangle_shape.h"
#include "Circle.h"
#include "Shapes.h"
#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include "time.h"
#include "SOIL.h"
#include <fstream>
#include <memory>
using namespace std;

// ANIMAL STRUCT
struct Animal {
    string name, size, weight;
    string habitat, lifespan, funFact;
};
// FUNCTIONS
void getAnimals();
// VARIABLES
vector<Animal> animals;



// GLOBAL VARIABLES
GLdouble width, height;
int wd;
Quad rect({0.7, 0.5, 1.0}, {350, 200}, 100, 40);
Button startButton(rect, "Begin");
Button againButton(rect, "Play Again");
enum screen {start, facts, final};
screen mode;
int animalNum = 1;
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
    mode = facts;
}

void clickToPlayAgain() {
    animalNum = 1;
    mode = start;
}

void displayString(string message, int x, int y) {
    glRasterPos2i(x, y);
    for (char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }
}

void init() {
    width = 800;
    height = 500;
    srand(time(0));
    mode = start;
    getAnimals();
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
}


void displayStart() {
    glColor3f(0.7, 0.0, 0.5);
    string welcome = "Welcome to Animal Facts!";
    displayString(welcome, 250, 150);
    startButton.draw();
}

void displayFacts() {
    // DISPLAY SHAPES using polymorphism with draw function
    vector<Shape*> shapes;
    Rectangle_shape *factBackground = new Rectangle_shape({250,140}, {0.7, 0.0, 0.5}, {420, 240});
    Circle *funFact = new Circle({450,320}, {0.5, 0.5, 0.5}, 175);

    shapes.push_back(factBackground);
    shapes.push_back(funFact);
    for (int i=0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    // DISPLAY VITAL STATS IN RECTANGLE
    glColor3f(0.9, 0.9, 0.9);
    displayString(animals[animalNum].name, 50, 60);
    string sizeString = "Size: " + animals[animalNum].size;
    displayString(sizeString, 75, 100);
    string weightString = "Weight: " + animals[animalNum].weight;
    displayString(weightString, 75, 140);
    string habitatString = "Habitat: " + animals[animalNum].habitat;
    displayString(habitatString, 75, 180);
    string lifeString = "Lifespan: " + animals[animalNum].lifespan;
    displayString(lifeString, 75, 220);

    // DISPLAY FUN FACT IN CIRCLE
    glColor3f(0.2, 0.2, 0.4);
    displayString("Did you know?", 320, 270);

    // break fun fact string into words
    string word = "";
    vector<string> funFactWords;
    istringstream iss(animals[animalNum].funFact);
    while (iss >> word) {
        funFactWords.push_back(word);
    }

    // break fact into lines
    int factChar = 0;
    string funFactLine1 = "", funFactLine2 = "";
    string funFactLine3 = "", funFactLine4 = "";
    for (int i = 0; i < funFactWords.size(); ++i) {
        if (factChar <= 40) {
            funFactLine1 += funFactWords[i] + " ";
            factChar += funFactWords.size() + 1;
        } else if (factChar <= 80) {
            funFactLine2 += funFactWords[i] + " ";
            factChar += funFactWords.size() + 1;
        } else if (factChar <= 140) {
            funFactLine3 += funFactWords[i] + " ";
            factChar += funFactWords.size() + 1;
        } else if (factChar <= 200) {
            funFactLine4 += funFactWords[i] + " ";
            factChar += funFactWords.size() + 1;
        } else {
            funFactLine1 = "Fact too big to display";
            funFactLine2 = "";
            funFactLine3 = "";
            funFactLine4 = "";
        }
    }

    // display each line of the fun fact
    displayString(funFactLine1, 320, 300);
    displayString(funFactLine2, 320, 330);
    displayString(funFactLine3, 320, 360);
    displayString(funFactLine4, 320, 390);

    // DISPLAY BACK/NEXT
    if (animalNum != 1) {
        displayString("< Back", 50, 450);
    }
    if (animalNum != 10) {
        displayString("Next >", 150, 450);
    }
    else {
        displayString("End >", 150, 450);
    }
    glColor3f(0.2, 0.8, 0.9);

    // DISPLAY ANIMAL IMAGE
    glEnable(GL_TEXTURE_2D);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    // create quad for image
    Rectangle_shape *animalImage = new Rectangle_shape({600,125}, {1.0,1.0,1.0}, {200, 150});
    animalImage->draw();
    // bind texture to the quad and then disable it for future draws
    glBindTexture( GL_TEXTURE_2D, textures[animalNum-1] );
    glDisable(GL_TEXTURE_2D);

}

void displayFinal() {
    glColor3f(0.7, 0.0, 0.5);
    string thanks = "Thank you!";
    displayString(thanks, 300, 150);
    string sources = "Facts from nationalgeographic.com and thedodo.com";
    displayString(sources, 50, 450);
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
        case facts:
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
//    //'s'
//    if (key == 's'){
//        if (mode == start) {
//            mode = play;
//        }
//    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            if (mode == facts && animalNum >= 2) {
                animalNum -=1;
            }
            break;
        case GLUT_KEY_RIGHT:
            if (mode == facts && animalNum < 10) {
                animalNum +=1;
            }
            else if (mode == facts && animalNum == 10) {
                mode = final;
            }
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
    wd = glutCreateWindow("Animal Facts!" /* title */ );

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

void getAnimals() {
    ifstream f_in;
    f_in.open("animalStats.csv");

    if (!f_in) {
        cout << "Could not open file " << endl;
    }

    while (f_in && f_in.peek() != EOF) {
        Animal a;
        getline(f_in, a.name, ',');
        getline(f_in, a.size, ',');
        getline(f_in, a.weight, ',');
        getline(f_in, a.habitat, ',');
        getline(f_in, a.lifespan, ',');
        getline(f_in, a.funFact, ',');

        animals.push_back(a);
    }

    f_in.close();
}
