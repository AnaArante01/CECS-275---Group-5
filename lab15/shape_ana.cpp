/*
* This C++ program creates and tests a pure abstract class to establish interfaces for classes.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include "shape_ana.h"
#include <iostream>

using namespace std;

Shape::Shape(){
    // Set default values
    centerX = 0;
    centerY = 0;
    radius = 0;
}

Shape::Shape(const int& centX, const int& centY, const int& rad){
    centerX = centX;
    centerY = centY;
    radius = rad;
}