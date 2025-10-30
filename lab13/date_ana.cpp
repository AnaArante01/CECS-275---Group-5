/*
* This C++ program creates and tests a Data class.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <array>
#include <iomanip>
#include <string>

// Header file for Date class
#include "classes_ana.h"

using namespace std;

static bool Date::isLeap(int y)
{
    return (y % 4 ==0 && y % 100 !=0) || (y % 400 ==0);
}

int Date::daysInMonth(int m, int y)
{
    static const int base[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2)
    {
        return base[1] + (Date::isLeap(y) ? 1 : 0);
    }
    if (m >= 0 && m <= 12)
    {
        return base[m];
    }
    return 0; // Invalid month
}

bool Date::isValidDate(int m, int d, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1)
        return false;
    int dim = daysInMonth(m, y);
    return d <= dim;
}

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

//**********************************************
// monthName returns the name of the month
//**********************************************
string Date::monthName() const
{
    if (month == 1) {
        return "January";
    }
    else if (month == 2) {
        return "February";
    }
    else if (month == 3) {
        return "March";
    }
    else if (month == 4) {
        return "April";
    }
    else if (month == 5) {
        return "May";
    }
    else if (month == 6) {
        return "June";
    }
    else if (month == 7) {
        return "July";
    }
    else if (month == 8) {
        return "August";
    }
    else if (month == 9) {
        return "September";
    }
    else if (month == 10) {
        return "October";
    }
    else if (month == 11) {
        return "November";
    }
    else if (month == 12) {
        return "December";
    }
    else {
        return "Invalid Input";
    }
}

string Date::format_MDY() const
{
    return (to_string(month) + "/" + to_string(day) + "/" + to_string(year));
}

string Date::format_MNDY() const
{
    return ((monthName() + " " + to_string(day) + ", " + to_string(year)));
}

string Date::format_DMNY() const
{
    return ((to_string(day) + " " + monthName() + " " + to_string(year)));
}




