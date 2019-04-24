//
// Created by Lisa Dion on 10/3/18.
//

#ifndef SHAPES_SHAPES_H
#define SHAPES_SHAPES_H

struct center_point {
    double x;
    double y;
};

struct color {
    double red;
    double green;
    double blue;
};

class Shape {
public:

    color fill;
    center_point center;
    center_point velocity;
    // Constructors

    /*
     * Requires: Nothing
     * Modifies: Sets center to (0,0) and fill color to black
     * Effects: Creates a new shape object with default values
     */
    Shape();

    /*
     * Requires: Color rgb values are between 0.0 and 1.0
     * Modifies: Sets center and fill color to values given
     * Effects: Creates a new shape object with given fill color and center location
     */
    Shape(center_point new_center, color new_fill);


    // Getters

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns the field value (or part of the struct independently)
     */
    center_point get_center() const;
    int get_center_x() const;
    int get_center_y() const;
    color get_fill() const;
    double get_fill_red() const;
    double get_fill_green() const;
    double get_fill_blue() const;

    // Setters

    /*
    * Requires: For fill setters, parameter values must be between 0.0 and 1.0
    * Modifies: Field value (or part of the struct independently)
    * Effects: Sets the object center, color, or part of the struct independently
    */
    void set_center(center_point new_center);
    void set_center_x(int x);
    void set_center_y(int y);
    void set_fill(color new_fill);
    void set_fill_red(double red);
    void set_fill_green(double green);
    void set_fill_blue(double blue);

    /*
    * Requires: Nothing
    * Modifies: Center location of the shape
    * Effects: Moves the center of the shape by the given change values
    */
    void move(int delta_x, int delta_y);

    void fly();

    void flipSide();

    bool isOffScreen();

    // Pure virtual methods

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Will be instantiated by child classes to draw the specific shape
     */
    virtual void draw() const = 0;

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Will be instantiated by child classes to calculate and return area using the correct method for that shape
    */
    virtual double calculate_area() const = 0;

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Will be instantiated by child classes to calculate and return perimeter using the correct method for that shape
    */
    virtual double calculate_perimeter() const = 0;

};


#endif //SHAPES_SHAPES_H