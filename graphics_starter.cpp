#include "Graphics.h"
#include "Button.h"
#include "Rectangle_shape.h"
#include "Circle.h"
#include "shapes.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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
Quad rect2({0.7, 0.5, 1.0}, {260, 260}, 100, 40);
Quad rect3({0.7, 0.5, 1.0}, {400, 300}, 100, 40);
Quad rect4({0.7, 0.5, 1.0}, {260, 100}, 100, 40);
Button startButton(rect, "Start Game");
Button leaderBoardButton(rect2, "Leader Board");
Button againButton(rect4, "Play Again");
Button mainButton(rect3, "Main Menu");
enum screen {start, leader, game, final, finalWin, finalWinCheat};
screen mode;
vector<Shape*> shapes;
vector<Shape*> cars;
vector<GLuint> textures;
vector<const char*> filenames = {"frog.jpg", "lightBlueCar.jpg"};
Rectangle_shape frog({250, 555}, {1.0, 1.0, 1.0}, {40, 30});
Rectangle_shape frog1({51, 25}, {1.0, 1.0, 1.0}, {40, 30});
Rectangle_shape frog2({152, 25}, {1.0, 1.0, 1.0}, {40, 30});
Rectangle_shape frog3({253, 25}, {1.0, 1.0, 1.0}, {40, 30});
Rectangle_shape frog4({354, 25}, {1.0, 1.0, 1.0}, {40, 30});
Rectangle_shape frog5({455, 25}, {1.0, 1.0, 1.0}, {40, 30});
high_resolution_clock::time_point t1;
high_resolution_clock::time_point t2;
high_resolution_clock::time_point t3;
double newTime1;
double newTime2;
double newTime3;
double newTime4;
double newTime5;
string gameTime1;
string gameTime2;
string gameTime3;
string gameTime4;
string gameTime5;

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

bool frog1Win;
bool frog2Win;
bool frog3Win;
bool frog4Win;
bool frog5Win;


struct leaderboard{
    double score1;
    double score2;
    double score3;
    double score4;
    double score5;
};

leaderboard score;


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
    frog1Win = false;
    frog2Win = false;
    frog3Win = false;
    frog4Win = false;
    frog5Win = false;
    lives = 3;
    numWins = 0;

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
    leaderBoardButton.draw();

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

