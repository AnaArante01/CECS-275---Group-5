




// function for Date();
void setMonth(int m);
void setDay(int d);
void setYear(int y);
     
   void Date::increment(){
    day++;
    if ( day > daysInMonth(month, year)){
        day = 1;
        month++;
    }
    if(month > 12){
        month = 1;
        year++
    }
   }

   void Date::decreaseDate(){
    day--;
        if(day<1){
            month--;
            if(month < 1){
                month--;
                year--;
            }
            day = daysInMonth(month, year);
        }
   }

   int Date::daysBetween(const Date& otherDate) const {
        long days1 = year * 365 + day;
        for (int i = 1; i < month; ++i){
            days1 += daysInMonth(i,year);
        }
        for (int i = 1; i < year; ++i){
            if (isLeap(i)){
                days1++;
            }
        }

        long days2 = otherDate.year * 365 + otherDate.day'
        for ( int i = 1; i < otherDate.month; ++i){
        days2 += daysInMonth(i,otherDate.year);
        }
        return static_cast<int>(days1-days2);
   }




        void decrement();