/*
    Mayank Kumar
    19CS30029
*/

#ifndef __NAME_H // Control inclusion of header files
#define __NAME_H

// C++ Headers
#include <string>
#include <iostream>
using namespace std;

// Declaration for 'Name' class
class Name
{
private:
    const string firstName_; // stores firstname
    const string middleName_; // stores middle name
    const string lastName_; // stores last name

public:
    Name(const string &, const string &, const string &); // constructor
    Name(const Name&); // copy constructor
    ~Name(); // destructor
    static Name* CreateName(const string &, const string &, const string &); // returns name object for string
    friend ostream &operator<<(ostream &, const Name &); // Output stream operator
    static void UnitTestName(); // for unt testing this class
};

#endif // __NAME_H