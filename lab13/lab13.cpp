#include <iostream>
#include <iomanip>
#include "classes.h"

using namespace std;

void displayMenu() {
    cout << "Choose an option:\n"
         << "1) Check if a year is a leap year\n"
         << "2) Number of days between two dates\n"
         << "3) Increase a date by one day\n"
         << "4) Decrease a date by one day\n"
         << "5) Compare two dates (1 if first>second, 0 equal, -1 less)\n";
}

static Date readDate(const char* prompt) {
    int m,d,y;
    cout << prompt << " (MM DD YYYY): ";
    cin >> m >> d >> y;
    return Date(m,d,y); // will throw if invalid
}

int main() {
        // Read one date and display in three formats
        Date today = readDate("Enter a date");
        cout << "Format 1: " << today.fmtMDY()     << endl;
        cout << "Format 2: " << today.fmtLongMDY() << endl;
        cout << "Format 3: " << today.fmtDMYLong() << endl;

        // Read second date and display in three formats
        Date future = readDate("Enter another date");
        cout << "Format 1: " << future.fmtMDY()     << endl;
        cout << "Format 2: " << future.fmtLongMDY() << endl;
        cout << "Format 3: " << future.fmtDMYLong() << endl;

        cout << "----------------------------------------\n";
        displayMenu();
        cout << "Enter your choice: ";
        int choice; cin >> choice; cout << endl;

        switch (choice) {
            case 1: {
                int y; cout << "Enter a year: "; cin >> y;
                Date tmp(1,1,y); // validates year
                cout << y << (tmp.isLeapYear()? " is" : " is not") << " a leap year.\n";
                break;
            }
            case 2: {
                Date a = readDate("First date");
                Date b = readDate("Second date");
                cout << "Days between " << a.fmtLongMDY() << " and "
                     << b.fmtLongMDY() << " = " << a.daysBetween(b) << " days.\n";
                break;
            }
            case 3: {
                Date a = readDate("Enter a date to increment");
                a.increment();
                cout << "Next day: " << a.fmtLongMDY() << endl;
                break;
            }
            case 4: {
                Date a = readDate("Enter a date to decrement");
                a.decrement();
                cout << "Previous day: " << a.fmtLongMDY() << endl;
                break;
            }
            case 5: {
                Date a = readDate("First date");
                Date b = readDate("Second date");
                cout << "compare(a,b) = " << a.compare(b) << endl;
                break;
            }
            default:
                cout << "Invalid choice.\n";
        }

        return 0;

}
    
