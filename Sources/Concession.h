/*
    Mayank Kumar
    19CS30029
*/

#ifndef __CONCESSION
#define __CONCESSION

// C++ Headers
#include <string>
#include <map>

// Project Headers
#include "Passenger.h"
#include "BookingClass.h"
#include "BookingCategory.h"
using namespace std;

// Forward Declarations
class BookingClass;
class Divyaang;

// Declaration for Concession class
class Concession
{
protected:
    Concession()
    {
        #if _DEBUG
            cout << "Concession Created" << endl;
        #endif  // _DEBUG
    }
    ~Concession()
    {
        #if _DEBUG
            cout << "Concession Destroyed" << endl;
        #endif  // _DEBUG
    };
};

class GeneralConcession : public Concession
{
private:
    const double sFactor = 0.0;
    // constructor
    GeneralConcession()
    {
        #if _DEBUG
            cout << "GeneralConcession Created" << endl;
        #endif  // _DEBUG
    }
    // destructor
    ~GeneralConcession()
    {
        #if _DEBUG
            cout << "GeneralConcession Destroyed" << endl;
        #endif  // _DEBUG
    }
public:
    // returns concession factor
    double GetFactor() const
    {
        return sFactor;
    }
    // returns static const object, singleton class
    static const GeneralConcession &Type()
    {
        static const GeneralConcession instance;
        return instance;
    }
};

class LadiesConcession : public Concession
{
private:
    const double sFactor = 0.0;

    // constructor
    LadiesConcession()
    {
        #if _DEBUG
            cout << "LadiesConcession Created" << endl;
        #endif  // _DEBUG
    }

    // destructor
    ~LadiesConcession()
    {
        #if _DEBUG
            cout << "LadiesConcession Destroyed" << endl;
        #endif  // _DEBUG
    }
public:

    // returns concession factor
    double GetFactor() const
    {
        return sFactor;
    }
    // returns static const object, singleton class
    static const LadiesConcession& Type()
    {
        static const LadiesConcession instance;
        return instance;
    }
};

class SeniorCitizenConcession : public Concession
{
private:
    const double sFactorMale = 0.4;
    const double sFactorFemale = 0.5;

    // constructor
    SeniorCitizenConcession()
    {
        #if _DEBUG
            cout << "SeniorCitizenConcession Created" << endl;
        #endif  // _DEBUG
    }

    // destructor
    ~SeniorCitizenConcession()
    {
        #if _DEBUG
            cout << "SeniorCitizenConcession Destroyed" << endl;
        #endif  // _DEBUG
    }
public:

    // returns concession factor
    double GetFactor(const Passenger &p) const
    {
        if(Gender::isMale(p.GetGender())==true)
            return sFactorMale;
        else
            return sFactorFemale;
    }

    // returns static const object, singleton class
    static const SeniorCitizenConcession &Type()
    {
        static const SeniorCitizenConcession instance;
        return instance;
    }
};

class DivyaangConcession : public Concession
{
private:
    const map<pair<const BookingClass*, const Divyaang*>, double> sFactors =
    {
        // master data for DivyaangConcession class
        {{&BookingClass::ACFirstClass::Type(), &Divyaang::Blind::Type()}, 0.50},
        {{&BookingClass::ACFirstClass::Type(), &Divyaang::OrthHandicapped::Type()}, 0.50},
        {{&BookingClass::ACFirstClass::Type(), &Divyaang::Cancer::Type()}, 0.50},
        {{&BookingClass::ACFirstClass::Type(), &Divyaang::TB::Type()}, 0.00},

        {{&BookingClass::ExecutiveChairCar::Type(), &Divyaang::Blind::Type()}, 0.75},
        {{&BookingClass::ExecutiveChairCar::Type(), &Divyaang::OrthHandicapped::Type()}, 0.75},
        {{&BookingClass::ExecutiveChairCar::Type(), &Divyaang::Cancer::Type()}, 0.75},
        {{&BookingClass::ExecutiveChairCar::Type(), &Divyaang::TB::Type()}, 0.00},

        {{&BookingClass::AC2Tier::Type(), &Divyaang::Blind::Type()}, 0.50},
        {{&BookingClass::AC2Tier::Type(), &Divyaang::OrthHandicapped::Type()}, 0.50},
        {{&BookingClass::AC2Tier::Type(), &Divyaang::Cancer::Type()}, 0.50},
        {{&BookingClass::AC2Tier::Type(), &Divyaang::TB::Type()}, 0.00},

        {{&BookingClass::FirstClass::Type(), &Divyaang::Blind::Type()}, 0.75},
        {{&BookingClass::FirstClass::Type(), &Divyaang::OrthHandicapped::Type()}, 0.75},
        {{&BookingClass::FirstClass::Type(), &Divyaang::Cancer::Type()}, 0.75},
        {{&BookingClass::FirstClass::Type(), &Divyaang::TB::Type()}, 0.75},

        {{&BookingClass::AC3Tier::Type(), &Divyaang::Blind::Type()}, 0.75},
        {{&BookingClass::AC3Tier::Type(), &Divyaang::OrthHandicapped::Type()}, 0.75},
        {{&BookingClass::AC3Tier::Type(), &Divyaang::Cancer::Type()}, 1.00},
        {{&BookingClass::AC3Tier::Type(), &Divyaang::TB::Type()}, 0.00},

        {{&BookingClass::ACChairCar::Type(), &Divyaang::Blind::Type()}, 0.75},
        {{&BookingClass::ACChairCar::Type(), &Divyaang::OrthHandicapped::Type()}, 0.75},
        {{&BookingClass::ACChairCar::Type(), &Divyaang::Cancer::Type()}, 1.00},
        {{&BookingClass::ACChairCar::Type(), &Divyaang::TB::Type()}, 0.00},

        {{&BookingClass::Sleeper::Type(), &Divyaang::Blind::Type()}, 0.75},
        {{&BookingClass::Sleeper::Type(), &Divyaang::OrthHandicapped::Type()}, 0.75},
        {{&BookingClass::Sleeper::Type(), &Divyaang::Cancer::Type()}, 1.00},
        {{&BookingClass::Sleeper::Type(), &Divyaang::TB::Type()}, 0.75},

        {{&BookingClass::SecondSitting::Type(), &Divyaang::Blind::Type()}, 0.75},
        {{&BookingClass::SecondSitting::Type(), &Divyaang::OrthHandicapped::Type()}, 0.75},
        {{&BookingClass::SecondSitting::Type(), &Divyaang::Cancer::Type()}, 1.00},
        {{&BookingClass::SecondSitting::Type(), &Divyaang::TB::Type()}, 0.75}
    };
    // constructor
    DivyaangConcession()
    {
        #if _DEBUG
            cout << "DivyaangConcession Created" << endl;
        #endif  // _DEBUG
    }
    // destructor
    ~DivyaangConcession()
    {
        #if _DEBUG
            cout << "DivyaangConcession Destroyed" << endl;
        #endif  // _DEBUG
    }
public:
    // returns concession factor
    double GetFactor(const Passenger &p, const BookingClass &b) const
    {
        return sFactors.at({&b, &(p.GetDisability())});
    }
    // returns static const object, singleton class
    static const DivyaangConcession& Type()
    {
        static const DivyaangConcession instance;
        return instance;
    }
};

#endif