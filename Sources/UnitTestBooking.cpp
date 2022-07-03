// CS20006 Assignment 5
// @author Mayank Kumar (19CS30029)

// Project Headers
#include "UnitTestBooking.h"

// Function body of UnitTestBooking() function for unit testing 'Booking' class

void Booking::UnitTestBooking()
{
    // positive test case

    const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
    *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));

    // Testing the members stored in Booking objects b1, b1, b3 and b4

    // Verified if Booking object 'b1' has stored correct members
    assert("Kolkata"==b1.fromStation_.GetName() && "Mumbai"==b1.toStation_.GetName() && "ACFirstClass"==b1.bookingClass_.GetName()
           && 1==b1.PNR_ && true==b1.bookingStatus_ && "BOOKING SUCCEEDED!"==b1.bookingMessage_ && Date(20, 4, 2021)==(b1.dateOfBooking_));
    assert(6606==b1.fare_); // Verified fare for ACFirstClass from Kolkata to Mumbai

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << b1; // Writing the Booking object 'b1' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestBooking.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of Booking object 'b1' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    cout << endl;

    // negative test case for wrong station name

    try
    {
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Kokata", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
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
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Kolkata", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
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
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "10/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
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
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
       *Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2022", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type()));
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

    // negative test case for invalid aadhaar

    try
    {
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
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
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), 
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

    // negative test case for invalid booking date, more than 1 day when booking category is tatkal

    try
    {
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2021", BookingClass::ACFirstClass::Type(), BookingCategory::Tatkal::Type(), 
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
       const Booking b1 = Booking::ReserveBooking("Kolkata", "Mumbai", "20/05/2023", BookingClass::ACFirstClass::Type(), BookingCategory::Tatkal::Type(), 
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


    return; // return statement
}

int main()
{
    Booking::UnitTestBooking(); // Called UnitTestBooking() function for unit testing

    return 0; // return statement
}
