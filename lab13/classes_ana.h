/*
* This C++ program creates and tests a Data class.
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#ifndef CLASSES_ANA_H
#define CLASSES_ANA_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Date class declaration
class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        // Default constructor
        //Date();
        void setMonth(int);
        void setDay(int);
        void setYear(int);
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        string getMonthName() const;
};





#endif // CLASSES_ANA_H