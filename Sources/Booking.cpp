/*
    Mayank Kumar
    19CS30029
*/

#include "Booking.h"
#include "Exception.h"

// initializing static attributes
int Booking::sBookingPNRSerial = 1;
vector<Booking*> Booking :: sBookings;
const double Booking::sBaseFarePerKM = 0.50;

// constructor
Booking::Booking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const Date& dateOfReservation,
	const BookingClass& bookingClass, const BookingCategory& bookingCategory, const Passenger& passenger, bool bookingStatus, const string& bookingMessage) : 
	fromStation_(fromStation), toStation_(toStation), dateOfBooking_(dateOfBooking), dateOfReservation_(dateOfReservation),
	bookingClass_(bookingClass), bookingCategory_(bookingCategory), passenger_(passenger), PNR_(sBookingPNRSerial), bookingStatus_(bookingStatus), bookingMessage_(bookingMessage)
{
    #if _DEBUG
            cout << "Booking Created" << endl;
        #endif  // _DEBUG
	sBookingPNRSerial += 1;
	sBookings.push_back(this);
}

// creates and reutrns Booking object when string inputs are given
// all the negative cases for booking are handled here
const Booking& Booking::ReserveBooking(const string& fromStationName, const string& toStationName, const string& bookingDate, const BookingClass& bookingClass, 
                        const BookingCategory& bookingCategory, const Passenger& passenger)
{
    const Station* fromStation;
    const Station* toStation;
    const Date* dateOfBooking;
    const Date dateOfReservation = Date::Today();
    int diff;
    bool flag = 0;
    
    // fromStation
    try
    {
        vector<Station>::const_iterator it;
        int x = 0;
        for(it = Railways::IndianRailways().sStations.begin(); it != Railways::IndianRailways().sStations.end(); ++it)
        {
            if(it->GetName() == fromStationName)
                fromStation = Railways::IndianRailways().GetStation(fromStationName), x = 1;
        }
        if(fromStationName.length()>0 && x==0)
        {
            BadFromStation e("Invalid From Station Name. " + fromStationName + " Station is not in Railways.");
            throw e; // throws error for invalid station name
        }
        else if(x==0)
        {
            BadFromStation e("Invalid From Station Name. Station name cannot be empty.");
            throw e; // throws error if station name was empty
        }
    }
    catch(BadStation& e)
    {
        cerr << e.what() << endl;
        flag = 1;
    }

    // toStation
    try
    {
        vector<Station>::const_iterator it;
        int x = 0;
        for(it = Railways::IndianRailways().sStations.begin(); it != Railways::IndianRailways().sStations.end(); ++it)
        {
            if(it->GetName() == toStationName)
                toStation = Railways::IndianRailways().GetStation(toStationName), x = 1;
        }
        if(toStationName.length()>0 && x==0)
        {
            BadToStation e("Invalid To Station Name. " + toStationName + " Station is not in Railways.");
            throw e; // throws error for invalid station name
        }
        else if(x==0)
        {
            BadToStation e("Invalid To Station Name. Station name cannot be empty.");
            throw e; // throws error if station name was empty
        }
    }
    catch(BadBooking& e)
    {
        cerr << e.what() << endl;
        flag = 1;
    }

    // checking if source and destination are same
    try
    {
        if(fromStation == toStation && fromStation != NULL && toStation != NULL)
        {
            SameStation e("From and To Stations cannot be same.");
            throw e; // throws error if from and to station are same
        }
    }
    catch (SameStation& e)
    {
        cerr << e.what() << endl;
        flag = 1;
    }

    // date of booking
    try
    {
        dateOfBooking = Date::CreateDate(bookingDate);
        diff = Date::subtract(*dateOfBooking, dateOfReservation);
        if(dateOfBooking == NULL)
        {
            BadBookingDate e("Date of Booking cannot be NULL.");
            throw e; // throws error if date of booking was null
        }

        if(diff < 0)
        {
            BadBookingDate e("Travel Date cannot be in past.");
            throw e; // throws error if travel date in past
        }

        if(diff == 0)
        {
            SameDayBooking e("Date of Booking cannot be same as Date of Reservation.");
            throw e; // throws error for same day reservation
        }
        if(diff>365)
        {
            BadBookingDate e("Reservation cannot be done more than one year prior to Travel Date.");
            throw e; // throws error for more than one year prior booking
        }
    }
    catch(BadDate& e)
    {
        cerr << e.what() << endl;
        flag = 1;
    }
    catch(BadBookingDate& e)
    {
        cerr << e.what() << endl;
        flag = 1;
    }
    catch(SameDayBooking& e)
    {
        cerr << e.what() << endl;
        flag = 1;
    }

    if(dateOfBooking != NULL)
    {
        try
        {
            if(bookingCategory.IsEligible(passenger) == false)
            {
                BadBooking e("Passenger is ineligible to book in " + bookingCategory.GetName() + " category");
                throw e; // throws error if passenger ineligible to book in that category
            }
            if((&bookingCategory == &BookingCategory::Tatkal::Type()) || (&bookingCategory == &BookingCategory::PremiumTatkal::Type()))
            {
                if(diff >= 2)
                {
                    BadBooking e("Tatkal or Premium Tatkal Bookings cannot be done more than one day prior to travel date.");
                    throw e; // throws error for date chosen for takal and premiuym tatkal booking category
                }
            }
        }
        catch(BadBooking& e)
        {
            cerr << e.what() << endl;
            flag = 1;
        }
    }
    try
    {
        if(flag == 1)
        {
            BadBooking e("Invalid Booking Information");
            throw e; // throws error if something goes wrong
        }
    }
    catch(BadBooking& e)
    {
        cerr << e.what() << endl;
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << endl;
    }
    
    Booking* booking = bookingCategory.CreateBooking(*fromStation, *toStation, dateOfReservation, *dateOfBooking, bookingClass, passenger, bookingCategory);
    if(flag == 0)
        booking -> fare_ = booking -> ComputeFare(); // computes fare if everything goes right
    if(flag == 1) // boking failed if something goes wrong
    {
        booking->bookingStatus_ = false;
        booking->bookingMessage_ = "Booking Failed!";
    }
    return *booking;
}

