/*
* This C++ program creates and tests a pure abstract class to establish interfaces for classes.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <numeric>
using namespace std;


#ifndef Lab15_suphia_classes_h
#define Lab15_suphia_classes_h

// create a pure abstract class for shape 

 void displayShape();
 void ClearShape();

class Shape {
    public:
    // anything that is a shape must override function print
    virtual void calcArea() const = 0;
    virtual void draw() const = 0;
    // destructor to perform neccessary cleanup operations
    // for the class object before it is removed from memory
    virtual ~Shape() = default;
  
};

class Circle : public Shape { // inherit this publicly to allow polymorphism
    private:
    
    int  CenterX;
    int  CenterY;
    int  radius;
    
    public:
    // constructor to initialize values upon creation
    Circle( int x, int y, int r): CenterX(x), CenterY(y), radius(r)
    {
        if ( radius < 0){
            cout << "radius cannot be negative!!\n";
        }
    }

    // initialize the member variable using the parameter x to immediately set the object
    void setValues( int x, int y, int r);
    void getValues( int &x, int &y, int &r);

    virtual void calcArea() const override;
    virtual void draw() const override;
};

class Rectangle : public Shape{
    private: 

    int Width_Rect;
    int Height_Rect;
    int CenterX_Rect;
    int CenterY_Rect;

    public:

    Rectangle(int x, int y, int w, int h) : CenterX_Rect(x), CenterY_Rect(y), Height_Rect(h), Width_Rect(w)
        {
        if ( (Height_Rect < 0) || Width_Rect < 0){
            cout << "Values cannot be negative!!\n";
          }
        }
    
    void getValues( int &x, int &y, int &w, int &h);
    void setValues( int x, int y, int w, int h);
    virtual void calcArea() const override;
    virtual void draw() const override;       
};

#endif
