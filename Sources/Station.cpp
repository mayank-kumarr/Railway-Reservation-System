/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "Station.h"
#include "Railways.h"
#include "Exception.h"

// constructor
Station::Station(const string &station) : name_(station)
{
    #if _DEBUG
        cout << "Station Created" << endl;
    #endif  // _DEBUG
}

// copy constructor
Station::Station(const Station&station) : name_(station.name_)
{

}

// destructor
Station::~Station()
{
    #if _DEBUG
        cout << "Station Destroyed" << endl;
    #endif  // _DEBUG
}

// returns name of station
string Station::GetName () const
{ 
	return name_;
}

// returns distance between stations
int Station::GetDistance(const Station& station) const
{
    return Railways::IndianRailways().GetDistance(*this, station);
}

// creates and returns Station object for string input
Station Station::CreateStation(const string &str)
{
    try
    {
        if(str.length()==0)
        {
            BadStation e("Station name cannot be empty.");
            throw e; // throws error if station name is empty
        }
        vector<Station>::const_iterator it;
        for(it = Railways::IndianRailways().sStations.begin(); it != Railways::IndianRailways().sStations.end(); ++it)
            if(it->GetName() == str)
                return Station(str);
        BadStation e("Station not present in Railways.");
        throw e; // throws error for invalid station name
    }
    catch(BadStation& e)
    {
        cerr << e.what() << endl;
    }
}

// output stream operator
ostream& operator<<(ostream& os, const Station& station)
{
    os << "Station: " << station.name_;
    return os;
}