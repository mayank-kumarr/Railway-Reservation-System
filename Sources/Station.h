/*
    Mayank Kumar
    19CS30029
*/

#ifndef __STATION_H // Control inclusion of header files
#define __STATION_H

// C++ Headers
#include <string>
#include<iostream>
using namespace std;

// Declaration for 'Station' class
class Station
{
private:
    const string name_; // Variable name
    Station& operator=(const Station &); // Blocked copy assignment operator

public:
    Station(const string &); // Constructor
    Station(const Station &); // Copy constructor
    ~Station(); // Destructor

    string GetName() const; // Function that gives name of station
    int GetDistance(const Station &) const; // Function that gives distance from one Station to another
    static Station CreateStation(const string &);
    friend ostream &operator<<(std::ostream &, const Station &); // Output stream operator
    static void UnitTestStation(); // Static function for unit testing
};

#endif // __STATION_H