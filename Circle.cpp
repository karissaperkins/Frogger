//
// Created by Kristin on 2/21/2019.
//
#define _USE_MATH_DEFINES
#include "Circle.h"
#include <iostream>
#include <math.h>

using namespace std;

Circle::Circle() : Shape() {
    set_radius(1.0);
}
Circle::Circle(xy_point new_center, color new_fill, double new_radius) :
        Shape(new_center, new_fill) {
    set_radius(new_radius);
}

// Getter
double Circle::get_radius() const{
    return radius;
}

// Setter
void Circle::set_radius (double new_radius){
    if (new_radius == 0.0) {
        radius = 1.0;
        std::cout << "Radius may not be zero. It has been set to default value of 1.0." << std::endl;
    }
    else if (new_radius < 0.0) {
        radius = abs(new_radius);
        std::cout << "Radius may not be negative. It has been set to the absolute value." << std::endl;
    }
    else {
        radius = (new_radius);
    }
}

// Override parent's pure virtual methods
// Based on code from linusthe3rd github for circles.cpp: https://gist.github.com/linusthe3rd/803118
void Circle::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    int triangleNum = 40; //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(get_center_x(), get_center_y()); // center of circle
    for (int i = 0; i <= triangleNum; i++) {
        glVertex2f(
                get_center_x() + (radius * cos(i * (2.0f * M_PI) / triangleNum)),
                get_center_y() + (radius * sin(i * (2.0f * M_PI) / triangleNum))
        );
    }
    glEnd();
}
vector<xy_point> Circle::get_bounds() const{
    vector<xy_point> bounds;
    xy_point bottom_left;
    xy_point top_right;
    bottom_left.x = get_center_x() - get_radius();
    bottom_left.y = get_center_y() + get_radius();
    bounds.push_back(bottom_left);
    top_right.x = get_center_x() + get_radius();
    top_right.y = get_center_y() - get_radius();
    bounds.push_back(top_right);
    return bounds;
}

double Circle::calculate_area() const {
    return M_PI * pow(get_radius(), 2);
}
double Circle::calculate_perimeter() const {
    return 2 * M_PI * get_radius();
}
