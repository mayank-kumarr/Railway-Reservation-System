/*
    Mayank Kumar
    19CS30029
    BookingClass.h
*/

#include <exception>
#include <string>
using namespace std;

class Exception : public exception
{
protected:
    string st_;

public:
    Exception(const string& st) : st_(st){};
    const char* what() const throw() {
        return st_.c_str();
    }
};

class BadName : public Exception
{
public:
    BadName(const string& st) : Exception(st)
    {
        
    };
};

class NameTooShort : public BadName
{
public:
    NameTooShort(const string& st) : BadName(st)
    {
        
    };
};

class BadDate : public Exception
{
public:
    BadDate(const string& st) : Exception(st)
    {

    };
};

class DateOutOfBound : public BadDate
{
public:
    DateOutOfBound(const string& st) : BadDate(st)
    {
        
    };
};

class BadDateFormat : public BadDate
{
public:
    BadDateFormat(const string& st) : BadDate(st)
    {

    };
};

class InvalidDate : public BadDate
{
public:
    InvalidDate(const string& st) : BadDate(st)
    {
        
    };
};

class DOBTooLate : public BadDate
{
public:
    DOBTooLate(const string& st) : BadDate(st)
    {
        
    };
};

class BadStation : public Exception
{
public:
    BadStation(const string& st) : Exception(st)
    {

    };
};

class NameEmpty : public BadStation
{
public:
    NameEmpty(const string& st) : BadStation(st)
    {
        
    };
};

class BadRailways : public Exception
{
public:
    BadRailways(const string& st) : Exception(st)
    {

    };
};

class DuplicateStation : public BadRailways
{
public:
    DuplicateStation(const string& st) : BadRailways(st)
    {
        
    };
};

class InvalidStation : public BadRailways
{
public:
    InvalidStation(const string& st) : BadRailways(st)
    {
        
    };
};

class DistanceOutOfBound : public BadRailways
{
public:
    DistanceOutOfBound(const string& st) : BadRailways(st)
    {
        
    };
};

class DuplicateDistance : public BadRailways
{
public:
    DuplicateDistance(const string& st) : BadRailways(st)
    {
        
    };
};

class BadPassenger : public Exception
{
public:
    BadPassenger(const string& st) : Exception(st)
    {

    };
};

class BadPassengerName : public BadPassenger
{
public:
    BadPassengerName(const string& st) : BadPassenger(st)
    {
        
    };
};

class BadDOB : public BadPassenger
{
public:
    BadDOB(const string& st) : BadPassenger(st)
    {
        
    };
};

class BadAadhaar : public BadPassenger
{
public:
    BadAadhaar(const string& st) : BadPassenger(st)
    {
        
    };
};

class BadMobile : public BadPassenger
{
public:
    BadMobile(const string& st) : BadPassenger(st)
    {
        
    };
};

class BadBooking : public Exception
{
public:
    BadBooking(const string& st) : Exception(st)
    {

    };
};

class BadFromStation : public BadBooking
{
public:
    BadFromStation(const string& st) : BadBooking(st)
    {
        
    };
};

class BadToStation : public BadBooking
{
public:
    BadToStation(const string& st) : BadBooking(st)
    {
        
    };
};

class SameStation : public BadBooking
{
public:
    SameStation(const string& st) : BadBooking(st)
    {
        
    };
};

class BadReservationDate : public BadBooking
{
public:
    BadReservationDate(const string& st) : BadBooking(st)
    {
        
    };
};

class BadBookingDate : public BadBooking
{
public:
    BadBookingDate(const string& st) : BadBooking(st)
    {
        
    };
};

class SameDayBooking : public BadBooking
{
public:
    SameDayBooking(const string& st) : BadBooking(st)
    {
        
    };
};

class BadPassengerInfo : public BadBooking
{
public:
    BadPassengerInfo(const string& st) : BadBooking(st)
    {
        
    };
};