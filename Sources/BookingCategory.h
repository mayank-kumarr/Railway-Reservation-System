/*
    Mayank Kumar
    19CS30029
    BookingCategory.h
*/

#ifndef __BOOKINGCATEGORY_H  // Control inclusion of header files
#define __BOOKINGCATEGORY_H

// Project Headers
#include "Passenger.h"
#include "Station.h"

// C++ Headers
#include <string>
using namespace std;

// Forward Declarations
class Booking;
class BookingClass;

// BookingCategoryType
template <typename T>
class BookingCategoryType;

// DivyaangCategoryType
template <typename T>
class DivyaangCategoryType;

// Declaration for BookingCategory class
class BookingCategory
{
private:
    // structs for different categories
    struct GeneralType {};
    struct LadiesType {};
    struct SeniorCitizenType {};
    struct TatkalType {};
    struct PremiumTatkalType {};
protected:
    const string name_; // stores name of booking category
    BookingCategory(const string &); // constructor
    virtual ~BookingCategory(); // destructor
public:
    // typedefs for different booking categories
    typedef BookingCategoryType<GeneralType> General;
    typedef BookingCategoryType<LadiesType> Ladies;
    typedef BookingCategoryType<SeniorCitizenType> SeniorCitizen;
    typedef BookingCategoryType<TatkalType> Tatkal;
    typedef BookingCategoryType<PremiumTatkalType> PremiumTatkal;
    const string& GetName() const; // returns name of booking category
    virtual bool IsEligible(const Passenger &) const = 0; // returns true if passenger is eligible to book under that category
    // creates and returns Booking object for a booking category
    virtual Booking* CreateBooking(const Station&, const Station&, const Date&, const Date&, 
                    const BookingClass&, const Passenger&, const BookingCategory&) const = 0;
    static void UnitTestBookingCategory(); // for unit testing
};

// BookingCategoryType class declaration
template <typename T>
class BookingCategoryType : public BookingCategory
{
private:
    static const string &sName; // stores name of booking category
    // constructor
    BookingCategoryType(const string &name = sName) : BookingCategory(name)
    {
        #if _DEBUG
            cout << "BookingCategoryType Created" << endl;
        #endif  // _DEBUG
    }
    // destructor
    ~BookingCategoryType()
    {
        #if _DEBUG
            cout << "BookingCategoryType Destroyed" << endl;
        #endif  // _DEBUG
    }
public:
    const string &GetName() const; // returns name of booking category
    // returns static const object, singleton class
    static const BookingCategoryType<T> &Type()
    {
        static const BookingCategoryType<T> instance;
        return instance;
    }
    // creates and returns Booking object for given booking category
    Booking *CreateBooking(const Station&, const Station&, const Date&, const Date&, 
                const BookingClass&, const Passenger&, const BookingCategory&) const;
    // checks if the passenger is eligible to book under that category
    bool IsEligible(const Passenger &) const;
    static void UnitTestBookingCategoryType(); // for unit testing
};

class Divyaang : public BookingCategory
{
private:
    // structs for different Divyaang categories
    struct BlindType {};
    struct OrthHandicappedType {};
    struct CancerType {};
    struct TBType {};
    struct NoneType {};
protected:
    // constructor
    Divyaang(const string &name) : BookingCategory(name)
    {
        #if _DEBUG
            cout << "Divyaang Created" << endl;
        #endif  // _DEBUG
    }
    // destructor
    ~Divyaang()
    {
        #if _DEBUG
            cout << "Divyaang Destroyed" << endl;
        #endif  // _DEBUG
    };
public:

    // typedefs for different divyaang categories
    typedef DivyaangCategoryType<BlindType> Blind;
    typedef DivyaangCategoryType<OrthHandicappedType> OrthHandicapped;
    typedef DivyaangCategoryType<CancerType> Cancer;
    typedef DivyaangCategoryType<TBType> TB;
    typedef DivyaangCategoryType<NoneType> None;
    // checks if passenger is eligible to book under this divyaang category
    virtual bool IsEligible(const Passenger &) const = 0;
    // creates and returns Booking object for a divyaang category
    Booking* CreateBooking(const Station&, const Station&, const Date&, const Date&, 
                const BookingClass&, const Passenger&, const BookingCategory&) const;
    static void UnitTestDivyaang(); // for unit testing
};

// DivyaangCategoryType class declaration
template <typename T>
class DivyaangCategoryType : public Divyaang
{
private:
    static const string &sName; // stores name for divyaang category
    // constructor
    DivyaangCategoryType(const string &name = sName) : Divyaang(name)
    {
        #if _DEBUG
            cout << "DivyaangCategoryType Created" << endl;
        #endif  // _DEBUG
    }
    // destructor
    ~DivyaangCategoryType()
    {
        #if _DEBUG
            cout << "DivyaangCategoryType Destroyed" << endl;
        #endif  // _DEBUG
    }
public:
    // returns static const object, singleton class
    static const DivyaangCategoryType<T> &Type()
    {
        static const DivyaangCategoryType<T> instance;
        return instance;
    }
    // returns true if passenger is eligible to book under this divyaang category
    bool IsEligible(const Passenger &) const;
    static void UnitTestDivyaangCategoryType(); // for unit testing
};

#endif // __BOOKINGCATEGORY_H