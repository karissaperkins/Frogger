//
// Created by Lisa Dion on 10/3/18.
//

#include "shapes.h"
#include <iostream>

// Constructors
Shape::Shape(){
    set_center({0,0});
    set_fill({0.0, 0.0, 0.0});
}
Shape::Shape(center_point new_center, color new_fill){
    set_center(new_center);
    set_fill(new_fill);
}

// Getters
center_point Shape::get_center() const{
    return center;
}
int Shape::get_center_x() const{
    return center.x;
}
int Shape::get_center_y() const{
    return center.y;
}
color Shape::get_fill() const{
    return fill;
}
double Shape::get_fill_red() const{
    return fill.red;
}
double Shape::get_fill_green() const{
    return fill.green;
}
double Shape::get_fill_blue() const{
    return fill.blue;
}


// Setters
void Shape::set_center(center_point new_center){
    center = new_center;
}
void Shape::set_center_x(int x){
    center.x = x;
}
void Shape::set_center_y(int y){
    center.y = y;
}
void Shape::set_fill(color new_fill){
    if (0.0 <= new_fill.red <= 1.0 && 0.0 <= new_fill.green <= 1.0 && 0.0 <= new_fill.blue <= 1.0 ){
        fill = new_fill;
    }
    else{
        fill = {0.0, 0.0, 0.0};
        std::cout << "rgb values of fill color must be between 0.0 and 1.0. The fill color has been set to default black." << std::endl;
    }
}
void Shape::set_fill_red(double red){
    if (0.0 <= red <= 1.0) {
        fill.red = red;
    }
    else {
        fill.red = 0.0;
        std::cout << "red value of fill color must be between 0.0 and 1.0. It has been set to default 0.0." << std::endl;
    }
}
void Shape::set_fill_green(double green){
    if (0.0 <= green <= 1.0) {
        fill.green = green;
    }
    else {
        fill.green = 0.0;
        std::cout << "green value of fill color must be between 0.0 and 1.0. It has been set to default 0.0." << std::endl;
    }
}
void Shape::set_fill_blue(double blue){
    if (0.0 <= blue <= 1.0) {
        fill.blue = blue;
    }
    else {
        fill.blue = 0.0;
        std::cout << "blue value of fill color must be between 0.0 and 1.0. It has been set to default 0.0." << std::endl;
    }
}


void Shape::move(int delta_x, int delta_y) {
    set_center_x(get_center_x() + delta_x);
    set_center_y(get_center_y() + delta_y);
}