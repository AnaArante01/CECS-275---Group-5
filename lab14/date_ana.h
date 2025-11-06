/*
* This C++ program creates a Data class.
* 
* CECS 275 - Fall 2025
* @authors Ana Jolynn Arante, Suphia Sidiqi
* @version 1.0.0
*/

#include <array>
#include <iomanip>
#include <string>

using namespace std;

#ifndef DATE_ANA_H
#define DATE_ANA_H

class Date {
    private:
        string mName;
        int month, day, year;
    public:

      // Setters
      void setMonth(int m);
      void setDay(int d);
      void setYear(int y);

      // Getters
      int getMonth() const;
      int getDay() const;
      int getYear() const;
      string getMonthName() const;

      /*
         Default constructor that initializes month, day, and year to 0.
      */
      Date();

      /*
         Overloaded constructor that allows initialization of month, day, and year.
      */
      Date(const int& m, const int& d, const int& y);

      /*
         Copy constructor that creates a new Date object as a copy of an existing Date object.
      */
      //Date(const Date &other)
      //    {month = other.month; day = other.day; year = other.year;}

      /*
         Overloaded operator= that allows assignment of one Date object to another.
      */
      //Date& operator=(const Date &other);

      const Date operator+ (int i) const;
      const Date operator+ (const Date& otherDate) const;
      const Date operator- (int i) const;
      const Date operator- (const Date& otherDate) const;
      
      bool operator==(const Date& otherDate) const;
      bool operator!=(const Date& otherDate) const;

      // Private Data Fields
      // Non-member function for operator overloading
      friend ostream& operator<< (ostream& out, const Date& date);
      friend istream& operator>> (istream& in, Date& date);
};










#endif // DATE_ANA_H