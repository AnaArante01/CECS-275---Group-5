/*
* This C++ program creates and tests a Data class.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#ifndef CLASSES_ANA_H
#define CLASSES_ANA_H

#include <string>
#include <iostream>

using namespace std;

// Function Prototypes
void displayMenu();

// Date class declaration
class Date
{
    private:
        int month{0}, day{0}, year{0}; // Default constructor sets all values to 0

        static bool isLeap(int y);
        static int daysInMonth(int m, int y);
        static bool isValidDate(int m, int d, int y);

        long long toSerial() const;
        static Data fromSerial(long long s);

    public:
        // Default constructor
        Date() = default;
        Date(int m, int d, int y);

        // Setters
        void setMonth(int m);
        void setDay(int d);
        void setYear(int y);

        // Getters
        int getMonth() const { return month; }
        int getDay() const { return day; }
        int getYear() const { return year; }
        
        // Formatting Functions
        string monthName() const;
        string format_MDY() const;
        string format_MNDY() const;
        string format_DMNY() const;

        // Required
        bool isLeapYear() const;
        //bool daysBetween( const Data& other) const;
        void increment();
        void decrement();
        //int compare(const Date& other) const;
};

// Function Prototypes
void displayMenu();

#endif // CLASSES_ANA_H