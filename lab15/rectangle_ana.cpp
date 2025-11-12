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

// Default constructor
Rectangle::Rectangle() {
    setWidth(0);
    setHeight(0);
    setCenterRX(0);
    setCenterRY(0);
}

// Forward constructor to base Shape to initialize width/height/center
Rectangle::Rectangle(int w, int h, int centRX, int centRY) : Shape(w, h, centRX, centRY) {}

// Function overriding
double Rectangle::calcArea()
{
    // Area of a rectangle = width * height
    return getWidth() * getHeight();
}

void Rectangle::draw(){
    int w = getWidth();
    int h = getHeight();
    int cx = getCenterRX();
    int cy = getCenterRY();

    // Compute top-left corner
    int left = cx - w / 2;
    int top = cy - h / 2;

    // Draw rectangle inside a 20x20 grid
    const int row = 20;
    const int col = 20;
    char grid[row][col];

    // Fill grid with spaces
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            grid[r][c] = ' ';
        }
    }

    // Draw rectangle borders
    for (int r = top; r < top + h; r++){
        for (int c = left; c < left + w; c++){
            if (r >= 0 && r < row && c >= 0 && c < col){
                grid[r][c] = '*';
            }
        }
    }

    // Print the grid
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            cout << grid[r][c];
        }
        cout << endl;
    }
}