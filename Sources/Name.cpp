/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "Name.h"
#include "Exception.h"

// constructor

Name::Name(const string& n1, const string& n2, const string& n3) : firstName_(n1), middleName_(n2), lastName_(n3)
{
    #if _DEBUG
        cout << "Name Created" << endl;
    #endif  // _DEBUG
}

// copy constructor

Name::Name(const Name& n) : firstName_(n.firstName_), middleName_(n.middleName_), lastName_(n.lastName_)
{
    
}

// destructor

Name::~Name()
{
    #if _DEBUG
        cout << "Name Destroyed" << endl;
    #endif  // _DEBUG
};

// output stream operator

ostream& operator<<(ostream& os, const Name& name)
{
    if (name.firstName_.length() > 0)
        os << name.firstName_ << " ";
    if (name.middleName_.length() > 0)
        os << name.middleName_ << " ";
    if (name.lastName_.length() > 0)
        os << name.lastName_ << " ";
    return os;
}

// function to create and return Nbame object when string inputs are given

Name* Name::CreateName(const string &fn = "", const string &mn = "", const string &ln = "")
{
    if(fn.length() == 0 && ln.length() == 0)
    {
        NameTooShort e("Bad Name Format. First Name or Last Name must be present.");
        throw e; // throws error if both first nane and last name are missing in the input
    }
    return (new Name(fn, mn, ln));
}