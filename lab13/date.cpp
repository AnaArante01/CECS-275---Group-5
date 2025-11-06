
#include "classes.h"
#include <array>
#include <string>

// ------- small helpers (no <sstream>) -------
static std::string pad2(int x) {
    // ensure two digits for month/day like 08/25
    if (x < 10) return "0" + std::to_string(x);
    return std::to_string(x);
}

// ================== Date impl ==================

bool Date::isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) {
    static const int base[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2) return base[2] + (isLeap(y) ? 1 : 0);
    if (m >= 1 && m <= 12) return base[m];
    return 0;
}

bool Date::isValid(int m, int d, int y) {
    if (y < 0) return false;
    if (m < 1 || m > 12) return false;
    int dim = daysInMonth(m, y);
    if (d < 1 || d > dim) return false;
    return true;
}

// ---- ctors ----
Date::Date(int m, int d, int y) {
    if (isValid(m,d,y)) { month = m; day = d; year = y; }
    else { month = day = year = 0; }  // per prompt: do not accept invalid date
}

// ---- setters (invalid => reset to 0/0/0) ----
void Date::setMonth(int m) {
    if (isValid(m, day==0?1:day, year)) { month = m; }
    else { month = day = year = 0; }
}
void Date::setDay(int d) {
    if (isValid(month==0?1:month, d, year)) { day = d; }
    else { month = day = year = 0; }
}
void Date::setYear(int y) {
    if (isValid(month==0?1:month, day==0?1:day, y)) { year = y; }
    else { month = day = year = 0; }
}

// Formatters
std::string Date::monthName() const {
    static const std::array<const char*,12> names = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };
    return (month>=1 && month<=12)? names[month-1] : "";
}

std::string Date::fmtMDY() const {
    return pad2(month) + "/" + pad2(day) + "/" + std::to_string(year);
}

std::string Date::fmtLongMDY() const {
    return monthName() + " " + pad2(day) + ", " + std::to_string(year);
}

std::string Date::fmtDMYLong() const {
    return pad2(day) + " " + monthName() + " " + std::to_string(year);
}

// ---- calendar utilities ----
bool Date::isLeapYear() const { return isLeap(year); }

// Serial day number (Rata-Die–like, 1-based) for proleptic Gregorian
long long Date::toSerial() const {
    long long y = year;
    long long days = 365*y + y/4 - y/100 + y/400;
    static const int cum[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
    days += cum[month];
    if (month > 2 && isLeap((int)y)) days += 1;
    days += day;
    return days;
}

Date Date::fromSerial(long long s) {
    // Find year by binary search
    long long lo = 0, hi = 100000; // enough range
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        long long d = 365*mid + mid/4 - mid/100 + mid/400;
        if (d < s) lo = mid + 1; else hi = mid;
    }
    long long y = lo - 1;
    long long doy1 = 365*y + y/4 - y/100 + y/400;
    long long doy = s - doy1; // 1..366
    bool leap = isLeap((int)y);

    static const int ml[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int m = 1;
    while (true) {
        int dim = ml[m] + ((m==2 && leap)?1:0);
        if ((long long)dim >= doy) break;
        doy -= dim; ++m;
    }
    int d = (int)doy;
    return Date(m,d,(int)y);
}

int Date::daysBetween(const Date& other) const {
    long long a = toSerial();
    long long b = other.toSerial();
    return (a > b) ? int(a - b) : int(b - a);
}

void Date::increment() { *this = fromSerial(toSerial() + 1); }
void Date::decrement() { *this = fromSerial(toSerial() - 1); }

int Date::compare(const Date& other) const {
    if (year != other.year)   return (year  > other.year)  ? 1 : -1;
    if (month != other.month) return (month > other.month) ? 1 : -1;
    if (day != other.day)     return (day   > other.day)   ? 1 : -1;
    return 0;
}
