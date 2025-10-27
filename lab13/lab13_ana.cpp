/*
* This C++ program creates and tests a Data class.
*
* Example: 
* Display the date in each of the following formats:
* 1. 8/25/2025
* 2. August 25, 2025
* 3. 25 August 2025
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
#include <iomanip>

// Header file for the Date class
#include "classes_ana.h"

using namespace std;

//*******************************************************
// setMonth sets the value of the member variable month*
//*******************************************************
void Date::setMonth(int m)
{
    month = m;
}

//**************************************************
// setDay sets the value of the member variable day*
//**************************************************
void Date::setDay(int d)
{
    day = d;
}

//****************************************************
// setYear sets the value of the member variable year*
//****************************************************
void Date::setYear(int y)
{
    year = y;
}

//************************************************
// getMonth returns the value in the month member*
//************************************************
int Date::getMonth() const
{
    return month;
}

//********************************************
// getDay returns the value in the day member*
//********************************************
int Date::getDay() const
{
    return day;
}

//**********************************************
// getYear returns the value in the year member*
//**********************************************
int Date::getYear() const
{
    return year;
}

//****************************************************
// Function main                                     *
//****************************************************
int main()
{
    Date today;
    Date future;
    int month, day, year;

    cout << "Enter month (1-12): ";
    cin >> month;

    cout << "Enter day (1-31): ";
    cin >> day;

    cout << "Enter year (e.g., 2025): ";
    cin >> year;
    cout << endl;

    // Store the month, day, and year in the today object
    today.setMonth(month);
    today.setDay(day);
    today.setYear(year);

    // Display the month, day, and year in the first format: 8/25/2025
    cout << "------------------------------------------------" << endl;
    cout << "Here is the date in the first format: " << today.getMonth() << "/" << today.getDay() << "/" << today.getYear() << endl;
    

    return 0;
}