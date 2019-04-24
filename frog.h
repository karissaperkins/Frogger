#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


//#include <stdlib.h>
////#include <glut.h>
//#include <iostream>

#ifndef FROGGER_FROG_H
#define FROGGER_FROG_H

float x = 0, y = 0;

class Frog{
public:

private:

    void move(int key, int x, int y);

    void draw();
};

#endif //FROGGER_FROG_H
