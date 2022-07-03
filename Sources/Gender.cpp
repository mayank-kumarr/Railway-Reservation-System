/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "Gender.h"

template <> const string Gender::Male::sName = "Male"; // name of male gender is Male
template <> const string Gender::Male::sSalutation = "Mr."; // title for male gender is Mr.

template <> const string Gender::Female::sName = "Female"; // name of female gender is Female
template <> const string Gender::Female::sSalutation = "Ms."; // title for female gender is Ms.

// output stream operator
ostream& operator<<(ostream& os, const Gender& gender)
{
    os << "Gender: " << gender.GetName();
    return os;
}