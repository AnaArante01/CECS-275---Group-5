/*
* This C++ program creates and tests a pure abstract class to establish interfaces for classes.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
using namespace std;

// create a pure abstract class for shape 

class Shape {
    public:
    // anything that is a shape must override function print
    virtual void calcArea() const = 0;
    virtual void draw() const = 0;
    // destructor to perform neccessary cleanup operations
    // for the class object before it is removed from memory
    virtual ~Shape() = default;

};

class Circle : Shape { // inherit this publicly to allow polymorphism

    private:
    int  CenterX;
    int  CenterY;
    int  radius;


    public:
    // constructor to initialize values upon creation

    Circle( int x, int y, int r): CenterX(x), CenterY(y), radius(r){
        if ( radius < 0){
            cout << "radius cannot be negative!!\n";
        }
    }
    // initialize the member variable using the parameter x to immediately set the object
    void setValues( int x, int y, int r){
        if (r < 0){
            cout << "radius cannot be negative!!\n";
        }
        CenterX = x;
        CenterY = y;
        radius = r;
    }

    void getValues( int &x, int &y, int &r){
       x = CenterX;
       y = CenterY;
       r = radius;
    }
 

    virtual void calcArea() const override {
        // area of a circle 
        // area of a circle = pi * r ^ 2
        int pi = 3.14;
        int newradius = radius * radius;
        int AreaCircle = pi * newradius;
        cout << " The radius of a circle is: " << newradius;
    }

    virtual void draw() const override {
        // draw the circle using the array
    }


    // private members: centerx, centerY, radius
    // public members functions: constructors takes centerX..
    //centerY, radius as parameters, getter/setter for private members
    //, override calcArea and draw function

};

class Rectangle : Shape{

        virtual void calcArea() const {

    // private memberss: width, heifht, centerX
    // centerY
    // public member functions: constructor takes width, 
    //height, centerX, and centerY as parameters, 
    //getter/setter for private members, override

};