void drawEndLine(int x){
    glLineWidth(1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(x, 50);
    glVertex2f(x, 0);
    glEnd();
}

void drawFrog(int frogNum){
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, textures[0] );
    if(frogNum == 1) {
        frog1.draw();
    }else if(frogNum == 2){
        frog2.draw();
    }else if(frogNum == 3) {
        frog3.draw();
    }else if(frogNum == 4){
        frog4.draw();
    }else if(frogNum == 5){
        frog5.draw();
    }
    glDisable(GL_TEXTURE_2D);
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

    string livesLeft = "Lives: " + to_string(lives);
    displayString(livesLeft, 400, 560);

    //draw ending
    drawEndLine(102);
    drawEndLine(204);
    drawEndLine(306);
    drawEndLine(408);

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
    if(numWins == 5){
        mode = finalWin;
    }

    // Cars collision
    if(frog.get_center_y() == yCarsOne || frog.get_center_y() == yCarsTwo || frog.get_center_y() == yCarsThree || frog.get_center_y() == yCarsFour || frog.get_center_y() == yCarsFive || frog.get_center_y() == yCarsSix) {
        if (isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "cars")) {
            frog.set_center({250,555});
            lives--;
            t2 = high_resolution_clock::now();
            t1 = high_resolution_clock::now();
        }
    }

    // Log/Lily pad riding
    if(frog.get_center_y() == yOne){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")) {
            frog.move(-2, 0);
        }else{
            frog.set_center({250,555});
            lives--;
            t2 = high_resolution_clock::now();
            t1 = high_resolution_clock::now();
        }
    }else if(frog.get_center_y() == yTwo){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")){
            frog.move(4, 0);
        }else{
            frog.set_center({250,555});
            lives--;
            t2 = high_resolution_clock::now();
            t1 = high_resolution_clock::now();
        }
    }else if(frog.get_center_y() == yThree){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")){
            frog.move(-5, 0);
        }else{
            frog.set_center({250,555});
            lives--;
            t2 = high_resolution_clock::now();
            t1 = high_resolution_clock::now();
        }
    }else if(frog.get_center_y() == yFour){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")){
            frog.move(-3, 0);
        }else{
            frog.set_center({250,555});
            lives--;
            t2 = high_resolution_clock::now();
            t1 = high_resolution_clock::now();
        }
    }else if(frog.get_center_y() == yFive){
        if(frog.get_center_x() >= xStart && frog.get_center_x() <= xEnd && isOverlappingBounds(frog.get_center_x(), frog.get_center_y(), "shapes")){
            frog.move(2, 0);
        }else{
            frog.set_center({250,555});
            lives--;
            t2 = high_resolution_clock::now();
            t1 = high_resolution_clock::now();
        }
    }else if(frog.get_center_y() == yEnd){

        if(frog.get_center_x() >= 0 && frog.get_center_x() <= 102){
            t2 = high_resolution_clock::now();
            if(!frog1Win){
                cout << "one";
                frog1Win = true;
                frog.set_center({250, 555});
                numWins++;
                duration<double> timeSpan = duration_cast<duration<double>>(t2-t1);
                string time = to_string(timeSpan.count());
                newTime1 = timeSpan.count();
                gameTime1 = "Your Time to Square 1: "+time+" seconds";
            }else if(frog1Win){
                frog.set_center({250,555});
                lives--;
            }
            t1 = high_resolution_clock::now();

        }else if(frog.get_center_x() > 102 && frog.get_center_x() <= 204){
            t2 = high_resolution_clock::now();
            if(!frog2Win) {
                cout << "two";
                frog2Win = true;
                frog.set_center({250, 555});
                numWins++;
                duration<double> timeSpan = duration_cast<duration<double>>(t2-t1);
                string time = to_string(timeSpan.count());
                newTime2 = timeSpan.count();
                gameTime2 = "Your Time to Square 2: "+time+" seconds";
            }else if(frog2Win){
                frog.set_center({250,555});
                lives--;
            }
            t1 = high_resolution_clock::now();

        }else if(frog.get_center_x() > 204 && frog.get_center_x() <= 306){
            t2 = high_resolution_clock::now();
            if(!frog3Win) {
                cout << "three";
                frog3Win = true;
                frog.set_center({250, 555});
                numWins++;
                duration<double> timeSpan = duration_cast<duration<double>>(t2-t1);
                string time = to_string(timeSpan.count());
                newTime3 = timeSpan.count();
                gameTime3 = "Your Time to Square 3: "+time+" seconds";
            }else if(frog3Win){
                frog.set_center({250,555});
                lives--;
            }
            t1 = high_resolution_clock::now();

        }else if(frog.get_center_x() > 306 && frog.get_center_x() <= 408){
            t2 = high_resolution_clock::now();
            if(!frog4Win) {
                cout << "four";
                frog4Win = true;
                frog.set_center({250, 555});
                numWins++;
                duration<double> timeSpan = duration_cast<duration<double>>(t2-t1);
                string time = to_string(timeSpan.count());
                newTime4 = timeSpan.count();
                gameTime4 = "Your Time to Square 4: "+time+" seconds";
            }else if(frog4Win){
                frog.set_center({250,555});
                lives--;
            }
            t1 = high_resolution_clock::now();

        }else if(frog.get_center_x() > 408 && frog.get_center_x() <= 510){
            t2 = high_resolution_clock::now();
            if(!frog5Win) {
                cout << "five";
                frog5Win = true;
                frog.set_center({250, 555});
                numWins++;
                duration<double> timeSpan = duration_cast<duration<double>>(t2-t1);
                string time = to_string(timeSpan.count());
                newTime5 = timeSpan.count();
                gameTime5 = "Your Time to Square 5: "+time+" seconds";
            }else if(frog5Win){
                frog.set_center({250,555});
                lives--;
            }
            t1 = high_resolution_clock::now();
        }
    }

    if(frog1Win){
        drawFrog(1);
    }
    if(frog2Win){
        drawFrog(2);
    }
    if(frog3Win){
        drawFrog(3);
    }
    if(frog4Win){
        drawFrog(4);
    }
    if(frog5Win){
        drawFrog(5);
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
    displayString(gameEnd, 205, 190);
    againButton.draw();
    leaderBoardButton.draw();

}

