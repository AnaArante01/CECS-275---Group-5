#ifndef CLASSES_H
#define CLASSES_H

#include <string>

using namespace std;

class Date {
private:
    int month{0}, day{0}, year{0};   // Default constructor sets all to zero

    static bool isLeap(int y);
    static int daysInMonth(int m, int y);
    static bool isValid(int m, int d, int y);

public:
    // Constructors
    Date() = default;
    Date(int m, int d, int y);   // Invalid dates become 0/0/0

    // Setters
    void setMonth(int m);  // Invalid change resets date to 0/0/0
    void setDay(int d);
    void setYear(int y);

    // Getters
    int  getMonth() const { return month; }
    int  getDay()   const { return day; }
    int  getYear()  const { return year; }

    // Formatting functions
    string monthName() const;
    string fmtMDY() const;
    string fmtLongMDY() const;
    string fmtDMYLong() const;

    // Required Operations
    bool isLeapYear() const;
    int daysBetween(const Date& other) const;
    void increment();
    void decrement();
    int compare(const Date& other) const;

private:
    long long toSerial() const;
    static Date fromSerial(long long s);
};

// Menu function declaration
void displayMenu();

#endif
