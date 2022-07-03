/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "BookingClass.h"

// initializing all the static attributes for different booking classes

template <> const string BookingClass::ACFirstClass::sName = "ACFirstClass";
template <> const bool BookingClass::ACFirstClass::sIsSitting = false;
template <> const bool BookingClass::ACFirstClass::sIsAC = true;
template <> const int BookingClass::ACFirstClass::sTiers = 2;

template <> const double BookingClass::ACFirstClass::sLoadFactor = 6.50;
template <> const bool BookingClass::ACFirstClass::sIsLuxury = true;
template <> const double BookingClass::ACFirstClass::sReservationCharge = 60.00;
template <> const double BookingClass::ACFirstClass::sTatkalFactor = 0.30;
template <> const double BookingClass::ACFirstClass::sTatkalMinCharge = 400.00;
template <> const double BookingClass::ACFirstClass::sTatkalMaxCharge = 500.00;
template <> const int BookingClass::ACFirstClass::sMinTatkalDistance = 500;


template <> const string BookingClass::ExecutiveChairCar::sName = "ExecutiveChairCar";
template <> const bool BookingClass::ExecutiveChairCar::sIsSitting = false;
template <> const bool BookingClass::ExecutiveChairCar::sIsAC = true;
template <> const int BookingClass::ExecutiveChairCar::sTiers = 0;

template <> const double BookingClass::ExecutiveChairCar::sLoadFactor = 5.00;
template <> const bool BookingClass::ExecutiveChairCar::sIsLuxury = true;
template <> const double BookingClass::ExecutiveChairCar::sReservationCharge = 60.00;
template <> const double BookingClass::ExecutiveChairCar::sTatkalFactor = 0.30;
template <> const double BookingClass::ExecutiveChairCar::sTatkalMinCharge = 400.00;
template <> const double BookingClass::ExecutiveChairCar::sTatkalMaxCharge = 500.00;
template <> const int BookingClass::ExecutiveChairCar::sMinTatkalDistance = 250;


template <> const string BookingClass::AC2Tier::sName = "AC2Tier";
template <> const bool BookingClass::AC2Tier::sIsSitting = false;
template <> const bool BookingClass::AC2Tier::sIsAC = true;
template <> const int BookingClass::AC2Tier::sTiers = 2;

template <> const double BookingClass::AC2Tier::sLoadFactor = 4.00;
template <> const bool BookingClass::AC2Tier::sIsLuxury = false;
template <> const double BookingClass::AC2Tier::sReservationCharge = 50.00;
template <> const double BookingClass::AC2Tier::sTatkalFactor = 0.30;
template <> const double BookingClass::AC2Tier::sTatkalMinCharge = 400.00;
template <> const double BookingClass::AC2Tier::sTatkalMaxCharge = 500.00;
template <> const int BookingClass::AC2Tier::sMinTatkalDistance = 500;


template <> const string BookingClass::FirstClass::sName = "FirstClass";
template <> const bool BookingClass::FirstClass::sIsSitting = false;
template <> const bool BookingClass::FirstClass::sIsAC = false;
template <> const int BookingClass::FirstClass::sTiers = 2;

template <> const double BookingClass::FirstClass::sLoadFactor = 3.00;
template <> const bool BookingClass::FirstClass::sIsLuxury = true;
template <> const double BookingClass::FirstClass::sReservationCharge = 50.00;
template <> const double BookingClass::FirstClass::sTatkalFactor = 0.30;
template <> const double BookingClass::FirstClass::sTatkalMinCharge = 400.00;
template <> const double BookingClass::FirstClass::sTatkalMaxCharge = 500.00;
template <> const int BookingClass::FirstClass::sMinTatkalDistance = 500;


template <> const string BookingClass::AC3Tier::sName = "AC3Tier";
template <> const bool BookingClass::AC3Tier::sIsSitting = false;
template <> const bool BookingClass::AC3Tier::sIsAC = true;
template <> const int BookingClass::AC3Tier::sTiers = 3;

