/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "UnitTestRailways.h"

// Function body of UnitTestRailways() function for unit testing 'Railways' class

void Railways::UnitTestRailways()
{
    const Railways& i = Railways::IndianRailways(); // Creating an object of Railways class
    assert(true == (&i==&Railways::IndianRailways())); // Verified if the previous object created is same as another object of Railways class

    // Testing the distance between stations given by GetDistance() function

    assert(1447 == i.GetDistance(Station("Mumbai"), Station("Delhi"))); // Verified the distance between Mumbai and Delhi
    assert(2014 == i.GetDistance(Station("Mumbai"), Station("Kolkata"))); // Verified the distance between Mumbai and Kolkata
    assert(981 == i.GetDistance(Station("Mumbai"), Station("Bangalore"))); // Verified the distance between Mumbai and Bangalore
    assert(1338 == i.GetDistance(Station("Mumbai"), Station("Chennai"))); // Verified the distance between Mumbai and Chennai

    assert(1472 == i.GetDistance(Station("Delhi"), Station("Kolkata"))); // Verified the distance between Delhi and Kolkata
    assert(2150 == i.GetDistance(Station("Delhi"), Station("Bangalore"))); // Verified the distance between Delhi and Bangalore
    assert(2180 == i.GetDistance(Station("Delhi"), Station("Chennai"))); // Verified the distance between Delhi and Chennai

    assert(1871 == i.GetDistance(Station("Kolkata"), Station("Bangalore"))); // Verified the distance between Kolkata and Bangalore
    assert(1659 == i.GetDistance(Station("Kolkata"), Station("Chennai"))); // Verified the distance between Kolkata and Chennai

    assert(350 == i.GetDistance(Station("Bangalore"), Station("Chennai"))); // Verified the distance between Bangalore and Chennai


    vector<Station>::const_iterator it1, it2; // iterators
    int cnt;
    for(it1 = i.sStations.begin(); it1 != i.sStations.end(); ++it1)
    {
        cnt = 0;
        for(it2 = i.sStations.begin(); it2 != i.sStations.end(); ++it2)
        {
            if((*it1).GetName() == (*it2).GetName())
                cnt++;
            if(i.GetDistance(*it1, *it2) != i.GetDistance(*it2, *it1)) // checking for duplicate distance
            {
                DuplicateDistance e("Duplicate Distance between two stations are present in master data.");
                cerr << e.what() << endl;
            }
            if(i.GetDistance(*it1, *it2) < 0) // checking for negative distance
            {
                BadRailways e("Negative Distance between two stations are present in master data.");
                cerr << e.what() << endl;
            }
        }
        if(cnt>2) // cnt will be 2 since every station is counted twice in the nested loop
        {
            DuplicateStation e("Duplicate Stations present in master data");
            cerr << e.what() << endl;
        }
    }


    // Testing the overloaded output stream operator <<
    
    stringstream expOut, out; // Creating the stringstream objects
    out << i; // Writing the Railways object 'i' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestRailways.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of Railways object 'i' to stringstream object 'out'
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
    Railways::UnitTestRailways(); // Called UnitTestRailways() function for unit testing

    return 0; // return statement
}
