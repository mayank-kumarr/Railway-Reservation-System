/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "UnitTestGender.h"

// Function body of UnitTestGender() function for unit testing 'Gender' class

void Gender::UnitTestGender()
{
    const Gender &g = Gender::Male::Type(); // Creating an object of Gender class
    assert(&g == &Gender::Male::Type()); // Verified for singleton class
    assert(isMale(g) == true); // isMale() should be true for male type
    assert(g.GetTitle() == "Mr."); // GetTitle() should give Mr. for male type
    assert(g.GetName() == "Male"); // GetName() should give Male for male type
    
    const Gender &g2 = Gender::Female::Type(); // Creating an object of Gender class
    assert(&g2 == &Gender::Female::Type()); // Verified for singleton class
    assert(isMale(g2) == false); // isMale() should be false for female type
    assert(g2.GetTitle() == "Ms."); // GetTitle() should give Ms. for female type
    assert(g2.GetName() == "Female"); // GetName() should give Female for female type

    return; // return statement
}

int main()
{
    Gender::UnitTestGender(); // for unit testing Gender class
    return 0;
}