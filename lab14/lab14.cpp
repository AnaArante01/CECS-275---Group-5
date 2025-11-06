

// case 3 number of days in between the dates
// add a overloaded minus operator first to return an int 

int Date operator-(const Date& otherDate) const;

case 3:
{
    // create date objects:
    Date date1, date2;
    // prompt the user to put in new values for date
    int month1, day1, year1;
    cout << " Enter the first date in mm dd yy:" << endl;     
    cin >> month1 >> day1 >> year1;
    date1.setMonth(month1);
    date1.setDay(Day1);
    date1.setYeara(Year1);

    // Prompt user to enter the second date 
    int month2, day2, year2;
    
    cout << "Enter the second date in mm dd yy:"
    cin >> month2 >> day2 >> year2;
    date2.setMonth(month2);
    date2.setDay(Day2);
    date2.setYear(Year2);

    // calculate and display the number in between the days 
    int daysBetween = date2 - date1;
    if (daysBetween < 0){
        daysBetween -= daysBetween;
    }
    cout << " \n Number of days between "
    << date1.getMonthName() << " " << date1.getDay()  << " " << date1.getYear() << " and "
    << date2.getMonthName() << " " << date2.getDay() << " " << dat2.getYear() << " are: " <<
    daysBetween << " days. " << endl;

    break;
}
      
