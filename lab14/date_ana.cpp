/*
* This C++ program creates a Data class.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
#include "date_ana.h"

using namespace std;

// Function to convert month number to month name
// Example: 1 -> January
static string nameFromMonth(const int& month)
{
    if (month == 1) return "January";
    if (month == 2) return "February";
    if (month == 3) return "March";
    if (month == 4) return "April";
    if (month == 5) return "May";
    if (month == 6) return "June";
    if (month == 7) return "July";
    if (month == 8) return "August";
    if (month == 9) return "September";
    if (month == 10) return "October";
    if (month == 11) return "November";
    if (month == 12) return "December";
    return "Invalid Month Number";
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

//************************************************
// getMonth returns the value in the month member*
//************************************************
string Date::getMonthName() const
{
    return nameFromMonth(month);
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

/*
   Default constructor that sets all properties to 0
*/
Date::Date(){
    month = 0;
    day = 0;
    year = 0;
}

// Overloaded constructor: month number, day, year
Date::Date(const int& m, const int& d, const int& y)
{
    month = m;                  // Store the month number
    mName = nameFromMonth(m);   // Convert month number to month name string
    day = d;
    year = y;
}

const Date Date::operator+ (int i) const
{
    Date result = *this;
    // Simple addition to the day (not accounting for month/year overflow)
    result.day += i;
    return result;
}

const Date Date::operator+ (const Date& otherDate) const
{
    Date result = *this;
    // Simple addition of days from another Date object (not accounting for month/year overflow)
    result.day += otherDate.day;
    return result;
}

const Date Date::operator- (int i) const
{
    Date result = *this;
    // Simple subtraction from the day (not accounting for month/year underflow)
    result.day -= i;
    return result;
}

const Date Date::operator- (const Date& otherDate) const
{
    Date result = *this;
    // Simple subtraction of days from another Date object (not accounting for month/year underflow)
    result.day -= otherDate.day;
    return result;
}

bool Date::operator==(const Date &otherDate) const
{
    return this->day == otherDate.day &&
           this->month == otherDate.month &&
           this->year == otherDate.year;
}

bool Date::operator!=(const Date &otherDate) const
{
    return !(*this == otherDate);
}

/*
   Non-member function for operator overloading <<
*/
ostream& operator<< (ostream &out, const Date &date)
{
    out << date.mName << " " << date.day << ", " << date.year << endl;
    return out;
}

/*
   Non-member function for operator overloading <<
*/
istream& operator>> (istream &in, Date &date)
{
    in >> date.mName;
    in >> date.day;
    in >> date.year;
    return in;
}

