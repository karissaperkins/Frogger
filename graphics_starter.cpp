#include "Graphics.h"
#include "Button.h"
#include "Rectangle_shape.h"
#include "Circle.h"
#include "shapes.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>

#include <vector>
#include "time.h"
#include "SOIL.h"
#include <fstream>
#include <memory>
using namespace std;
using namespace std::chrono;


// GLOBAL VARIABLES
GLdouble width, height;
int wd;
Quad rect({0.7, 0.5, 1.0}, {260, 200}, 100, 40);
Button startButton(rect, "Start Game");
Button againButton(rect, "Play Again");
enum screen {start, game, final, finalWin};
screen mode;
vector<Shape*> shapes;
vector<Shape*> cars;
vector<GLuint> textures;
vector<const char*> filenames = {"frog.jpg", "lightBlueCar.jpg"};
Rectangle_shape frog({250, 555}, {1.0, 1.0, 1.0}, {40, 30});

high_resolution_clock::time_point t1;
high_resolution_clock::time_point t2;
high_resolution_clock::time_point t3;

int xStart = 50;
int xEnd = 490;
int yOne = 75;
int yTwo = 115;
int yThree = 155;
int yFour = 195;
int yFive = 235;
int yCarsOne = 315;
int yCarsTwo = 355;
int yCarsThree = 395;
int yCarsFour = 435;
int yCarsFive = 475;
int yCarsSix = 515;
int yEnd = 35;

int numWins = 0;
int lives = 3;

struct leaderboard{
    double score1;
    double score2;
    double score3;
    double score4;
    double score5;
};


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
    t1 = high_resolution_clock::now();
    shapes.clear();
    cars.clear();
    frog.set_center(xy_point{250,555});

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

    Rectangle_shape *truckA1 = new Rectangle_shape({0,315}, {1.0, 0.0, 0.0}, {75, 30});
    Rectangle_shape *truckA2 = new Rectangle_shape({200,315}, {1.0, 0.0, 0.0}, {75, 30});
    Rectangle_shape *truckA3 = new Rectangle_shape({460,315}, {1.0, 0.0, 0.0}, {75, 30});
    Rectangle_shape *carA1 = new Rectangle_shape({25,355}, {0.5, 0.0, 1.0}, {40, 30});
    Rectangle_shape *carA2 = new Rectangle_shape({185,355}, {0.5, 0.0, 1.0}, {40, 30});
    Rectangle_shape *carA3 = new Rectangle_shape({345,355}, {0.5, 0.0, 1.0}, {40, 30});
    Rectangle_shape *carA4 = new Rectangle_shape({505,355}, {0.5, 0.0, 1.0}, {40, 30});
    Rectangle_shape *truckB1 = new Rectangle_shape({20,395}, {0.0, 1.0, 1.0}, {75, 30});
    Rectangle_shape *truckB2 = new Rectangle_shape({240,395}, {0.0, 1.0, 1.0}, {75, 30});
    Rectangle_shape *truckB3 = new Rectangle_shape({500,395}, {0.0, 1.0, 1.0}, {75, 30});
    Rectangle_shape *carB1 = new Rectangle_shape({0,435}, {0.0, 0.0, 1.0}, {40, 30});
    Rectangle_shape *carB2 = new Rectangle_shape({140,435}, {0.0, 0.0, 1.0}, {40, 30});
    Rectangle_shape *carB3 = new Rectangle_shape({320,435}, {0.0, 0.0, 1.0}, {40, 30});
    Rectangle_shape *carB4 = new Rectangle_shape({510,435}, {0.0, 0.0, 1.0}, {40, 30});
    Rectangle_shape *carC1 = new Rectangle_shape({0,475}, {0.5, 0.5, 0.5}, {40, 30});
    Rectangle_shape *carC2 = new Rectangle_shape({140,475}, {0.5, 0.5, 0.5}, {40, 30});
    Rectangle_shape *carC3 = new Rectangle_shape({320,475}, {0.5, 0.5, 0.5}, {40, 30});
    Rectangle_shape *carC4 = new Rectangle_shape({510,475}, {0.5, 0.5, 0.5}, {40, 30});
    Rectangle_shape *truckC1 = new Rectangle_shape({20,515}, {1.0, 0.5, 0.0}, {75, 30});
    Rectangle_shape *truckC2 = new Rectangle_shape({240,515}, {1.0, 0.5, 0.0}, {75, 30});
    Rectangle_shape *truckC3 = new Rectangle_shape({500,515}, {1.0, 0.5, 0.0}, {75, 30});

    cars.push_back(truckA1);
    cars.push_back(truckA2);
    cars.push_back(truckA3);
    cars.push_back(carA1);
    cars.push_back(carA2);
    cars.push_back(carA3);
    cars.push_back(carA4);
    cars.push_back(truckB1);
    cars.push_back(truckB2);
    cars.push_back(truckB3);
    cars.push_back(carB1);
    cars.push_back(carB2);
    cars.push_back(carB3);
    cars.push_back(carB4);
    cars.push_back(carC1);
    cars.push_back(carC2);
    cars.push_back(carC3);
    cars.push_back(carC4);
    cars.push_back(truckC1);
    cars.push_back(truckC2);
    cars.push_back(truckC3);

}


