/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "UnitTestBookingCategory.h"

template <> void BookingCategory::General::UnitTestBookingCategoryType()
{
    const BookingCategory &i = General::Type(); // Creating an object of General class
    assert(true == (&i == &General::Type())); // Verified if the previous object created is same as another object of General class
    assert("General" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void BookingCategory::Ladies::UnitTestBookingCategoryType()
{
    const BookingCategory &i = Ladies::Type(); // Creating an object of Ladies class
    assert(true == (&i == &Ladies::Type())); // Verified if the previous object created is same as another object of Ladies class
    assert("Ladies" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void BookingCategory::SeniorCitizen::UnitTestBookingCategoryType()
{
    const BookingCategory &i = SeniorCitizen::Type(); // Creating an object of SeniorCitizen class
    assert(true == (&i == &SeniorCitizen::Type())); // Verified if the previous object created is same as another object of SeniorCitizen class
    assert("SeniorCitizen" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void BookingCategory::Tatkal::UnitTestBookingCategoryType()
{
    const BookingCategory &i = Tatkal::Type(); // Creating an object of Tatkal class
    assert(true == (&i == &Tatkal::Type())); // Verified if the previous object created is same as another object of Tatkal class
    assert("Tatkal" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void BookingCategory::PremiumTatkal::UnitTestBookingCategoryType()
{
    const BookingCategory &i = PremiumTatkal::Type(); // Creating an object of PremiumTatkal class
    assert(true == (&i == &PremiumTatkal::Type())); // Verified if the previous object created is same as another object of PremiumTatkal class
    assert("PremiumTatkal" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void Divyaang::Blind::UnitTestDivyaangCategoryType()
{
    const BookingCategory &i = Blind::Type(); // Creating an object of Blind class
    assert(true == (&i == &Blind::Type())); // Verified if the previous object created is same as another object of Blind class
    assert("Blind" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void Divyaang::OrthHandicapped::UnitTestDivyaangCategoryType()
{
    const BookingCategory &i = OrthHandicapped::Type(); // Creating an object of OrthHandicapped class
    assert(true == (&i == &OrthHandicapped::Type())); // Verified if the previous object created is same as another object of OrthHandicapped class
    assert("OrthHandicapped" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void Divyaang::Cancer::UnitTestDivyaangCategoryType()
{
    const BookingCategory &i = Cancer::Type(); // Creating an object of Cancer class
    assert(true == (&i == &Cancer::Type())); // Verified if the previous object created is same as another object of Cancer class
    assert("Cancer" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void Divyaang::TB::UnitTestDivyaangCategoryType()
{
    const BookingCategory &i = TB::Type(); // Creating an object of TB class
    assert(true == (&i == &TB::Type())); // Verified if the previous object created is same as another object of TB class
    assert("TB" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

template <> void Divyaang::None::UnitTestDivyaangCategoryType()
{
    const BookingCategory &i = None::Type(); // Creating an object of None class
    assert(true == (&i == &None::Type())); // Verified if the previous object created is same as another object of None class
    assert("None" == i.GetName()); // Verified if GetName() function gives correct output
    return; // return statement
}

int main()
{
    BookingCategory::General::UnitTestBookingCategoryType(); // for unit testing General
    BookingCategory::Ladies::UnitTestBookingCategoryType(); // for unit testing Ladies
    BookingCategory::SeniorCitizen::UnitTestBookingCategoryType(); // for unit testing SeniorCitizen
    BookingCategory::Tatkal::UnitTestBookingCategoryType(); // for unit testing Tatkal
    BookingCategory::PremiumTatkal::UnitTestBookingCategoryType(); // for unit testing PremiumTatkal
    Divyaang::Blind::UnitTestDivyaangCategoryType(); // for unit testing Blind
    Divyaang::OrthHandicapped::UnitTestDivyaangCategoryType(); // for unit testing OrthHandicapped
    Divyaang::Cancer::UnitTestDivyaangCategoryType(); // for unit testing Cancer
    Divyaang::TB::UnitTestDivyaangCategoryType(); // for unit testing TB
    Divyaang::None::UnitTestDivyaangCategoryType(); // for unit testing None

    return 0; // return statement
}
