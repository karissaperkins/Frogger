//
// Created by Kristin on 2/21/2019.
//

#ifndef SHAPES_RECTANGLE_SHAPE_H
#define SHAPES_RECTANGLE_SHAPE_H

#include "shapes.h"

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

struct rect_dim {
    double length;
    double width;
};

class Rectangle_shape : public Shape {
protected:
    center_point center;
    rect_dim dimensions;
public:

    // Constructors

    /*
     * Requires: Nothing
     * Modifies: Sets center to (0,0), dimensions to 1.0 x 1.0, and fill color to black
     * Effects: Creates a new rectangle object with default values
     */
    Rectangle_shape();

    /*
     * Requires: Color rgb values are between 0.0 and 1.0, dimension values are positive and non-zero
     * Modifies: Sets center, fill color, and length and width to values given
     * Effects: Creates a new rectangle object with given fill color, center location, and dimensions
     */
    Rectangle_shape(center_point new_center, color new_fill, rect_dim new_dimensions);

    // Getters

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns the dimensions (or length or width independently)
     */
    center_point get_center() const;
    rect_dim get_dimensions() const;
    double get_length() const;
    double get_width() const;

    // Setters

    /*
    * Requires: Dimension values must be positive and non-zero
    * Modifies: Dimensions (or length or width independently)
    * Effects: Sets the object dimensions (or length or width independently)
    */
    void set_dimensions(rect_dim new_dimensions);
    void set_length(double length);
    void set_width(double width);

    // Override parent's pure virtual methods

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Currently prints "Drawing a rectangle..." to the console. Will be used later to draw the rectangle
    */
    virtual void draw() const override;

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Calculates and returns the area of the rectangle
    */
    virtual double calculate_area() const override;

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Calculates and returns the perimeter of the rectangle
    */
    virtual double calculate_perimeter() const override;

};



#endif //SHAPES_RECTANGLE_SHAPE_H