void clickToPlayAgain() {
    mode = game;
}

void drawLine(double lineWidth, xy_point start, xy_point end) {
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(35, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(lineWidth);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(start.x, start.y);
    glVertex2f(end.x, end.y);
    glEnd();
    glPopAttrib();

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

bool isOverlappingBounds(int x, int y, string shapeList) {
    if (shapeList == "cars") {
        for (Shape *c: cars) {
            vector<xy_point> bounds = c->get_bounds();  // bounds[0] is the bottom left point of the shape and
            // bounds[1] is the top right
            if (bounds[1].x >= x && bounds[0].x <= x && bounds[0].y >= y && bounds[1].y <= y) {
                return true;
            }
        }
    } else if (shapeList == "shapes"){  // can be used for logs/lily pads to see if the frog is on one of the logs or lily pads
        for (Shape*  s: shapes) {
            vector<xy_point> bounds = s->get_bounds();  // bounds[0] is the bottom left point of the shape and
                                                        // bounds[1] is the top right
            if (bounds[1].x >= x && bounds[0].x <= x && bounds[0].y >= y && bounds[1].y <= y) {
                return true;
            }
        }
    }
    return false;
}


void displayGame() {
    // DISPLAY SHAPES using polymorphism with draw function

    vector<Shape*> bars;
    Rectangle_shape *startRec = new Rectangle_shape({255,550}, {0.7, 0.0, 0.5}, {520, 40});
    Rectangle_shape *middleRec = new Rectangle_shape({255,280}, {0.7, 0.0, 0.5}, {520, 40});
    Rectangle_shape *water = new Rectangle_shape({255, 155}, {0.0, 0.2, 0.7}, {520, 210});
    Rectangle_shape *endRec = new Rectangle_shape({255,25}, {0.7, 0.0, 0.5}, {520, 50});

    bars.push_back(startRec);
    bars.push_back(middleRec);
    bars.push_back(water);
    bars.push_back(endRec);

    for (Shape*  b: bars) {
        b->draw();
    }

    drawLine(1.0, {0,335}, {520, 335});
    drawLine(1.0, {0,375}, {520, 375});
    drawLine(1.0, {0,415}, {520, 415});
    drawLine(1.0, {0,455}, {520, 455});
    drawLine(1.0, {0,495}, {520, 495});

    t2 = high_resolution_clock::now();
    duration<double> timeSpan = duration_cast<duration<double>>(t2-t1);

    glColor3f(0.0, 0.0, 0.0);
    string gameTime = "Time: "+to_string(timeSpan.count());
    displayString(gameTime, 15, 560);

    //draw ending
    glLineWidth(1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(180, 35);
    glVertex2f(180, 10);
    glEnd();

    for (Shape*  s: shapes) {
        s->draw();
    }
    for (Shape* c: cars) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture( GL_TEXTURE_2D, textures[1] );
        c->draw();
        glDisable(GL_TEXTURE_2D);
    }

    //seeing how many lives and wins
    if(lives == 0){
        mode = final;
    }
    if(numWins == 2){
        mode = finalWin;
    }

    // Cars collision
    if(frog.get_center_y() == yCarsOne || frog.get_center_y() == yCarsTwo || frog.get_center_y() == yCarsThree || frog.get_center_y() == yCarsFour || frog.get_center_y() == yCarsFive || frog.get_center_y() == yCarsSix) {
        if (isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "cars")) {
            frog.set_center({250,555});
            lives--;
        }
    }

    // Log/Lily pad riding
    if(frog.get_center_y() == yOne){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")) {
            frog.move(-2, 0);
        }else{
            frog.set_center({250,555});
            lives--;
        }
    }else if(frog.get_center_y() == yTwo){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")){
            frog.move(4, 0);
        }else{
            frog.set_center({250,555});
            lives--;
        }
    }else if(frog.get_center_y() == yThree){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")){
            frog.move(-5, 0);
        }else{
            frog.set_center({250,555});
            lives--;
        }
    }else if(frog.get_center_y() == yFour){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")){
            frog.move(-3, 0);
        }else{
            frog.set_center({250,555});
            lives--;
        }
    }else if(frog.get_center_y() == yFive){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")){
            frog.move(2, 0);
        }else{
            frog.set_center({250,555});
            lives--;
        }
    }else if(frog.get_center_y() == yEnd){
        //mode = finalWin;
        t2 = high_resolution_clock::now();

        if(frog.get_center_x() >= 32 && frog.get_center_x() <= 114){
            cout << "one";
            frog.set_center({250,555});
            numWins++;
        }else if(frog.get_center_x() > 114 && frog.get_center_x() <= 196){
            cout << "two";
            frog.set_center({250,555});
            numWins++;
        }else if(frog.get_center_x() > 196 && frog.get_center_x() <= 278){
            cout << "three";
            frog.set_center({250,555});
            numWins++;
        }else if(frog.get_center_x() > 278 && frog.get_center_x() <= 360){
            cout << "four";
            frog.set_center({250,555});
            numWins++;
        }else if(frog.get_center_x() > 360 && frog.get_center_x() <=442){
            cout << "five";
            frog.set_center({250,555});
        }
    }


    // DISPLAY FROG
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, textures[0] );
    frog.draw();
    glDisable(GL_TEXTURE_2D);

}

