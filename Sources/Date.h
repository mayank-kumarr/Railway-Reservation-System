/*
    Mayank Kumar
    19CS30029
    Date.h
*/

#ifndef __DATE_H // Control inclusion of header files
#define __DATE_H

// C++ Headers
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Enum declarations
enum Day {Sun, Mon, Tue, Wed, Thr, Fri, Sat};
enum Month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

// Declaration for 'Date' class
class Date
{
private:
    static const vector<string> sDayNames; // List of day names
    static const vector<string> sMonthNames; // List of month names

    const int date_; // Variable date
    const Month month_; // Variable month
    const int year_; // Variable year
    Day day_;

    Day GetDay() const; // Function that gives day of week from date

    Date& operator=(const Date&); // Blocked copy assignment operator

public:
    Date(int d = 1, int m = 1, int y = 2021); // Constructor
    Date(const Date&); // Copy constructor
    ~Date(); // Destructor

    inline bool operator==(const Date& d) // overloaded operator to test equality of two dates
    {
        return (date_==d.date_ && month_==d.month_ && year_==d.year_);
    }
    inline bool operator<=(const Date& d) // overloaded operator to test "less-than-equals" for two dates
    {
        if(year_<=d.year_)
            return true;
        if(month_<=d.month_)
            return true;
        if(date_<=d.date_)
            return true;
        return false;
    }
    static int subtract(const Date &, const Date &); // function two find no. of days between two dates
    static Date* CreateDate(const string&); // function to return Date object when a string is given as input
    static Date Today(); // function to return today's date
    static int Age(const Date &); // function to calculate age
    friend ostream &operator<<(ostream&, const Date&); // Output stream operator
    static void UnitTestDate(); // Static function for unit testing
};

#endif // __DATE_H