void displayLeaderBoard() {
    glColor3f(0.7, 0.0, 0.5);
    mainButton.draw();
    glColor3f(0.7, 0.0, 0.5);

    for (int i = 0; i < 5; i++) {
        ifstream f_in;
        f_in.open("topScores.txt");
        double line;
        while (f_in >> line) {
            if (line != score.score1 && line != score.score2 && line != score.score3 &&
                line != score.score4 && line != score.score5) {
                if (line < score.score1 || score.score1 == 0) {
                    score.score1 = line;
                } else if ((score.score1 < line && line < score.score2) || score.score2 == 0) {
                    score.score2 = line;
                } else if ((score.score2 < line && line < score.score3) || score.score3 == 0) {
                    score.score3 = line;
                } else if ((score.score3 < line && line < score.score4) || score.score4 == 0) {
                    score.score4 = line;
                } else if ((score.score4 < line && line < score.score5) || score.score5 == 0) {
                    score.score5 = line;
                }
            }
        }
        f_in.close();
    }


    string topTimes = "Top Times: ";
    displayString(topTimes, 175, 125);
    string topTime = "1. "+to_string(score.score1);
    string secondTime = "2. "+to_string(score.score2);
    string thirdTime = "3. "+to_string(score.score3);
    string fourthTime = "4. "+to_string(score.score4);
    string fifthTime = "5. "+to_string(score.score5);
    displayString(topTime, 175, 165);
    displayString(secondTime, 175, 205);
    displayString(thirdTime, 175, 245);
    displayString(fourthTime, 175, 285);
    displayString(fifthTime, 175, 325);
}


void displayFinalWin() {
    glColor3f(0.7, 0.0, 0.5);
    string gameWin = "Congratulations! You Won!";
    displayString(gameWin, 135, 50);
    againButton.draw();
    glColor3f(0.7, 0.0, 0.5);

    displayString(gameTime1, 75, 160);
    displayString(gameTime2, 75, 190);
    displayString(gameTime3, 75, 220);
    displayString(gameTime4, 75, 250);
    displayString(gameTime5, 75, 280);

    ofstream f_out;
    f_out.open("topScores.txt", ios::app);
    if (newTime1 > 0) {
        f_out << newTime1 << endl;
    }
    if (newTime2 > 0) {
        f_out << newTime2 << endl;
    }
    if (newTime3 > 0) {
        f_out << newTime3 << endl;
    }
    if (newTime4 > 0) {
        f_out << newTime4 << endl;
    }
    if (newTime5 > 0) {
        f_out << newTime5 << endl;
    }
    f_out.close();

    for (int i = 0; i < 5; i++) {
        ifstream f_in;
        f_in.open("topScores.txt");
        double line;
        while (f_in >> line) {
            if (line != score.score1 && line != score.score2 && line != score.score3 &&
                    line != score.score4 && line != score.score5) {
                if (line < score.score1 || score.score1 == 0) {
                    score.score1 = line;
                } else if ((score.score1 < line && line < score.score2) || score.score2 == 0) {
                    score.score2 = line;
                } else if ((score.score2 < line && line < score.score3) || score.score3 == 0) {
                    score.score3 = line;
                } else if ((score.score3 < line && line < score.score4) || score.score4 == 0) {
                    score.score4 = line;
                } else if ((score.score4 < line && line < score.score5) || score.score5 == 0) {
                    score.score5 = line;
                }
            }
        }
        f_in.close();
    }


    string topTimes = "Top Times: ";
    displayString(topTimes, 135, 330);
    string topTime = "1. "+to_string(score.score1);
    string secondTime = "2. "+to_string(score.score2);
    string thirdTime = "3. "+to_string(score.score3);
    string fourthTime = "4. "+to_string(score.score4);
    string fifthTime = "5. "+to_string(score.score5);
    displayString(topTime, 135, 370);
    displayString(secondTime, 135, 410);
    displayString(thirdTime, 135, 450);
    displayString(fourthTime, 135, 490);
    displayString(fifthTime, 135, 530);
}

