//
// Created by Kristin on 2/21/2019.
//

#include "Rectangle_shape.h"
#include <iostream>
#include <math.h>

using namespace std;

Rectangle_shape::Rectangle_shape() : Shape(){
    set_dimensions({1.0, 1.0});
}
Rectangle_shape::Rectangle_shape(xy_point new_center, color new_fill, rect_dim new_dimensions) :
    Shape(new_center, new_fill) {
    set_dimensions(new_dimensions);
}

// Getters
xy_point Rectangle_shape::get_center() const {
    return center;
}
rect_dim Rectangle_shape::get_dimensions() const{
    return dimensions;
}
double Rectangle_shape::get_length() const{
    return dimensions.length;
}
double Rectangle_shape::get_width() const{
    return dimensions.width;
}

// Setters
void Rectangle_shape::set_dimensions(rect_dim new_dimensions){
    if (new_dimensions.length > 0.0 && new_dimensions.width > 0.0 ){
        dimensions = new_dimensions;
    }
    else {
        dimensions = {1.0, 1.0};
        std::cout << "Side lengths must be positive values. The dimensions have been set to default 1.0 x 1.0." << std::endl;
    }
}

void Rectangle_shape::set_length(double length){
    if (length == 0.0) {
        dimensions.length = 1.0;
        std::cout << "Side length may not be zero. It has been set to default value of 1.0." << std::endl;
    }
    else if (length < 0.0) {
        dimensions.length = abs(length);
        std::cout << "Side length may not be negative. It has been set to the absolute value." << std::endl;
    }
    else {
        dimensions.length = (length);
    }
}
void Rectangle_shape::set_width(double width){
    if (width == 0.0) {
        dimensions.width = 1.0;
        std::cout << "Side length may not be zero. It has been set to default value of 1.0." << std::endl;
    }
    else if (width < 0.0) {
        dimensions.width = abs(width);
        std::cout << "Side length may not be negative. It has been set to the absolute value." << std::endl;
    }
    else {
        dimensions.width = (width);
    }
}


// Override parent's pure virtual methods
void Rectangle_shape::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0,1.0); glVertex2i(get_center_x() - ((int)get_length() / 2), get_center_y() - ((int)get_width() / 2));
    glTexCoord2d(0.0,0.0); glVertex2i(get_center_x() - ((int)get_length() / 2), get_center_y() + ((int)get_width() / 2));
    glTexCoord2d(1.0,0.0); glVertex2i(get_center_x() + ((int)get_length() / 2), get_center_y() + ((int)get_width() / 2));
    glTexCoord2d(1.0,1.0); glVertex2i(get_center_x() + ((int)get_length() / 2), get_center_y() - ((int)get_width() / 2));
    glEnd();
}

vector<xy_point> Rectangle_shape::get_bounds() const{
    vector<xy_point> bounds;
    xy_point bottom_left;
    xy_point top_right;
    bottom_left.x = get_center_x() - (get_length()/2.0);
    bottom_left.y = get_center_y() + (get_width()/2.0);
    bounds.push_back(bottom_left);
    top_right.x = get_center_x() + (get_length()/2.0);
    top_right.y = get_center_y() - (get_width()/2.0);
    bounds.push_back(top_right);
    return bounds;
}

double Rectangle_shape::calculate_area() const{
    return get_length() * get_width();
}
double Rectangle_shape::calculate_perimeter() const{
    return 2 * (get_length() + get_width());
}

