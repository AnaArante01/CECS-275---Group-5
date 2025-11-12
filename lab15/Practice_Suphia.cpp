// in this program Derive class from Shape called Circle
// Derive class from shape called Rectangle 
// Pure abstract base class called shape (1)
// After you implement these functions in the main
// you have to create an array of SHape and add different circle 
// and rectangle with different sizes into this array
// draw it out using an 2D Array


// Practice to create a pure abstract class 
// public member functions: calcArea(virtual function) and
// draw()
// gonna try to use constructors as well
// take it one thing at a time
// you can create three files, two cpp, one h to test and run the main program
// Abstract base class contains at least one pure virtual function
// base - class -- abstract
// contain >= 1 pure virtual function 
// only exist to be derived from 
// virtual functions makes the class abstract 

// base class -- abstract
// contains one pure virtual function
// only exists to be derived from
#include <iostream>
using namespace std;
class foo{
    public:
    // anything that is a foo must override function print
    virtual void print() const = 0;

};


class bar: public foo {
    public:
    // have to override or bar will not compile

    virtual void print() const{
    cout << " I am a bar class\n";
    }

};



int main (){
    bar b;
    b.print();


}



