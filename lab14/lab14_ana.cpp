/*
* This C++ program creates and tests a Date class with three properties.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <iostream>
#include <iomanip>

// Header file for Date class
#include "date_ana.h"

using namespace std;

int main()
{
    // Display Main Menu
    cout << "---------------- Main Menu ----------------" << endl;
    cout << "Choose between the following options:" << endl;
    cout << "1. Display a date in the format: August 25, 2025" << endl;
    cout << "2. Check if a year is a leap year" << endl;
    cout << "3. Find the number of days between two dates" << endl;
    cout << "4. Increase a date by one day" << endl;
    cout << "5. Decrease a date by one day" << endl;
    cout << "6. Compare two dates" << endl;
    cout << "7. Calculate the date in the future after advancing a number of dates from a current date" << endl;
    cout << "8. Calculate the date in the past after receding a number of days from a current date" << endl;
    cout << "9. Exit program" << endl;
    cout << "-------------------------------------------" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    bool hasDate = false;
    Date currentDate(1, 1, 2000);

    switch(choice)
    {
        case 1: // User chooses to display a date in the format: August 25, 2025
        {
            // Create Date object: date
            Date date;

            // Prompt user to enter a month
            int month;
            cout << "Enter a month (1-12): ";
            cin >> month;
            date.setMonth(month);
            
            // Prompt user to enter a day
            int day;
            cout << "Enter a day (1-31): ";
            cin >> day;
            date.setDay(day);

            // Prompt user to enter a year
            int year;
            cout << "Enter a year (e.g., 2025): ";
            cin >> year;
            date.setYear(year);
           
            // Display the date using overloaded << operator
            cout << endl << "The date you entered is: " << date.getMonthName() << " " << date.getDay() << ", " << date.getYear() << endl;

            break;
        } // End of case 1
        case 2: // User chooses to check if a year is a leap year
        {
            int y;
            if (hasDate){
                y = currentDate.getYear();
            }
            else {
                cout << "Enter a year: ";
                cin >> y;
            }
            Date d = currentDate;
            d.setYear(y);
            if (d.isLeap(y)){
                cout << y << " is a leap year." << endl;
            }
            else {
                cout << y << " is not a leap year." << endl;
            }
            break;
        } // End of case 2
        case 3: // User chooses to find the number of days between two dates
        {
            // Create Date objects: date1, date2
            Date date1, date2;

            // Prompt user to enter the first date
            int month1, day1, year1;
            cout << "Enter the first date in the format MM DD YYYY: ";
            cin >> month1 >> day1 >> year1;
            date1.setMonth(month1);
            date1.setDay(day1);
            date1.setYear(year1);

            // Prompt user to enter the second date
            int month2, day2, year2;
            cout << "Enter the second date in the format MM DD YYYY: ";
            cin >> month2 >> day2 >> year2;
            date2.setMonth(month2);
            date2.setDay(day2);
            date2.setYear(year2);

            // Calculate the number of days between the two dates
            int yearsBetween = (date2.getYear() - date1.getYear()) * 365; // Gets number of days from number of years between two dates
            int monthsBetween = (date2.getMonth() - date1.getMonth()) * 30; // Gets number of days from number of months between two dates
            int daysBetween = date2.getDay() - date1.getDay();  // Gets number of days between two dates
            int totalDaysBetween = abs(yearsBetween + monthsBetween + daysBetween);
            cout << endl << "The number of days between " << date1.getMonthName() << " " << date1.getDay() << ", " << date1.getYear() << " and " << date2.getMonthName() << " " << date2.getDay() << ", " << date2.getYear() << " is " << totalDaysBetween << " days." << endl;

            break;
        } // End of case 3
        case 4: // User chooses to increase a date by one day
        {
            // Prompt user to enter a date
            Date date;
            cout << "The date you will enter will be increased by one day." << endl;
            int month, day, year;
            cout << "Enter a date in the format MM DD YYYY: ";
            cin >> month >> day >> year;
            date.setMonth(month);
            date.setDay(day);
            date.setYear(year);

            if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10))
            {
                date.setMonth(++month);
                date.setDay(1);
            }
            else if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
            {
                date.setMonth(++month);
                date.setDay(1);
            }
            else if (month == 2)
            {
                if (Date::isLeap(year))
                {
                    if (day == 29)
                    {
                        date.setMonth(3);
                        date.setDay(1);
                    }
                    else
                    {
                        ++day;
                    }
                }
                else
                {
                    if (day == 28)
                    {
                        date.setMonth(3);
                        date.setDay(1);
                    }
                    else
                    {
                        ++day;
                    }
                }
            }
            else if (day == 31 && month == 12)
            {
                date.setMonth(1);
                date.setDay(1);
                date.setYear(++year);
            }
            else
            {
                date.setDay(++day);
            }

            cout << "The new date is: " << date.getMonthName() << " " << date.getDay() << ", " << date.getYear() << endl;

            break;
        } // End of case 4
        case 5: // User chooses to decrease a date by one day
        {
            // DOES NOT ACCOUNT FOR MONTH/YEAR UNDERFLOW
            Date date;

            // Prompt user to enter a date
            cout << "The date you will enter will be decreased by one day." << endl;
            int month, day, year;
            cout << "Enter a date in the format MM DD YYYY: ";
            cin >> month >> day >> year;
            date.setMonth(month);
            date.setDay(day);
            date.setYear(year);

            if (day == 1 && (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11))
            {
                date.setMonth(--month);
                date.setDay(31);
            }
            else if (day == 1 && (month == 5 || month == 7 || month == 10 || month == 12))
            {
                date.setMonth(--month);
                date.setDay(30);
            }
            else if (month == 2)
            {
                if (Date::isLeap(year))
                {
                    if (day == 1)
                    {
                        date.setMonth(1);
                        date.setDay(30);
                    }
                    else
                    {
                        date.setDay(--day);
                    }
                }
                else
                {
                    if (day == 1)
                    {
                        date.setMonth(2);
                        date.setDay(28);
                    }
                    else
                    {
                        date.setDay(--day);
                    }
                }
            }
            else
            {
                date.setDay(day - 1);
            }

            cout << "The new date is: " << date.getMonthName() << " " << date.getDay() << ", " << date.getYear() << endl;

            break;
        } // End of case 5
        case 6: // User chooses to compare two dates
        {
            // Create Date objects: date1, date2
            Date date1, date2;

            // Prompt user to enter the first date
            int month1, day1, year1;
            cout << "Enter the first date in the format MM DD YYYY: ";
            cin >> month1 >> day1 >> year1;
            date1.setMonth(month1);
            date1.setDay(day1);
            date1.setYear(year1);

            // Prompt user to enter the second date
            int month2, day2, year2;
            cout << "Enter the second date in the format MM DD YYYY: ";
            cin >> month2 >> day2 >> year2;
            date2.setMonth(month2);
            date2.setDay(day2);
            date2.setYear(year2);

            // Compare the two dates
            if (date1 == date2)
                cout << "The two dates are the same." << endl;
            else
                cout << "The two dates are different." << endl;

            break;
        } // End of case 6
        case 7: // User chooses to calculate the date in the future
        {
            // Create Date object: date
            Date date;

            // Prompt user to enter a date
            cout << "The date you will enter will be advanced by a number of days." << endl;
            int month, day, year;
            cout << "Enter a date in the format MM DD YYYY: ";
            cin >> month >> day >> year;
            date.setMonth(month);
            date.setDay(day);
            date.setYear(year);

            // Prompt user to enter number of days to advance
            int addDays;
            cout << "Enter the number of days to advance by: ";
            cin >> addDays;

            // Advance the date by the specified number of days
            date = date + addDays;

            cout << "The new date is: " << date.getMonthName() << " " << date.getDay() << ", " << date.getYear() << endl;

            break;
        } // End of case 7
        case 8: // User chooses to calculate the date in the past
        {
            // Create Date object: date
            Date date;

            // Prompt user to enter a date
            cout << "The date you will enter will be receded by a number of days." << endl;
            int month, day, year;
            cout << "Enter a date in the format MM DD YYYY: ";
            cin >> month >> day >> year;
            date.setMonth(month);
            date.setDay(day);
            date.setYear(year);

            // Prompt user to enter a number of days to recede
            int subtractDays;
            cout << "Enter the number of days to subtract by: ";
            cin >> subtractDays;

            // Subtract the inputted number of days by using overloaded - operator
            date = date - subtractDays;

            cout << "The new date is: " << date.getMonthName() << " " << date.getDay() << ", " << date.getYear() << endl;

            break;
        } // End of case 8
        case 9: // User chooses to exit program
        {
            cout << "-------------------------------------------" << endl << endl;
            cout << "Thank you for using our software!" << endl;
            break;
        }
        default: // User selects a choice besides 1-9
        {
            cout << "Invalid choice. Please try again." << endl << endl;
        }
    } // End of switch
    
    return 0;
}