void displayFinalWinCheat() {
    glColor3f(0.7, 0.0, 0.5);
    string gameWin = "Congratulations! You Won!";
    displayString(gameWin, 135, 50);
    againButton.draw();
    glColor3f(0.7, 0.0, 0.5);

    duration<double> timeSpan = duration_cast<duration<double>>(t2-t1);
    string time = to_string(timeSpan.count());
    double newTime = timeSpan.count();
    string gameTime = "Your Time: "+time+" seconds";
    displayString(gameTime, 135, 280);

    for (int i = 0; i < 5; i++) {
        ifstream f_in;
        f_in.open("topScores.txt");
        double line;
        while (f_in >> line) {
            if (line != score.score1 && line != score.score2 && line != score.score3 &&
                line != score.score4 && line != score.score5) {
                if (line < score.score1 || score.score1 == 0) {
                    score.score1 = line;
                } else if ((score.score1 < line && line < score.score2) || score.score2 == 0) {
                    score.score2 = line;
                } else if ((score.score2 < line && line < score.score3) || score.score3 == 0) {
                    score.score3 = line;
                } else if ((score.score3 < line && line < score.score4) || score.score4 == 0) {
                    score.score4 = line;
                } else if ((score.score4 < line && line < score.score5) || score.score5 == 0) {
                    score.score5 = line;
                }
            }
        }
        f_in.close();
    }


    string topTimes = "Top Times: ";
    displayString(topTimes, 135, 330);
    string topTime = "1. "+to_string(score.score1);
    string secondTime = "2. "+to_string(score.score2);
    string thirdTime = "3. "+to_string(score.score3);
    string fourthTime = "4. "+to_string(score.score4);
    string fifthTime = "5. "+to_string(score.score5);
    displayString(topTime, 135, 370);
    displayString(secondTime, 135, 410);
    displayString(thirdTime, 135, 450);
    displayString(fourthTime, 135, 490);
    displayString(fifthTime, 135, 530);
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
        case leader:
            displayLeaderBoard();
            break;
        case game:
            displayGame();
            break;
        case finalWinCheat:
            //displayFinalWinCheat();
            displayFinalWin();
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
        mode = finalWinCheat;
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

    if (leaderBoardButton.isOverlapping(x, y)) {
        leaderBoardButton.hover();
    } else {
        leaderBoardButton.release();
    }

    if (againButton.isOverlapping(x, y)) {
        againButton.hover();
    } else {
        againButton.release();
    }

    if (mainButton.isOverlapping(x, y)) {
        mainButton.hover();
    } else {
        mainButton.release();
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

    if (state == GLUT_UP &&
        button == GLUT_LEFT_BUTTON &&
        againButton.isOverlapping(x, y) && mode == finalWinCheat) {
        startButton.click(startGame);
    }

    if (state == GLUT_DOWN &&
        button == GLUT_LEFT_BUTTON &&
        leaderBoardButton.isOverlapping(x, y)) {
        leaderBoardButton.pressDown();
    } else {
        leaderBoardButton.release();
    }

    if (state == GLUT_UP &&
        button == GLUT_LEFT_BUTTON &&
        leaderBoardButton.isOverlapping(x, y) && (mode == start || mode == final)) {
        mode = leader;
        leaderBoardButton.click(displayLeaderBoard);
    }

    if (state == GLUT_DOWN &&
        button == GLUT_LEFT_BUTTON &&
        mainButton.isOverlapping(x, y)) {
        mainButton.pressDown();
    } else {
        mainButton.release();
    }

    if (state == GLUT_UP &&
        button == GLUT_LEFT_BUTTON &&
        mainButton.isOverlapping(x, y) && (mode == leader)) {
        mode = start;
        mainButton.click(displayStart);
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
