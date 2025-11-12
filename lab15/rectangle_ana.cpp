/*
* This C++ program creates and tests a pure abstract class to establish interfaces for classes.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include "rectangle_ana.h"
#include <iostream>

using namespace std;

// Function overriding
double Rectangle::calcArea()
{
    // Area of a rectangle = width * height
    return getWidth() * getHeight();
}