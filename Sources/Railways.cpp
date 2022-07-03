/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "Railways.h"
#include "Exception.h"

// initializing static variables
vector<Station> Railways::sStations = {Station("Mumbai"), Station("Delhi"), Station("Kolkata"), Station("Bangalore"), Station("Chennai")};
map<pair<string, string>, int> Railways::sDistStations;

// constructor
Railways::Railways()
{
    #if _DEBUG
        cout << "Railways Created" << endl;
    #endif  // _DEBUG
    AddDistance("Mumbai", "Delhi", 1447);
    AddDistance("Mumbai", "Bangalore", 981);
    AddDistance("Mumbai", "Kolkata", 2014);
    AddDistance("Mumbai", "Chennai", 1338);
    AddDistance("Delhi", "Kolkata", 1472);
    AddDistance("Delhi", "Chennai", 2180);
    AddDistance("Delhi", "Bangalore", 2150);
    AddDistance("Bangalore", "Kolkata", 1871);
    AddDistance("Bangalore", "Chennai", 350);
    AddDistance("Kolkata", "Chennai", 1659);
}

// destructor
Railways::~Railways()
{
    #if _DEBUG
        cout << "Railways Destroyed" << endl;
    #endif  // _DEBUG
}

// Function for adding distance between two stations in master data

void Railways::AddDistance(const string& station1, const string& station2, int distance)
{
    sDistStations[make_pair(station1, station2)] = distance;
    sDistStations[make_pair(station2, station1)] = distance;
}

// Function to return Station object for a given station name

const Station* Railways::GetStation(const string& name) const
{
    vector<Station>::const_iterator it;
    try
    {
        int x = 0;
        for(it = Railways::sStations.begin(); it != Railways::sStations.end(); ++it)
            if((*it).GetName() == name)
            {
                x = 1;
                return &(*it);
            }
        if(x == 0)
        {
            BadStation e("Invalid Station Name");
            throw e; // throws error if station was not present
        }
    }
    catch(BadRailways& e)
    {
        cerr << e.what() << endl;
    }    
}

// Function to get distance between two stations

int Railways::GetDistance(const Station &x, const Station &y) const
{
    int dist = 0;
    try
    {
        if(x.GetName() == y.GetName())
        {
            DistanceOutOfBound e("From and To stations cannot be same. Enter something other than " + x.GetName() + " in the two fields.");
            throw e; // throws error if tried to get distance between same stations
        }
        dist = Railways::sDistStations.at({x.GetName(), y.GetName()});
    }
    catch(DistanceOutOfBound& e)
    {
        cerr << e.what() << endl;
    }
    return dist;
}

// IndianRailways() function for singleton-ness

const Railways& Railways::IndianRailways()
{
    static const Railways instance;
    return instance;
}

// output stream operator

ostream& operator<<(ostream& os, const Railways& railways)
{
    vector<Station>::const_iterator it;
    os << "Indian Railways: " << endl;
    for(it = railways.sStations.begin(); it != railways.sStations.end(); ++it)
    {
        os << " " << *it << endl;
    }
    return os;
}