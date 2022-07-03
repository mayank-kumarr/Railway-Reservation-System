/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "UnitTestDate.h"

// Function body of UnitTestDate() function for unit testing 'Date' class

void Date::UnitTestDate()
{
    Date d(7, 3, 2021); // Constructor called, with 7, 3 and 2021 as arguments
    Date d1(d); // Copy constructor called
    Date d2 = d1; // Copy constructor called

    Date d3; // Constructor called, with 1, 1 and 2021 as arguments
    Date d4(5); // Constructor called with 5, 1 and 2021 as arguments
    Date d5(5, 6); // Constructor called with 5, 6 and 2021 as arguments

    Date d6(7, 3, 2020); // Constructor called, with 7, 3 and 2020 as arguments
    Date d7(7, 4, 2021); // Constructor called, with 7, 4 and 2021 as arguments
    Date d8(8, 3, 2021); // Constructor called, with 8, 3 and 2021 as arguments
    Date d9(29, 2, 2020); // Constructor called, with 8, 4 and 2020 as arguments
    Date d10(16, 7, 2001); // Constructor called, with 16, 7 and 2001 as arguments
    
    // Testing the members stored in Date objects

    assert(7==d.date_ && Mar==d.month_ && 2021==d.year_); // Verified if Date object 'd' has stored correct members
    assert(7==d1.date_ && Mar==d1.month_ && 2021==d1.year_); // Verified if Date object 'd1' has stored correct members
    assert(7==d2.date_ && Mar==d2.month_ && 2021==d2.year_); // Verified if Date object 'd2' has stored correct members
    assert(1==d3.date_ && Jan==d3.month_ && 2021==d3.year_); // Verified if Date object 'd3' has stored correct members
    assert(5==d4.date_ && Jan==d4.month_ && 2021==d4.year_); // Verified if Date object 'd4' has stored correct members
    assert(5==d5.date_ && Jun==d5.month_ && 2021==d5.year_); // Verified if Date object 'd5' has stored correct members

    // Testing the day of week given by GetDay() function for Date objects

    assert(Sun == d.GetDay()); // Verified if Date object 'd' gives correct day of week when GetDay() function is called
    assert(Sun == d1.GetDay()); // Verified if Date object 'd1' gives correct day of week when GetDay() function is called
    assert(Sun == d2.GetDay()); // Verified if Date object 'd2' gives correct day of week when GetDay() function is called
    assert(Fri == d3.GetDay()); // Verified if Date object 'd3' gives correct day of week when GetDay() function is called
    assert(Tue == d4.GetDay()); // Verified if Date object 'd4' gives correct day of week when GetDay() function is called
    assert(Sat == d5.GetDay()); // Verified if Date object 'd5' gives correct day of week when GetDay() function is called
    assert(Sat == d9.GetDay()); // Verified if Date object 'd9' gives correct day of week when GetDay() function is called (for 29th Feb)

    // Testing the overloaded relational operator ==

    assert(true == (d==d1)); // Verified if Date objects d and d1 are equal
    assert(true == (d1==d2)); // Verified if Date objects d1 and d2 are equal

    assert(false == (d==d6));  // Verified if Date objects d and d6 are unequal (Only year_ is different in objects d and d6)
    assert(false == (d==d7)); // Verified if Date objects d and d7 are unequal (Only month_ is different in objects d and d7)
    assert(false == (d==d8)); // Verified if Date objects d and d8 are unequal (Only date_ is different in objects d and d8)

    assert(false == (d6==d7)); // Verified if Date objects d6 and d7 are unequal (Both year_ and month_ are different in objects d6 and d7)
    assert(false == (d6==d8)); // Verified if Date objects d6 and d8 are unequal (Both year_ and date_ are different in objects d6 and d8)
    assert(false == (d7==d8)); // Verified if Date objects d7 and d8 are unequal (Both month_ and date_ are different in objects d7 and d8)
    
    assert(false == (d==d9)); // Verified if Date objects d and d9 are unequal (Both year_, month and date_ are different in objects d and d9)

    assert(0 == subtract(d, d1)); // Verified if 0 is the output when two dates are same
    assert(-395 == subtract(d6, d7)); // Verified if -395 is the output for these dates
    assert(396 == subtract(d7, d6)); // Verified if 396 is the output for these dates
    assert(-365 == subtract(d6, d8)); // Verified if -365 is the output for these dates
    assert(366 == subtract(d8, d6)); // Verified if 365 is the output for these dates

    assert(0 == Age(d1)); // Verified if age is 0 for a date in 2021
    assert(1 == Age(d6)); // Verified if age is 1 for a date in 2020
    assert(19 == Age(d10)); // Verified if age is 19 for a date in 2001

    // positive test case

    Date* d11 = NULL;
    try
    {
        d11 = Date::CreateDate("16/07/2001");
        assert(16 == d11->date_);
        assert(Jul == d11->month_);
        assert(2001 == d11->year_);

    }
    catch(BadDate& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    // negative test case, digits not present

    try
    {
        d11 = Date::CreateDate("dd/mm/yyyy");
    }
    catch(BadDate& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(*d11 == Date(16, 07, 2001));

    // negative test case, febreuary 1999 did not have 29 days

    try
    {
        d11 = Date::CreateDate("29/02/1999");
    }
    catch(BadDate& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(*d11 == Date(16, 07, 2001));

    // negative test case, april doesn't have 31 days

    try
    {
        d11 = Date::CreateDate("31/04/2021");
    }
    catch(BadDate& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(*d11 == Date(16, 07, 2001));

    // negative test case, july doesn't have 31 days

    try
    {
        d11 = Date::CreateDate("32/07/2021");
    }
    catch(BadDate& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(*d11 == Date(16, 07, 2001));

    // negative test case, date less than 1899 not allowed

    try
    {
        d11 = Date::CreateDate("09/04/1899");
    }
    catch(BadDate& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(*d11 == Date(16, 07, 2001));

    // negative test case, date above 2099 not allowed

    try
    {
        d11 = Date::CreateDate("09/04/3000");  //year > 2099
    }
    catch(BadDate& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(*d11 == Date(16, 07, 2001));


    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << d; // Writing the Date object 'd' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestDate.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of Date object 'd' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

int main()
{
    Date::UnitTestDate(); // Called UnitTestDate() function for unit testing

    return 0; // return statement
}