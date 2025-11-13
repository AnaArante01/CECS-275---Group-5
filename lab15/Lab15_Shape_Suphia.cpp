#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <numeric>
#include "lab15_suphia_classes.h"
using namespace std;


// Define dimensions for our drawing area 
const int Width = 40;
const int Height = 20;
const char Shape_char = '.';
const char Empty_char = ' ';



// global 2d array
std::vector<std::string> shape( Height, std::string(Width, Empty_char));

//function to clear
void ClearShape(){
    for (int x = 0; x < Height; x++){
        for ( int y = 0; y < Width; y++){
            shape[x][y] = Shape_char;
        }
    }
}

// function to create a "canvas" to draw the shape 
void displayShape() {
    std::string border = "+";
        for ( int x = 0; x < Width; x++){
            border += "-"; // append one hyphen at a time

        }
            border += "+";
            std::cout<<border<<endl;
            for( int y = 0; y < Height; y++){
                std:: cout << "|";
                std:: cout << shape[y];
                std:: cout << "|" << std::endl;
            }
            std::cout<<border<<endl;

}

    void Circle::setValues(int x, int y, int r){
           if (r < 0){
            cout << "radius cannot be negative!!\n";
        }
        CenterX = x;
        CenterY = y;
        radius = r;
    }
    

    void Circle::getValues(int &x, int &y, int &r){
         x = CenterX;
         y = CenterY;
         r = radius;
    }
    
    // declared as a virtual in the other file
     void Circle::calcArea() const {
        // area of a circle 
        // area of a circle = pi * r ^ 2
        double pi = 3.14;
        double newradius = radius * radius;
        double AreaCircle = pi * newradius;
        cout << " The radius of a circle is: " << AreaCircle;
    }

    //declared as a virtual function in other file
       void Circle::draw() const {
        for ( int x = CenterY - radius; x <= CenterY + radius; ++x){
            for (int y = CenterX - radius; y <= CenterX + radius; ++y){
                if (( y - CenterX) * (x - CenterX) + ( y - CenterY) * ( x - CenterY) <= (radius * radius)){
                    // check bounds
                        if ( x >= 0 && x < Width && y >= 0 && y < Height) {
                          if ( y == CenterY || y == CenterY + radius - 1 || x == CenterX || x == CenterX + radius - 1)
                          {

                            shape[x][y] = Shape_char;                            
                        }
                }
            }
        }
    }
}

    // if the width and height is less than the border rhen draw the shape 
    // do rectangle first

    // you can do a switch case to decide what to draw

    // rectangle class
    void Rectangle::setValues( int x, int y, int h, int w){
        if ( (Height_Rect < 0) || Width_Rect < 0){
            cout << "Values cannot be negative!!\n";
          }
        CenterX_Rect = x;
        CenterY_Rect = y;
        Height_Rect = h;
        Width_Rect = w;

    }

     void Rectangle::getValues( int &x, int &y, int &h, int &w){
        x = CenterX_Rect;
        y = CenterY_Rect;
        h = Height_Rect;
        w = Width_Rect;
    }

    void Rectangle::calcArea() const {
        double Area_Rect = Width_Rect * Height_Rect;
        std::cout << " Rectangle area:" << Area_Rect << std::endl;
    }

    void Rectangle::draw() const{
        for ( int y = CenterY_Rect; y < CenterY_Rect + Height_Rect; ++y){
            for ( int x = CenterX_Rect; x < CenterX_Rect + Width_Rect; ++x){
                     if ( x >= 0 && x < Width && y >= 0 && y < Height) {
                        if ( y == CenterY_Rect || y == CenterY_Rect + Height_Rect - 1 || x == CenterX_Rect || x == CenterX_Rect + Width_Rect - 1)
                        {
                        // modifies the shape array
                        shape[y][x] = Shape_char;
                    }
            }
        }

      }
    
    }

  

