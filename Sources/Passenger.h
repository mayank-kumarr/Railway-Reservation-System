/*
    Mayank Kumar
    19CS30029
    Passenger.h
*/

#ifndef __PASSENGER_H // Control inclusion of header files
#define __PASSENGER_H

// Project Headers
#include "Name.h"
#include "Date.h"
#include "Gender.h"

// C++ Headers
#include <string>
#include <iostream>
using namespace std;

// Forward Declaration
class Divyaang;

// Declaration for Passenger class
class Passenger
{
protected:
    const Name name_; // stores name
    const string aadhaar_; // stores aadhaar
    const Date dob_; // stores date of birth
    const Gender &gender_; // stores gender
    const string &mobile_; // stores mobile no.
    const Divyaang& disability_; // stores disability
    const string& disabilityID_; // stores disabilityID

public:
    Passenger(const Name &, const Date &, const Gender &, const string &, 
                const string &, const Divyaang &, const string & = ""); // constructor
    ~Passenger(); // destructor
    const Date &GetDOB() const; // returns date of birth
    const Gender &GetGender() const; // returns gender
    const Divyaang &GetDisability() const; // returns disability
    // function to create and return Passenger object when string inputs are given
    static Passenger *CreatePassenger(const string&, const string&, const string&, const string&, 
            const Gender&, const string&, const string&, const Divyaang&, const string& = "");
    friend ostream &operator<<(ostream &, const Passenger &); // Output stream operator
    static void UnitTestPassenger(); // for unit testing Passenger class
};


#endif // __PASSENGER_H