/*
* This C++ program creates and tests a pure abstract class to establish interfaces for classes.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#ifndef SHAPE_ANA_H
#define SHAPE_ANA_H

#include <iostream>
#include <string>

using namespace std;

class Shape {
    private:
        int centerX, centerY, radius;
    public:
        /*
        * Default constructor
        */
        Shape();

        /*
        * Overloaded constructor that takes centerX, centerY, and radius as parameters
        * @param centX - x coordinate of center
        * @param centY - y coordinate of center
        * @param rad - radius of the shape
        */
        Shape(int centX, int centY, int rad);

}







#endif // SHAPE_ANA_H