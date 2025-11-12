/*
* This C++ program creates and tests a pure abstract class to establish interfaces for classes.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#ifndef RECTANGLE_ANA_H
#define RECTANGLE_ANA_H

#include "shape_ana.h"
#include <iostream>

using namespace std;

class Rectangle : public Shape {
    public:
    // Default constructor
    Rectangle();
    // Construct a rectangle with width, height, and center coordinates
    Rectangle(int w, int h, int centRX, int centRY);
    double calcArea();
    void draw();
};

#endif // RECTANGLE_ANA_H