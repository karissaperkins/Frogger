//
// Created by Kristin on 2/21/2019.
//

#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

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

#include "shapes.h"

class Circle : public Shape {
protected:
    double radius;
public:

    // Constructors

    /*
     * Requires: Nothing
     * Modifies: Sets center to (0,0), radius to 1.0, and fill color to black
     * Effects: Creates a new circle object with default values
     */
    Circle();

    /*
     * Requires: Color rgb values are between 0.0 and 1.0, radius value is positive and non-zero
     * Modifies: Sets center, fill color, and radius to values given
     * Effects: Creates a new circle object with given fill color, center location, and radius
     */
    Circle(center_point new_center, color new_fill, double new_radius);

    // Getter

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns the radius value
     */
    double get_radius() const;

    // Setter

    /*
    * Requires: Radius value must be positive and non-zero
    * Modifies: Radius of the circle object
    * Effects: Sets the radius
    */
    void set_radius (double new_radius);

    // Override parent's pure virtual methods

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Currently prints "Drawing a circle..." to the console. Will be used later to draw the circle
    */
    virtual void draw() const override;

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Calculates and returns the area of the circle
    */
    virtual double calculate_area() const override;

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Calculates and returns the perimeter of the circle
    */
    virtual double calculate_perimeter() const override;

};


#endif //SHAPES_CIRCLE_H