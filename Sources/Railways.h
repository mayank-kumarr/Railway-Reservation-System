/*
    Mayank Kumar
    19CS30029
*/

#ifndef __RAILWAYS_H // Control inclusion of header files
#define __RAILWAYS_H

// Project Headers
#include "Station.h"

// C++ Headers
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Declaration for 'Railways' class
class Railways
{
private:
    static map<pair<string, string>, int> sDistStations; // Static variable to store distance between all distinct pairs of stations
    void AddDistance(const string&, const string&, int); // Inserts distance between two stations in sDistStations variable

    Railways(); // Constructor
    Railways(const Railways &); // Blocked copy constructor
    ~Railways(); // Destructor
    
    Railways& operator=(const Railways &); // Blocked copy assignment operator

public:
    static vector<Station> sStations; // Static variable to store all Station
    static const Railways &IndianRailways(); // Function that gives a static const object of Railways class
    int GetDistance(const Station &, const Station &) const; // Static function that gives distance between two stations
    const Station* GetStation(const string&) const; // returns Station object for a given station name
    friend ostream &operator<<(ostream &, const Railways &); // Output stream operator
    static void UnitTestRailways(); // Static function for unit testing
};

#endif // __RAILWAYS_H