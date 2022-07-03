/*
    Mayank Kumar
    19CS30029
*/

#include "Name.h"
#include "Date.h"
#include "Gender.h"
#include "Station.h"
#include "Booking.h"
#include "Railways.h"
#include "Passenger.h"
#include "BookingClass.h"
#include "BookingCategory.h"
#include "Exception.h"

using namespace std;

void TestApplication()
{
    // positive test cases

    const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
    *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    cout << b1 << endl;

    const Booking b2 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::SeniorCitizen::Type(), 
    *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/1957", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::Blind::Type(), "311"));
    cout << b2 << endl;

    const Booking b3 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::Sleeper::Type(), BookingCategory::Ladies::Type(), 
    *Passenger::CreatePassenger("XX", "", "Kumari", "16/07/2001", Gender::Female::Type(), "906125658148", "9631920388", Divyaang::TB::Type(), "5121"));
    cout << b3 << endl;

    const Booking b4 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
    *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    cout << b4 << endl;

    const Booking b5 = Booking::ReserveBooking("Mumbai", "Kolkata", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
    *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    cout << b5 << endl;

    const Booking b6 = Booking::ReserveBooking("Kolkata", "Mumbai", "22/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
    *Passenger::CreatePassenger("ABC", "", "Kumar", "16/07/2000", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    cout << b6 << endl;

    Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
    *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));

    cout << endl;

    // negative test case for wrong station name

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Kokata", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for same from and to stations

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Kolkata", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for same booking and reservation date

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "10/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }
    
    cout << endl;

    // negative test case for invalid date of birth of passenger

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2022", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for invalid aadhaar

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "90612565814a", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }
    
    cout << endl;

    // negative test case for invalid mobile

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "963192038b", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for Male passenger not eligible to book in Ladies category

    try
    {
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), BookingCategory::Ladies::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for Male passenger with age <= 60 not eligible to book in SeniorCitizen category

    try
    {
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), BookingCategory::SeniorCitizen::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/1962", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;
    
    // negative test case for Female passenger with age <= 58 not eligible to book in SeniorCitizen category

    try
    {
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), BookingCategory::SeniorCitizen::Type(), 
       *Passenger::CreatePassenger("XX", "", "Kumari", "16/07/1964", Gender::Female::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for non-disable passenger not eligible to book in any of Divyaang categories

    try
    {
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), Divyaang::Blind::Type(), 
       *Passenger::CreatePassenger("XX", "", "Kumari", "16/07/1965", Gender::Female::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for Divyaang passenger not eligible as they need to select correct Divyaang category

    try
    {
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), Divyaang::Blind::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Female::Type(), "906125658148", "9631920388", Divyaang::TB::Type(), "655"));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for invalid booking date, more than 1 day when booking category is tatkal

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), BookingCategory::Tatkal::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for invalid travel date, more than one year late travelling date

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2023", BookingClass::ACFirstClass::Type(), BookingCategory::Tatkal::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for ineligible booking category

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), BookingCategory::Ladies::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for disabilityID not given even when disablity is not None

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), BookingCategory::Ladies::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::Blind::Type()));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;

    // negative test case for disabilityID given even when disablity is None

    try
    {
       const Booking b7 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), BookingCategory::Ladies::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type(), "652"));
    }
    catch(const BadBooking& e)
    {
       cerr << e.what() << endl;
    }
    catch(const BadPassenger& e)
    {
       cerr << e.what() << endl;
    }

    cout << endl;
}

int main()
{
    TestApplication();
    return 0;
}
