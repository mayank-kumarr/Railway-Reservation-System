// CS20006 Assignment 5
// @author Mayank Kumar (19CS30029)

// Project Headers
#include "UnitTestBookingClass.h"

// Function body for ACFirstClass for unit testing

template <> void BookingClass::ACFirstClass::UnitTestBookingClassType()
{
    const ACFirstClass &i = ACFirstClass::Type(); // Creating an object of ACFirstClass class
    assert(true == (&i == &ACFirstClass::Type())); // Verified if the previous object created is same as another object of ACFirstClass class

    // Testing the IsSitting(), IsAC(), IsLuxury(), GetNumberOfTiers(), GetName(), GetLoadFactor(), GetReservationCharge(), GetTatkalLoadFactor()
    //  GetMinTatkalCharge(), GetMaxTatkalCharge(), GetMinTatkalDist() functions

    assert(false==i.IsSitting()); // Verified if class is for sitting or sleeping
    assert(true==i.IsAC()); // Verified if class is AC or non-AC
    assert(true==i.IsLuxury()); // Verified if class is luxury or ordinary
    assert(2==i.GetNumberOfTiers()); // Verified number of tiers of the class
    assert("ACFirstClass"==i.GetName()); // Verified name of the class
    assert(6.5==i.GetLoadFactor()); // Verified load factor of the class
    assert(60.0==i.GetReservationCharge()); // Verified reservation charge of the class
    assert(0.3==i.GetTatkalLoadFactor()); // Verified tatkal factor of the class
    assert(400.0 == i.GetMinTatkalCharge()); // Verified min tatkal charge of the class
    assert(500.0 == i.GetMaxTatkalCharge()); // Verified max tatkal charge of the class
    assert(500 == i.GetMinTatkalDist()); // Verified min tatkal distance of the class

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the BookingClassType object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestACFirstClass.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of BookingClassType object 'i' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

// Function body for AC2Tier for unit testing

template <> void BookingClass::AC2Tier::UnitTestBookingClassType()
{
    const AC2Tier &i = AC2Tier::Type(); // Creating an object of AC2Tier class
    assert(true == (&i == &AC2Tier::Type())); // Verified if the previous object created is same as another object of AC2Tier class

    // Testing the IsSitting(), IsAC(), IsLuxury(), GetNumberOfTiers(), GetName(), GetLoadFactor(), GetReservationCharge(), GetTatkalLoadFactor()
    //  GetMinTatkalCharge(), GetMaxTatkalCharge(), GetMinTatkalDist() functions

    assert(false==i.IsSitting()); // Verified if class is for sitting or sleeping
    assert(true==i.IsAC()); // Verified if class is AC or non-AC
    assert(false==i.IsLuxury()); // Verified if class is luxury or ordinary
    assert(2==i.GetNumberOfTiers()); // Verified number of tiers of the class
    assert("AC2Tier"==i.GetName()); // Verified name of the class
    assert(4.0==i.GetLoadFactor()); // Verified load factor of the class
    assert(50.0==i.GetReservationCharge()); // Verified reservation charge of the class
    assert(0.3==i.GetTatkalLoadFactor()); // Verified tatkal factor of the class
    assert(400.0 == i.GetMinTatkalCharge()); // Verified min tatkal charge of the class
    assert(500.0 == i.GetMaxTatkalCharge()); // Verified max tatkal charge of the class
    assert(500 == i.GetMinTatkalDist()); // Verified min tatkal distance of the class

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the BookingClassType object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestAC2Tier.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of BookingClassType object 'i' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

// Function body for FirstClass for unit testing

template <> void BookingClass::FirstClass::UnitTestBookingClassType()
{
    const FirstClass &i = FirstClass::Type(); // Creating an object of FirstClass class
    assert(true == (&i == &FirstClass::Type())); // Verified if the previous object created is same as another object of FirstClass class

    // Testing the IsSitting(), IsAC(), IsLuxury(), GetNumberOfTiers(), GetName(), GetLoadFactor(), GetReservationCharge(), GetTatkalLoadFactor()
    //  GetMinTatkalCharge(), GetMaxTatkalCharge(), GetMinTatkalDist() functions

    assert(false==i.IsSitting()); // Verified if class is for sitting or sleeping
    assert(false==i.IsAC()); // Verified if class is AC or non-AC
    assert(true==i.IsLuxury()); // Verified if class is luxury or ordinary
    assert(2==i.GetNumberOfTiers()); // Verified number of tiers of the class
    assert("FirstClass"==i.GetName()); // Verified name of the class
    assert(3.0==i.GetLoadFactor()); // Verified load factor of the class
    assert(50.0==i.GetReservationCharge()); // Verified reservation charge of the class
    assert(0.3==i.GetTatkalLoadFactor()); // Verified tatkal factor of the class
    assert(400.0 == i.GetMinTatkalCharge()); // Verified min tatkal charge of the class
    assert(500.0 == i.GetMaxTatkalCharge()); // Verified max tatkal charge of the class
    assert(500 == i.GetMinTatkalDist()); // Verified min tatkal distance of the class

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the BookingClassType object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestFirstClass.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of BookingClassType object 'i' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

// Function body for AC3Tier for unit testing

template <> void BookingClass::AC3Tier::UnitTestBookingClassType()
{
    const AC3Tier &i = AC3Tier::Type(); // Creating an object of AC3Tier class
    assert(true == (&i == &AC3Tier::Type())); // Verified if the previous object created is same as another object of AC3Tier class

    // Testing the IsSitting(), IsAC(), IsLuxury(), GetNumberOfTiers(), GetName(), GetLoadFactor(), GetReservationCharge(), GetTatkalLoadFactor()
    //  GetMinTatkalCharge(), GetMaxTatkalCharge(), GetMinTatkalDist() functions

    assert(false==i.IsSitting()); // Verified if class is for sitting or sleeping
    assert(true==i.IsAC()); // Verified if class is AC or non-AC
    assert(false==i.IsLuxury()); // Verified if class is luxury or ordinary
    assert(3==i.GetNumberOfTiers()); // Verified number of tiers of the class
    assert("AC3Tier"==i.GetName()); // Verified name of the class
    assert(2.5==i.GetLoadFactor()); // Verified load factor of the class
    assert(40.0==i.GetReservationCharge()); // Verified reservation charge of the class
    assert(0.3==i.GetTatkalLoadFactor()); // Verified tatkal factor of the class
    assert(300.0 == i.GetMinTatkalCharge()); // Verified min tatkal charge of the class
    assert(400.0 == i.GetMaxTatkalCharge()); // Verified max tatkal charge of the class
    assert(500 == i.GetMinTatkalDist()); // Verified min tatkal distance of the class

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the BookingClassType object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestAC3Tier.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of BookingClassType object 'i' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

// Function body for ACChairCar for unit testing

template <> void BookingClass::ACChairCar::UnitTestBookingClassType()
{
    const ACChairCar &i = ACChairCar::Type(); // Creating an object of ACChairCar class
    assert(true == (&i == &ACChairCar::Type())); // Verified if the previous object created is same as another object of ACChairCar class

    // Testing the IsSitting(), IsAC(), IsLuxury(), GetNumberOfTiers(), GetName(), GetLoadFactor(), GetReservationCharge(), GetTatkalLoadFactor()
    //  GetMinTatkalCharge(), GetMaxTatkalCharge(), GetMinTatkalDist() functions

    assert(true==i.IsSitting()); // Verified if class is for sitting or sleeping
    assert(true==i.IsAC()); // Verified if class is AC or non-AC
    assert(false==i.IsLuxury()); // Verified if class is luxury or ordinary
    assert(0==i.GetNumberOfTiers()); // Verified number of tiers of the class
    assert("ACChairCar"==i.GetName()); // Verified name of the class
    assert(2.0==i.GetLoadFactor()); // Verified load factor of the class
    assert(40.0==i.GetReservationCharge()); // Verified reservation charge of the class
    assert(0.3==i.GetTatkalLoadFactor()); // Verified tatkal factor of the class
    assert(125.0 == i.GetMinTatkalCharge()); // Verified min tatkal charge of the class
    assert(225.0 == i.GetMaxTatkalCharge()); // Verified max tatkal charge of the class
    assert(250 == i.GetMinTatkalDist()); // Verified min tatkal distance of the class

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the BookingClassType object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestACChairCar.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of BookingClassType object 'i' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

// Function body for Sleeper for unit testing

template <> void BookingClass::Sleeper::UnitTestBookingClassType()
{
    const Sleeper &i = Sleeper::Type(); // Creating an object of Sleeper class
    assert(true == (&i == &Sleeper::Type())); // Verified if the previous object created is same as another object of Sleeper class

    // Testing the IsSitting(), IsAC(), IsLuxury(), GetNumberOfTiers(), GetName(), GetLoadFactor(), GetReservationCharge(), GetTatkalLoadFactor()
    //  GetMinTatkalCharge(), GetMaxTatkalCharge(), GetMinTatkalDist() functions

    assert(false==i.IsSitting()); // Verified if class is for sitting or sleeping
    assert(false==i.IsAC()); // Verified if class is AC or non-AC
    assert(false==i.IsLuxury()); // Verified if class is luxury or ordinary
    assert(3==i.GetNumberOfTiers()); // Verified number of tiers of the class
    assert("Sleeper"==i.GetName()); // Verified name of the class
    assert(1.0==i.GetLoadFactor()); // Verified load factor of the class
    assert(20.0==i.GetReservationCharge()); // Verified reservation charge of the class
    assert(0.3==i.GetTatkalLoadFactor()); // Verified tatkal factor of the class
    assert(100.0 == i.GetMinTatkalCharge()); // Verified min tatkal charge of the class
    assert(200.0 == i.GetMaxTatkalCharge()); // Verified max tatkal charge of the class
    assert(500 == i.GetMinTatkalDist()); // Verified min tatkal distance of the class

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the BookingClassType object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestSleeper.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of BookingClassType object 'i' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

// Function body for SecondSitting for unit testing

template <> void BookingClass::SecondSitting::UnitTestBookingClassType()
{
    const SecondSitting &i = SecondSitting::Type(); // Creating an object of SecondSitting class
    assert(true == (&i == &SecondSitting::Type())); // Verified if the previous object created is same as another object of SecondSitting class

    // Testing the IsSitting(), IsAC(), IsLuxury(), GetNumberOfTiers(), GetName(), GetLoadFactor(), GetReservationCharge(), GetTatkalLoadFactor()
    //  GetMinTatkalCharge(), GetMaxTatkalCharge(), GetMinTatkalDist() functions

    assert(true==i.IsSitting()); // Verified if class is for sitting or sleeping
    assert(false==i.IsAC()); // Verified if class is AC or non-AC
    assert(false==i.IsLuxury()); // Verified if class is luxury or ordinary
    assert(0==i.GetNumberOfTiers()); // Verified number of tiers of the class
    assert("SecondSitting"==i.GetName()); // Verified name of the class
    assert(0.6==i.GetLoadFactor()); // Verified load factor of the class
    assert(15.0==i.GetReservationCharge()); // Verified reservation charge of the class
    assert(0.1==i.GetTatkalLoadFactor()); // Verified tatkal factor of the class
    assert(10.0 == i.GetMinTatkalCharge()); // Verified min tatkal charge of the class
    assert(15.0 == i.GetMaxTatkalCharge()); // Verified max tatkal charge of the class
    assert(100 == i.GetMinTatkalDist()); // Verified min tatkal distance of the class

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the BookingClassType object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestSecondSitting.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of BookingClassType object 'i' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

// Function body for ExecutiveChairCar for unit testing

template <> void BookingClass::ExecutiveChairCar::UnitTestBookingClassType()
{
    const ExecutiveChairCar &i = ExecutiveChairCar::Type(); // Creating an object of ExecutiveChairCar class
    assert(true == (&i == &ExecutiveChairCar::Type())); // Verified if the previous object created is same as another object of ExecutiveChairCar class

    // Testing the IsSitting(), IsAC(), IsLuxury(), GetNumberOfTiers(), GetName(), GetLoadFactor(), GetReservationCharge(), GetTatkalLoadFactor()
    //  GetMinTatkalCharge(), GetMaxTatkalCharge(), GetMinTatkalDist() functions

    assert(false==i.IsSitting()); // Verified if class is for sitting or sleeping
    assert(true==i.IsAC()); // Verified if class is AC or non-AC
    assert(true==i.IsLuxury()); // Verified if class is luxury or ordinary
    assert(0==i.GetNumberOfTiers()); // Verified number of tiers of the class
    assert("ExecutiveChairCar"==i.GetName()); // Verified name of the class
    assert(5.0==i.GetLoadFactor()); // Verified load factor of the class
    assert(60.0==i.GetReservationCharge()); // Verified reservation charge of the class
    assert(0.3==i.GetTatkalLoadFactor()); // Verified tatkal factor of the class
    assert(400.0 == i.GetMinTatkalCharge()); // Verified min tatkal charge of the class
    assert(500.0 == i.GetMaxTatkalCharge()); // Verified max tatkal charge of the class
    assert(250 == i.GetMinTatkalDist()); // Verified min tatkal distance of the class

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the BookingClassType object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestExecutiveChairCar.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of BookingClassType object 'i' to stringstream object 'out'
       assert(expOut.str()==out.str()); // Verified if expected output in stringstream object 'expOut' is same as the output to stringstream object 'out'
    }
    else
    {
       cout << "Error... LogFile not found!" << endl;
       exit(1);
    }

    return; // return statement
}

int main()
{
    BookingClass::ACFirstClass::UnitTestBookingClassType(); // for unit testing ACFirstClass
    BookingClass::AC2Tier::UnitTestBookingClassType(); // for unit testing AC2Tier
    BookingClass::FirstClass::UnitTestBookingClassType(); // for unit testing FirstClass
    BookingClass::AC3Tier::UnitTestBookingClassType(); // for unit testing AC3Tier
    BookingClass::ACChairCar::UnitTestBookingClassType(); // for unit testing ACChairCar
    BookingClass::Sleeper::UnitTestBookingClassType(); // for unit testing Sleeper
    BookingClass::SecondSitting::UnitTestBookingClassType(); // for unit testing SecondSitting
    BookingClass::ExecutiveChairCar::UnitTestBookingClassType(); // for unit testing ExecutiveChairCar

    return 0; // return statement
}
