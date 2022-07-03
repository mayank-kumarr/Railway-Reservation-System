/*
    Mayank Kumar
    19CS30029
    Booking.h
*/

#ifndef __BOOKING_H // Control inclusion of header files
#define __BOOKING_H

// Project Headers
#include "Date.h"
#include "Railways.h"
#include "Concession.h"
#include "Station.h"
#include "BookingClass.h"
#include "BookingCategory.h"
#include "Passenger.h"

// C++ Headers
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;

// BookingType class
template <typename T>
class BookingType;

// Declaration for 'Booking' class
class Booking
{
private:
    // structs for different bookings
    struct GeneralType {};
    struct LadiesType {};
    struct SeniorCitizenType {};
    struct TatkalType {};
    struct PremiumTatkalType {};
    struct DivyaangType {};

protected:
    const string name_;
    const Station &fromStation_; // Station from which booking is done
    const Station &toStation_; // Station to which booking is done
    const Date dateOfReservation_; // Travel Date
    const Date dateOfBooking_; // Booking Date
    const BookingClass &bookingClass_; // Booking Class of travel
    const BookingCategory &bookingCategory_; // Booking Category of travel

    const int PNR_; // PNR for the booking
    int fare_; // Fare incurred for the booking
    
    const Passenger passenger_; // Passenger details
    
    bool bookingStatus_; // Booking status for the booking
    string bookingMessage_; // Booking message received after booking

    Booking& operator=(const Booking&); // Blocked copy assignment operator

    virtual int ComputeFare() const {}; // Function that computes fare
    
public:
    typedef BookingType<GeneralType> GeneralBooking;
    typedef BookingType<LadiesType> LadiesBooking;
    typedef BookingType<SeniorCitizenType> SeniorCitizenBooking;
    typedef BookingType<TatkalType> TatkalBooking;
    typedef BookingType<PremiumTatkalType> PremiumTatkalBooking;
    typedef BookingType<DivyaangType> DivyaangBooking;

    static int sBookingPNRSerial; // Static variable to serially allocate PNRs, starting from 1
    static const double sBaseFarePerKM; // Base fare per km
    static vector<Booking*> sBookings; // List of all bookings
    Booking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation,
	const BookingClass& bookingClass, const BookingCategory& bookingCategory, const Passenger& passenger, bool bookingStatus = true, const string& bookingMessage = "BOOKING SUCCEEDED!");
    virtual ~Booking() // Destructor
    {
        #if _DEBUG
            cout << "Booking Destroyed" << endl;
        #endif  // _DEBUG
    };

    static const Booking& ReserveBooking(const string&, const string&, const string&, const BookingClass&, 
                        const BookingCategory&, const Passenger&);

    friend ostream &operator<<(ostream &, const Booking &); // Output stream operator
    
    static void UnitTestBooking(); // Static function for unit testing
};

template <typename T>
class BookingType : public Booking
{
private:
    static const string sName;
public:
    BookingType(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation,
	 			const BookingClass& bookingClass, const BookingCategory& bookingCategory, const Passenger& passenger) : 
                Booking(fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory, passenger)
    {
        #if _DEBUG
            cout << "BookingType Created" << endl;
        #endif  // _DEBUG
    }
    ~BookingType()
    {
        #if _DEBUG
            cout << "BookingType Destroyed" << endl;
        #endif  // _DEBUG
    }
    const string &GetName() const
    {
        return sName;
    }
    int ComputeFare() const;
};

#endif // __BOOKING_H