template <> const double BookingClass::AC3Tier::sLoadFactor = 2.50;
template <> const bool BookingClass::AC3Tier::sIsLuxury = false;
template <> const double BookingClass::AC3Tier::sReservationCharge = 40.00;
template <> const double BookingClass::AC3Tier::sTatkalFactor = 0.30;
template <> const double BookingClass::AC3Tier::sTatkalMinCharge = 300.00;
template <> const double BookingClass::AC3Tier::sTatkalMaxCharge = 400.00;
template <> const int BookingClass::AC3Tier::sMinTatkalDistance = 500;


template <> const string BookingClass::ACChairCar::sName = "ACChairCar";
template <> const bool BookingClass::ACChairCar::sIsSitting = true;
template <> const bool BookingClass::ACChairCar::sIsAC = true;
template <> const int BookingClass::ACChairCar::sTiers = 0;

template <> const double BookingClass::ACChairCar::sLoadFactor = 2.00;
template <> const bool BookingClass::ACChairCar::sIsLuxury = false;
template <> const double BookingClass::ACChairCar::sReservationCharge = 40.00;
template <> const double BookingClass::ACChairCar::sTatkalFactor = 0.30;
template <> const double BookingClass::ACChairCar::sTatkalMinCharge = 125.00;
template <> const double BookingClass::ACChairCar::sTatkalMaxCharge = 225.00;
template <> const int BookingClass::ACChairCar::sMinTatkalDistance = 250;


template <> const string BookingClass::Sleeper::sName = "Sleeper";
template <> const bool BookingClass::Sleeper::sIsSitting = false;
template <> const bool BookingClass::Sleeper::sIsAC = false;
template <> const int BookingClass::Sleeper::sTiers = 3;

template <> const double BookingClass::Sleeper::sLoadFactor = 1.00;
template <> const bool BookingClass::Sleeper::sIsLuxury = false;
template <> const double BookingClass::Sleeper::sReservationCharge = 20.00;
template <> const double BookingClass::Sleeper::sTatkalFactor = 0.30;
template <> const double BookingClass::Sleeper::sTatkalMinCharge = 100.00;
template <> const double BookingClass::Sleeper::sTatkalMaxCharge = 200.00;
template <> const int BookingClass::Sleeper::sMinTatkalDistance = 500;


template <> const string BookingClass::SecondSitting::sName = "SecondSitting";
template <> const bool BookingClass::SecondSitting::sIsSitting = true;
template <> const bool BookingClass::SecondSitting::sIsAC = false;
template <> const int BookingClass::SecondSitting::sTiers = 0;

template <> const double BookingClass::SecondSitting::sLoadFactor = 0.60;
template <> const bool BookingClass::SecondSitting::sIsLuxury = false;
template <> const double BookingClass::SecondSitting::sReservationCharge = 15.00;
template <> const double BookingClass::SecondSitting::sTatkalFactor = 0.10;
template <> const double BookingClass::SecondSitting::sTatkalMinCharge = 10.00;
template <> const double BookingClass::SecondSitting::sTatkalMaxCharge = 15.00;
template <> const int BookingClass::SecondSitting::sMinTatkalDistance = 100;

// output stream operator

ostream& operator<<(ostream& os, const BookingClass& x)
{
    string sitOrSleep, ac, lux;
    if(x.IsSitting())
        sitOrSleep = "Sitting";
    else
        sitOrSleep = "Sleeping";
    if(x.IsAC())
        ac = "AC";
    else
        ac = "Non-AC";
    if(x.IsLuxury())
        lux = "Yes";
    else
        lux = "No";
    os << "Travel Class = " << x.GetName() << "\n";
    os << " : Mode: " << sitOrSleep << "\n";
    os << " : Comfort: " << ac << "\n";
    os << " : Bunks: " << x.GetNumberOfTiers() << "\n";
    os << " : Luxury: " << lux;
    return os;
}