/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "BookingCategory.h"
#include "Booking.h"

// initializing static members
template <> const string& BookingCategory::General::sName = "General";
template <> const string& BookingCategory::Ladies::sName = "Ladies";
template <> const string& BookingCategory::SeniorCitizen::sName = "SeniorCitizen";
template <> const string& BookingCategory::Tatkal::sName = "Tatkal";
template <> const string& BookingCategory::PremiumTatkal::sName = "PremiumTatkal";
template <> const string& Divyaang::Blind::sName = "Blind";
template <> const string& Divyaang::OrthHandicapped::sName = "OrthHandicapped";
template <> const string& Divyaang::Cancer::sName = "Cancer";
template <> const string& Divyaang::TB::sName = "TB";
template <> const string& Divyaang::None::sName = "None";

// constructor
BookingCategory::BookingCategory(const string& name) : name_(name)
{
    #if _DEBUG
        cout << "BookingCategory Created" << endl;
    #endif  // _DEBUG
}

// destructor
BookingCategory::~BookingCategory()
{
    #if _DEBUG
        cout << "BookingCategory Destroyed" << endl;
    #endif  // _DEBUG
}

// returns name of booking category
const string& BookingCategory::GetName() const
{
    return name_;
}

// checking for eligibility in different booking categories
// unittesting for these functions are in UnitTestBooking.cpp since
// it is to be used there directly

template <> bool BookingCategory::General::IsEligible(const Passenger& p) const
{
    return true;
}

template <> bool BookingCategory::Ladies::IsEligible(const Passenger& p) const
{
    int age = Date::Age(p.GetDOB());
    if(Gender::isMale(p.GetGender())==false || age < 12)
        return true;
    else
        return false;
}

template <> bool BookingCategory::SeniorCitizen::IsEligible(const Passenger& p) const
{
    int age = Date::Age(p.GetDOB());
    if (Gender::isMale(p.GetGender())==true && age > 60)
        return true;
    else if (Gender::isMale(p.GetGender())==false && age > 58)
        return true;
    else
        return false;
}

template <> bool BookingCategory::Tatkal::IsEligible(const Passenger& p) const
{
    return true;
}

template <> bool BookingCategory::PremiumTatkal::IsEligible(const Passenger& p) const
{
    return true;
}

// creating and returning Booking object for different booking categories

template <> Booking* BookingCategory::General::CreateBooking(const Station& fromStation, const Station& toStation,
                                                 const Date& dateOfReservation, const Date& dateOfBooking,
                                                 const BookingClass& bookingClass, const Passenger& Passenger,
                                                 const BookingCategory& bookingCategory) const
{
    Booking *booking = new Booking::GeneralBooking(fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory, Passenger);
    return booking;
}

template <> Booking* BookingCategory::Ladies::CreateBooking(const Station& fromStation, const Station& toStation,
                                                 const Date& dateOfReservation, const Date& dateOfBooking,
                                                 const BookingClass& bookingClass, const Passenger& Passenger,
                                                 const BookingCategory& bookingCategory) const
{
    Booking *booking = new Booking::LadiesBooking(fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory, Passenger);
    return booking;
}

template <> Booking* BookingCategory::SeniorCitizen::CreateBooking(const Station& fromStation, const Station& toStation,
                                                 const Date& dateOfReservation, const Date& dateOfBooking,
                                                 const BookingClass& bookingClass, const Passenger& Passenger,
                                                 const BookingCategory& bookingCategory) const
{
    Booking *booking = new Booking::SeniorCitizenBooking(fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory, Passenger);
    return booking;
}

template <> Booking* BookingCategory::Tatkal::CreateBooking(const Station& fromStation, const Station& toStation,
                                                 const Date& dateOfReservation, const Date& dateOfBooking,
                                                 const BookingClass& bookingClass, const Passenger& Passenger,
                                                 const BookingCategory& bookingCategory) const
{
    Booking *booking = new Booking::TatkalBooking(fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory, Passenger);
    return booking;
}

template <> Booking* BookingCategory::PremiumTatkal::CreateBooking(const Station& fromStation, const Station& toStation,
                                                 const Date& dateOfReservation, const Date& dateOfBooking,
                                                 const BookingClass& bookingClass, const Passenger& Passenger,
                                                 const BookingCategory& bookingCategory) const
{
    Booking *booking = new Booking::PremiumTatkalBooking(fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory, Passenger);
    return booking;
}

Booking* Divyaang::CreateBooking(const Station& fromStation, const Station& toStation,
                                                 const Date& dateOfReservation, const Date& dateOfBooking,
                                                 const BookingClass& bookingClass, const Passenger& Passenger,
                                                 const BookingCategory& bookingCategory) const
{
    Booking *booking = new Booking::DivyaangBooking(fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory, Passenger);
    return booking;
}

// checking for eligibility in different divyaang booking categories
// unittesting for these functions are in UnitTestBooking.cpp since
// it is to be used there directly

template <> bool Divyaang::Blind::IsEligible(const Passenger& p) const
{
    if(&p.GetDisability() == &Divyaang::Blind::Type())
        return true;
    else
        return false;
}

template <> bool Divyaang::OrthHandicapped::IsEligible(const Passenger& p) const
{
    if(&p.GetDisability() == &Divyaang::OrthHandicapped::Type())
        return true;
    else
        return false;
}

template <> bool Divyaang::Cancer::IsEligible(const Passenger& p) const
{
    if(&p.GetDisability() == &Divyaang::Cancer::Type())
        return true;
    else
        return false;
}
template <> bool Divyaang::TB::IsEligible(const Passenger& p) const
{
    if(&p.GetDisability() == &Divyaang::TB::Type())
        return true;
    return false;
}

template <> bool Divyaang::None::IsEligible(const Passenger& p) const
{
    if(&p.GetDisability() == &Divyaang::None::Type())
        return true;
    else
        return false;
}
