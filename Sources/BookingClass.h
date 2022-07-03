/*
    Mayank Kumar
    19CS30029
    BookingClass.h
*/

#ifndef __BOOKINGCLASS_H // Control inclusion of header files
#define __BOOKINGCLASS_H

// C++ Headers
#include <string>
#include <iostream>
using namespace std;

// Booking class type
template <typename T>
class BookingClassType;

// BookingClass class declaration
class BookingClass
{
private:
    // structs for different booking classes
    struct ACFirstClassType {};
    struct AC2TierType {};
    struct FirstClassType {};
    struct AC3TierType {};
    struct ACChairCarType {};
    struct ExecutiveChairCarType {};
    struct SleeperType {};
    struct SecondSittingType {};
    
protected:
    const string name_; // stiores name of booking class
    // constructor
    BookingClass()
    {
        #if _DEBUG
            cout << "BookingClass Created" << endl;
        #endif  // _DEBUG
    }
    // copy constructor
    BookingClass(const string &name) : name_(name)
    {

    }
    // destructor
    virtual ~BookingClass()
    {
        #if _DEBUG
            cout << "BookingClass Destroyed" << endl;
        #endif  // _DEBUG
    }
public:
    // typedef for different BookingClass
    typedef BookingClassType<ACFirstClassType> ACFirstClass;
    typedef BookingClassType<AC2TierType> AC2Tier;
    typedef BookingClassType<FirstClassType> FirstClass;
    typedef BookingClassType<AC3TierType> AC3Tier;
    typedef BookingClassType<ACChairCarType> ACChairCar;
    typedef BookingClassType<ExecutiveChairCarType> ExecutiveChairCar;
    typedef BookingClassType<SleeperType> Sleeper;
    typedef BookingClassType<SecondSittingType> SecondSitting;
    const string& GetName() const // returns name of BookingClass
    {
        return name_;
    };
    virtual bool IsSitting() const = 0;
    virtual bool IsAC() const = 0;
    virtual bool IsLuxury() const = 0;
    virtual double GetLoadFactor() const = 0;
    virtual double GetReservationCharge() const = 0;
    virtual double GetTatkalLoadFactor() const = 0;
    virtual double GetMinTatkalCharge() const = 0;
    virtual double GetMaxTatkalCharge() const = 0;
    virtual int GetMinTatkalDist() const = 0;
    virtual int GetNumberOfTiers() const = 0;
    // output stream operator
    friend ostream& operator<<(ostream&, const BookingClass&);
    static void UnitTestBookingClass(); // for unit testing

};

// BookingClassType declaration
template <typename T>
class BookingClassType : public BookingClass
{
private:
    // attributes of BookingClassType
    static const string sName;
    static const bool sIsAC;
    static const bool sIsLuxury;
    static const bool sIsSitting;
    static const double sLoadFactor;
    static const int sTiers;
    static const double sReservationCharge;
    static const double sTatkalFactor;
    static const double sTatkalMinCharge;
    static const double sTatkalMaxCharge;
    static const int sMinTatkalDistance;
protected:
    BookingClassType(const string& name = sName) : BookingClass(name)
    {
        #if _DEBUG
            cout << "BookingClassType Created" << endl;
        #endif  // _DEBUG
    };
    ~BookingClassType()
    {
        #if _DEBUG
            cout << "BookingClassType Destroyed" << endl;
        #endif  // _DEBUG
    };
public:
    // to return static const objecty, singleton
    static const BookingClassType<T> &Type()
    {
        static const BookingClassType<T> instance;
        return instance;
    };
    bool IsAC() const
    {
        return sIsAC;
    }
    bool IsLuxury() const
    {
        return sIsLuxury;
    }
    bool IsSitting() const
    {
        return sIsSitting;
    }
    double GetLoadFactor() const
    {
        return sLoadFactor;
    }
    int GetNumberOfTiers() const
    {
        return sTiers;
    }
    string GetName() const
    {
        return sName;
    }
    double GetReservationCharge() const
    {
        return sReservationCharge;
    }
    double GetTatkalLoadFactor() const
    {
        return sTatkalFactor;
    }
    double GetMinTatkalCharge() const
    {
        return sTatkalMinCharge;
    }
    double GetMaxTatkalCharge() const
    {
        return sTatkalMaxCharge;
    }
    int GetMinTatkalDist() const
    {
        return sMinTatkalDistance;
    }
    // for unit testing
    static void UnitTestBookingClassType();
};

#endif // __BOOKINGCLASS_H