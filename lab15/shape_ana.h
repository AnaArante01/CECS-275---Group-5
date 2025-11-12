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
        // Variables for class Circle
        int centerX, centerY, radius;
        
        // Variables for class Rectangle
        int width, height, centerRX, centerRY;

    public:

        // Setters
        void setCenterX(int cx);
        void setCenterY(int cy);
        void setRadius(int r);
        void setWidth(int w);
        void setHeight(int h);
        void setCenterRX(int rx);
        void setCenterRY(int ry);

        // Getters
        int getCenterX() const;
        int getCenterY() const;
        int getRadius() const;
        int getWidth() const;
        int getHeight() const;
        int getCenterRX() const;
        int getCenterRY() const;

        /*
        * Default constructor
        */
        Shape();

        /*
        * Overloaded constructor that takes centerX, centerY, and radius as parameters
        * @param centX - x coordinate of ceenter of the circle
        * @param centY - y coordinate of center of the circle
        * @param rad - radius of the circle
        */
        Shape(const int& centX, const int& centY, const int& rad);

        /*
        * Overloaded constructor that takes centerX, centerY, and radius as parameters
        * @param w - width of the rectangle
        * @param h - height of the rectangle
        * @param centRX - x coordinate of the center of the rectangle
        * @param centRY - y coordinate of the center of the rectangle
        */
        Shape(const int& w, const int& h, const int& centRX, const int& centRY);

       /*
       * This function calculates the area of a shape
       */
        virtual double calcArea() = 0;
        // virtual makes Shape an abstract class
        // = 0 means that Shape is a pure abstract class
        
        /*
       * This function draws a shape
       */
        virtual void draw() = 0;
};

#endif // SHAPE_ANA_H