/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "UnitTestStation.h"

// Function body of UnitTestStation() function for unit testing 'Station' class

void Station::UnitTestStation()
{
    Station s1("Mumbai"); // Constructor called with "Mumbai" as argument
    Station s2 = s1; // Copy constructor called
    Station s3("Kolkata"); // Copy constructor called

    assert("Mumbai"==s1.name_); // Verified if Station object 's1' has stored correct member
    assert("Mumbai"==s2.name_); // Verified if Station object 's2' has stored correct member
    assert("Kolkata"==s3.name_); // Verified if Station object 's3' has stored correct member

    // Testing the name of station given by GetName() function

    assert("Mumbai"==s1.GetName()); // Verified the name of Station object 's1'
    assert("Mumbai"==s2.GetName()); // Verified the name of Station object 's2'
    assert("Kolkata"==s3.GetName()); // Verified the name of Station object 's3'

    // Testing the distance between stations given by GetDistance() function
    assert(2014==s1.GetDistance(s3)); // Verified the distance between stations 's1' and 's3'

    // negative test case, station name empty

    string str = "";
    
    try
    {
        Station t = (Station::CreateStation(str));
    }
    catch(BadStation& e)
    {
        cerr << e.what() << endl;
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

    // negative test case, station name invalid

    str = "dijgh";

    try
    {
        Station t = (Station::CreateStation(str));
    }
    catch(BadStation& e)
    {
        cerr << e.what() << endl;
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

    // positive test case

    str = "Kolkata";

    try
    {
        Station t = (Station::CreateStation(str));
    }
    catch(BadStation& e)
    {
        cerr << e.what() << endl;
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << s3; // Writing the Station object 's3' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestStation.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of Station object 's3' to stringstream object 'out'
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
    Station::UnitTestStation(); // Called UnitTestStation() function for unit testing

    return 0; // return statement
}
