/*
* This C++ program creates and tests a pure abstract class to establish interfaces for classes.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
#include "shape_ana.h"
#include "rectangle_ana.h"

using namespace std;

int main() {

    // Variables for rectangle
    int rectWidth, rectHeight, rectCenterX, rectCenterY;

    // Prompt user to enter rectangle dimensions
    cout << "Enter the width of the rectangle: ";
    cin >> rectWidth;
    cout << "Enter the height of the rectangle: ";
    cin >> rectHeight;
    cout << "Enter the center X coordinate of the rectangle: ";
    cin >> rectCenterX;
    cout << "Enter the center Y coordinate of the rectangle: ";
    cin >> rectCenterY;

    Rectangle rectangle(rectWidth, rectHeight, rectCenterX, rectCenterY);

    rectangle.calcArea();






    return 0;
}
