




// this file is to use for the function date class and function prototypes 
// this struct class has the three prpoerties of month, day, and year

//you have to use constructors:
// member function that is automatically callled when 
// an object is created
class Date 
{
    int Month;
    int Day;
    int Year;

    public:
    Date();                    // default constructor
    Date(int m, int d, int y); // overloaded constructor
    // getters anbd setters
    // get month
    // get date
    // get year--> check if its a leap year
    // display function
    std :: int getMonth() const;
    std :: int getDay() const;
    std :: int getYear() const;

    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);
     
      void increment();
        void decrement();


};

// add function prototypes here 
