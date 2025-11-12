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

/*
* setCenteX sets the value of the member variable centerX
*/
void Shape::setCenterX(int cx){
    centerX = cx;
}

/*
* setCenterY sets the value of the member variable centerY
*/
void Shape::setCenterY(int cy){
    centerY = cy;
}

/*
* setRadius sets the value of the member variable radius
*/
void Shape::setRadius(int r){
    radius = r;
}

/*
* setWidth sets the value of the member variable width
*/
void Shape::setWidth(int w){
    width = w;
}

/*
* setHeight sets the value of the member variable height
*/
void Shape::setHeight(int h){
    height = h;
}

/*
* setCenterRX sets the value of the member variale centerRX
*/
void Shape::setCenterRX(int rx){
    centerRX = rx;
}

/*
* setCenterRY sets the value of the member variable centerRY
*/
void Shape::setCenterRY(int ry){
    centerRY = ry;
}

/*
* getCenterX returns the value in the centerX member
*/
int Shape::getCenterX() const{
    return centerX;
}

/*
* getCenterY returns the value in the centerY member
*/
int Shape::getCenterY() const{
    return centerY;
}

/*
* getRadius returns the value in the radius member
*/
int Shape::getRadius() const{
    return radius;
}

/*
* getWidth returns the value in the width member
*/
int Shape::getWidth() const{
    return width;
}

/*
* getHeight returns the value in the height member
*/
int Shape::getHeight() const{
    return height;
}

/*
* getCenterRX returns the value in the centerRX member
*/
int Shape::getCenterRX() const{
    return centerRX;
}

/*
* getCenterRY returns the value in the centerRY member
*/
int Shape::getCenterRY() const{
    return centerRY;
}

/*
   Default constructor that sets all properties for rectangle to 0
*/
Shape::Shape(){
    // Set default values for circle
    centerX = 0;
    centerY = 0;
    radius = 0;

    // Set default values for rectangle
    width = 0;
    height = 0;
    centerRX = 0;
    centerRY = 0;
}

Shape::Shape(const int& centX, const int& centY, const int& rad){
    centerX = centX;
    centerY = centY;
    radius = rad;
}

Shape::Shape(const int& w, const int& h, const int& centRX, const int& centRY){
    width = w;
    height = h;
    centerRX = centRX;
    centerRY = centRY;
}

// Note: calcArea() is a pure virtual function and does not have an implementation here.