void displayFinal() {
    glColor3f(0.7, 0.0, 0.5);
    string gameEnd = "Game Over";
    displayString(gameEnd, 205, 150);
    againButton.draw();
    lives = 3;
}

void displayFinalWin() {
    glColor3f(0.7, 0.0, 0.5);
    string gameWin = "Congratulations! You Won!";
    displayString(gameWin, 135, 150);
    againButton.draw();
    glColor3f(0.7, 0.0, 0.5);

    duration<double> timeSpan = duration_cast<duration<double>>(t2-t1);
    string gameTime = "Your Time: "+to_string(timeSpan.count())+" seconds";
    displayString(gameTime, 135, 280);
    string topTimes = "Top Times: ";
    displayString(topTimes, 135, 330);
    string topTime = "1. ";
    string secondTime = "2. ";
    string thirdTime = "3. ";
    string fourthTime = "4. ";
    string fifthTime = "5. ";
    displayString(topTime, 135, 370);
    displayString(secondTime, 135, 410);
    displayString(thirdTime, 135, 450);
    displayString(fourthTime, 135, 490);
    displayString(fifthTime, 135, 530);
    numWins = 0;
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
        case finalWin:
            displayFinalWin();
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
    //'q' Game Over
    if (key == 'q'){
        mode = final;
    }

    //'w' Game Win
    if (key == 'w'){
        mode = finalWin;
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            if (mode == game){
                frog.move(0,40);
                cout << frog.get_center_x() << " , " << frog.get_center_y() << endl;
                if (frog.get_center_y() > (height - (frog.get_width()/2.0))) {
                        frog.move(0, -40);
                }

            }

            break;
        case GLUT_KEY_LEFT:
            if (mode == game){
                frog.move(-40,0);
                cout << frog.get_center_x() << " , " << frog.get_center_y() << endl;
                if (frog.get_center_x() < (frog.get_length()/2.0)) {
                    frog.move(40,0);
                }
            }
            break;
        case GLUT_KEY_RIGHT:
            if (mode == game){
                frog.move(40,0);
                cout << frog.get_center_x() << " , " << frog.get_center_y() << endl;
                if (frog.get_center_x() > (width - (frog.get_length()/2.0))) {
                    frog.move(-40,0);
                }
            }
            break;
        case GLUT_KEY_UP:
            if (mode == game){
                frog.move(0,-40);
                cout << frog.get_center_x() << " , " << frog.get_center_y() << endl;
                if (frog.get_center_y() < (frog.get_width()/2.0)) {
                    frog.move(0, 40);
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

    if (state == GLUT_UP &&
        button == GLUT_LEFT_BUTTON &&
        againButton.isOverlapping(x, y) && mode == finalWin) {
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
    for (Shape*  c: cars) {
        if (c->get_center_y() == 315) {
            c->move(3, 0);
        } else if (c->get_center_y() == 355) {
            c->move(-3, 0);
        } else if (c->get_center_y() == 395) {
            c->move(-5, 0);
        } else if (c->get_center_y() == 435) {
            c->move(-2, 0);
        } else if (c->get_center_y() == 475) {
            c->move(2, 0);
        } else if (c->get_center_y() == 515) {
            c->move(-4, 0);
        }

        if (c->isOffScreen()) {
            c->flipSide();
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