// functions for computing fare under different scenarios

template <> int Booking::GeneralBooking::ComputeFare() const
{
    int dist = static_cast<double>(fromStation_.GetDistance(toStation_));
    double baseFare = sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - (GeneralConcession::Type().GetFactor()));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.50);
}

template <> int Booking::LadiesBooking::ComputeFare() const
{
    int dist = static_cast<double>(fromStation_.GetDistance(toStation_));
    double baseFare = sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - (LadiesConcession::Type().GetFactor()));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template <> int Booking::SeniorCitizenBooking::ComputeFare() const
{
    int dist = static_cast<double>(fromStation_.GetDistance(toStation_));
    double baseFare = sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - (SeniorCitizenConcession::Type().GetFactor(passenger_)));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template <> int Booking::TatkalBooking::ComputeFare() const
{
    int dist = static_cast<double>(fromStation_.GetDistance(toStation_));
    double baseFare = sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    double tatkalFare = loadedFare * bookingClass_.GetTatkalLoadFactor();
    if(dist < bookingClass_.GetMinTatkalDist() || tatkalFare < bookingClass_.GetMinTatkalCharge())
        tatkalFare = 0.0;
    else if(tatkalFare > bookingClass_.GetMaxTatkalCharge())
        tatkalFare = bookingClass_.GetMaxTatkalCharge();
    double finalFare = loadedFare + tatkalFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template <> int Booking::PremiumTatkalBooking::ComputeFare() const
{
    int dist = static_cast<double>(fromStation_.GetDistance(toStation_));
    double baseFare = sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    double tatkalFare = loadedFare * bookingClass_.GetTatkalLoadFactor() * 2.00;
    if(dist < bookingClass_.GetMinTatkalDist() || tatkalFare < bookingClass_.GetMinTatkalCharge())
        tatkalFare = 0.0;
    else if(tatkalFare > bookingClass_.GetMaxTatkalCharge())
        tatkalFare = bookingClass_.GetMaxTatkalCharge();
    double finalFare = loadedFare + (2.0 * tatkalFare) + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template <> int Booking::DivyaangBooking::ComputeFare() const
{
    int dist = static_cast<double>(fromStation_.GetDistance(toStation_));
    double baseFare = sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - (DivyaangConcession::Type().GetFactor(passenger_, bookingClass_)));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

// output stream operator

ostream &operator<<(ostream &os, const Booking &booking)
{
    os << booking.bookingMessage_ << endl;
    os << "PNR Number : " << booking.PNR_ << endl;
    os << "From Station : " << booking.fromStation_.GetName() << endl;
    os << "To Station : " << booking.toStation_.GetName() << endl;
    os << "Travel Date : " << booking.dateOfBooking_ << endl;
    os << "Booking Date : " << booking.dateOfReservation_ << endl;
    os << "Booking Category : " << booking.bookingCategory_.GetName() << endl;
    os << booking.bookingClass_ << endl;
    os << "Passenger Information : \n" << booking.passenger_;
    os << "Fare = " << booking.fare_ << endl;
    return os;
}
