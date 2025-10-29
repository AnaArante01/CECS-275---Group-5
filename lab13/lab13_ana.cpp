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

//**********************************************
// getYear returns the value in the year member*
//**********************************************
void Date::setMonthName()
{
    string mName;
    if (month == 1){
        mName = "January";
    }
    else if (month == 2){
        mName = "February";
    }
    else if (month == 3){
        mName = "March";
    }
    else if (month == 4){
        mName = "April";
    }
    else if (month == 5){
        mName = "May";
    }
    else if (month == 6){
        mName = "June";
    }
    else if (month == 7){
        mName = "July";
    }
    else if (month == 8){
        mName = "August";
    }
    else if (month == 9){
        mName = "September";
    }
    else if (month == 10){
        mName = "October";
    }
    else if (month == 11){
        mName = "November";
    }
    else if (month == 12){
        mName = "December";
    }
    monthName = mName;
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

//************************************************
// getMonth returns the value in the month member*
//************************************************
string Date::getMonthName() const
{
    return monthName;
}

//****************************************************
// Function main                                     *
//****************************************************
int main()
{
    Date today;
    Date future;
    int month, day, year;
    int fMonth, fDay, fYear;

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
    today.setMonthName();

    // DISPLAY THE FIRST DATE IN THE THREE FORMATS
    // Display the month, day, and year in the first format: 8/25/2025
    cout << "--------------------------------------------------------" << endl;
    cout << "Here is the date in the first format: " << setw(2) << setfill('0') << today.getMonth() << "/" << setw(2) << setfill('0') << today.getDay() << "/" << today.getYear() << endl;
    // Display the month, day, and year in the second format: August 25, 2025
    cout << "Here is the date in the second format: " << today.getMonthName() << " " << setw(2) << setfill('0') << today.getDay() << ", " << today.getYear() << endl;
    // Display the month, day, and year in the third format: 25 August 2025
    cout << "Here is the date in the third format: " << setw(2) << setfill('0') << today.getDay() << " " << today.getMonthName() << " " << today.getYear() << endl;
    cout << "--------------------------------------------------------" << endl;

    // Prompts user to enter a second date
    cout << endl << "Enter another date: " << endl;
    cout << "Enter month (1-12): ";
    cin >> fMonth;
    cout << "Enter day (1-31): ";
    cin >> fDay;
    cout << "Enter year (e.g., 2025): ";
    cin >> fYear;

    future.setMonth(fMonth);
    future.setDay(fDay);
    future.setYear(fYear);
    future.setMonthName();

    // DISPLAY THE SECOND DATE IN THE THREE FORMATS
    // Display the month, day, and year in the first format: 8/25/2025
    cout << "--------------------------------------------------------" << endl;
    cout << "Here is the date in the first format: " << setw(2) << setfill('0') << future.getMonth() << "/" << setw(2) << setfill('0') << future.getDay() << "/" << future.getYear() << endl;
    // Display the month, day, and year in the second format: August 25, 2025
    cout << "Here is the date in the second format: " << future.getMonthName() << " " << setw(2) << setfill('0') << future.getDay() << ", " << future.getYear() << endl;
    // Display the month, day, and year in the third format: 25 August 2025
    cout << "Here is the date in the third format: " << setw(2) << setfill('0') << future.getDay() << " " << future.getMonthName() << " " << future.getYear() << endl;
    cout << "--------------------------------------------------------" << endl;

    int choice;
    displayMenu();  // Display menu
    cout << "Enter your choice: ";
    cin >> choice;  // Prompt user for choice
    cout << endl;

    switch (choice)
    {
        case 1: // Check if a year is a leap year
        {
            int year;
            cout << "Enter a year: ";
            cin >> year;

            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                cout << year << " is a leap year." << endl;
            else
                cout << year << " is not a leap year." << endl;
        }
            break;
        case 2: // Calculate the number of days between two dates
        {
                Date date1, date2;
                // Get input for the first date
                int month, day, year;
                cout << "Enter the first date (MM DD YYYY): ";
                cin >> month >> day >> year;
                date1.setMonth(month);
                date1.setDay(day);
                date1.setYear(year);
                date1.setMonthName();

                // Get input for the second date
                cout << "Enter the second date (MM DD YYYY): ";
                cin >> month >> day >> year;
                date2.setMonth(month);
                date2.setDay(day);
                date2.setYear(year);
                date2.setMonthName();

                // Calculate the number of days between the two dates
                int daysBetween = abs((date2.getYear() - date1.getYear()) * 365 + (date2.getMonth() - date1.getMonth()) * 30 + (date2.getDay() - date1.getDay()));
                cout << "The number of days between " << date1.getMonthName() << " " << date1.getDay() << ", " << date1.getYear() << " and " << date2.getMonthName() << " " << date2.getDay() << ", " << date2.getYear() << " is " << daysBetween << " days." << endl;
        }
            break;
        case 3: // Increase a date by one
            {
                Date date;
            }
            break;
        case 4: // Decrease a date by one
            
            break;
        case 5: // Compare two dates
            {
                Date date1, date2;
                // Get input for the first date
                int month, day, year;
                cout << "Enter the first date (MM DD YYYY): ";
                cin >> month >> day >> year;
                date1.setMonth(month);
                date1.setDay(day);
                date1.setYear(year);
                date1.setMonthName();

                // Get input for the second date
                cout << "Enter the second date (MM DD YYYY): ";
                cin >> month >> day >> year;
                date2.setMonth(month);
                date2.setDay(day);
                date2.setYear(year);
                date2.setMonthName();

                // Compare the two dates
                if (date1.getYear() == date2.getYear() && date1.getMonth() == date2.getMonth() && date1.getDay() == date2.getDay())
                    cout << "The two dates are the same." << endl;
                else
                    cout << "The two dates are different." << endl;
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }


    return 0; // End of program
}