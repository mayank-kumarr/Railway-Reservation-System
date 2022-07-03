/*
    Mayank Kumar
    19CS30029
*/

#include "UnitTestPassenger.h"

using namespace std;

void Passenger::UnitTestPassenger()
{
    Passenger* d = NULL;

    // Positive Test Case

    try
    {
        d = Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type());
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e) {
        cerr << e.what() << endl;
    }

    assert(Gender::isMale(d->GetGender()));
    assert(Date(16, 07, 2001) == d->GetDOB());
    assert("906125658148" == d->aadhaar_);
    assert("9631920388" == d->mobile_);
    assert(Divyaang::None::Type().IsEligible(*d) == true);

    // Positive Test Case

    try
    {
        d = Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::TB::Type(), "3114");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }
    
    assert(Divyaang::TB::Type().IsEligible(*d) == true);

    cout << endl;

    // Negative test case, Date of birth from future

    try
    {
        d = Passenger::CreatePassenger("Mayank", "", "", "16/07/2025", Gender::Male::Type(), "906125658148", "", Divyaang::Blind::Type(), "22");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    Passenger* p = d;

    cout << endl;

    // Negative test case, First namee and last name is absent

    try
    {
        p = Passenger::CreatePassenger("", "Kumar", "", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::Blind::Type(), "22");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);

    cout << endl;

    // Negative test case, First name, middle name and last name is absent

    try
    {
        p = Passenger::CreatePassenger("", "", "", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::Cancer::Type(), "3114");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);
    
    cout << endl;

    // Negative test case, Invalid Date of Birth

    try
    {
        p = Passenger::CreatePassenger("Mayank", "Kumar", "", "29/02/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::Cancer::Type(), "3114");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);

    cout << endl;

    // Negative test case, Invalid Date of Birth

    try
    {
        p = Passenger::CreatePassenger("Mayank", "Kumar", "", "30/02/2000", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::Cancer::Type(), "3114");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);

    cout << endl;

    // Negative test case, Invalid Aadhaar

    try
    {
        p = Passenger::CreatePassenger("Mayank", "Kumar", "", "16/07/2001", Gender::Male::Type(), "9061", "9631920388", Divyaang::Cancer::Type(), "3114");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);

    cout << endl;

    // Negative test case, Invalid Aadhaar

    try
    {
        p = Passenger::CreatePassenger("Mayank", "Kumar", "", "16/07/2001", Gender::Male::Type(), "9061abcd", "9631920388", Divyaang::Cancer::Type(), "3114");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);

    cout << endl;

    // Negative test case, Invalud Mobile no.

    try
    {
        p = Passenger::CreatePassenger("Mayank", "Kumar", "", "16/07/2001", Gender::Male::Type(), "906125658148", "96319203885", Divyaang::Cancer::Type(), "3114");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);

    cout << endl;

    // Negative test case, Invalid Mobile No.

    try
    {
        p = Passenger::CreatePassenger("Mayank", "Kumar", "", "16/07/2001", Gender::Male::Type(), "906125658148", "9631903ij", Divyaang::Cancer::Type(), "3114");
        cout << *p;
    } catch(BadPassenger& e) {
        cerr << e.what() << endl;
    } catch(exception& e) {
        cerr << e.what() << endl;
    }

    assert(p == d);

    cout << endl;

    // Negative test case, DisabilityID not mentioned even when Disability is not None

    try
    {
        p = Passenger::CreatePassenger("Mayank", "Kumar", "", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::Cancer::Type());
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);

    cout << endl;

    // Negative test case, DisabilityID mentioned even when Disability is None

    try
    {
        p = Passenger::CreatePassenger("Mayank", "Kumar", "", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type(), "3114");
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(p == d);

    // Positive Test Case

    Passenger* ps = NULL;
    try
    {
        ps = Passenger::CreatePassenger("Mayank", "", "Kumar", "16/07/2001", Gender::Male::Type(), "906125658148", "9631920388", Divyaang::None::Type());
    }
    catch(BadPassenger& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e) {
        cerr << e.what() << endl;
    }
    
    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << *ps; // Writing the Passenger object 'ps' to stringstream object 'out'
    ifstream log("GoldenUnitTestPassenger.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of Passenger object 'ps' to stringstream object 'out'
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
    Passenger::UnitTestPassenger();
    return 0;
}