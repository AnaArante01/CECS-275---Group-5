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

    Shape* shapes[3];

    shapes[0] = new Rectangle(4, 5, 10, 10);
    shapes[1] = new Rectangle(6, 3, 5, 5);
    shapes[2] = new Rectangle(2, 8, 15, 15);

    for (int i = 0; i < 3; i++){
        cout << "Shape " << i + 1 << ":" << endl;
        cout << "Area: " << shapes[i]->calcArea() << endl;
        shapes[i]->draw();
        cout << endl;
    }

    /* // Variables for rectangle
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

    // Build a rectangle either via constructor or setters
    Rectangle rectangle; // use default constructor
    rectangle.setWidth(rectWidth);
    rectangle.setHeight(rectHeight);
    rectangle.setCenterRX(rectCenterX);
    rectangle.setCenterRY(rectCenterY);

    double area = rectangle.calcArea();
    cout << "Rectangle area: " << area << endl; */






    return 0;
}
