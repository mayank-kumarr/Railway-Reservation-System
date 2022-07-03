/*
    Mayank Kumar
    19CS30029
*/

// Project headers
#include "Passenger.h"
#include "BookingCategory.h"
#include "Exception.h"

// constructor
Passenger::Passenger(const Name &name, const Date &date, const Gender &gender, const string &aadhaar, const string &mobile, 
                    const Divyaang &disability, const string &disabilityID) : name_(name),dob_(date), gender_(gender),
                    aadhaar_(aadhaar), mobile_(mobile), disability_(disability), disabilityID_(disabilityID)
{
    #if _DEBUG
        cout << "Passenger Created" << endl;
    #endif  // _DEBUG
}

// destructor
Passenger::~Passenger()
{
    #if _DEBUG
        cout << "Passenger Destroyed" << endl;
    #endif  // _DEBUG
}

// returns date of birth
const Date &Passenger::GetDOB() const
{
    return dob_;
}

// returns gender
const Gender &Passenger::GetGender() const
{
    return gender_;
}

// returns disability
const Divyaang &Passenger::GetDisability() const
{
    return disability_;
}

// output stream operator
ostream &operator<<(ostream &os, const Passenger &p)
{
    os << "Name: " << p.gender_.GetTitle() << " " << p.name_ << endl;
    os << "Date of Birth: " << p.dob_ << endl;
    os << "Gender: " << p.gender_.GetName() << endl;
    os << "Aadhaar: " << p.aadhaar_ << endl;
    if (p.mobile_ != "")
    {
        os << "Mobile: " << p.mobile_ << endl;
    }
    if ((p.disability_).GetName() != "None")
    {
        os << "Disability: " << (p.disability_).GetName() << endl;
        os << "Disability ID: " << p.disabilityID_ << endl;
    }
    return os;
}

// Function to create and return Passenger object when string inputs are given
Passenger* Passenger::CreatePassenger(const string &n1, const string &n2, const string &n3, const string &dob, const Gender &gender, const string &aadhaar,
                                      const string &mobile, const Divyaang &disability, const string &disabilityID)

{
    // checking if name is valid
    Name *name = NULL;
    int flag = 0;
    try
    {
        name = Name::CreateName(n1, n2, n3);
    }
    catch(BadName &e)
    {
        flag = 1;
        cerr << e.what() << endl;
    }
    catch(exception &e)
    {
        flag = 1;
        cerr << e.what() << endl;
    }

    // checking if date of birth is valid
    Date *date = NULL;
    try
    {
        date = Date::CreateDate(dob);
        int diff = Date::subtract(Date::Today(), *date);
        if(diff<0)
        {
            DOBTooLate e("Date of Birth " + dob + " cannot be from future");
            throw e; // throws error if age is found to be negative
        }
    }
    catch(BadDate &e)
    {
        flag = 1;
        cerr << e.what() << endl;
    }
    catch(exception &e)
    {
        flag = 1;
        cerr << e.what() << endl;
    }

    // checking if aadhaar is valid
    try
    {
        if (aadhaar.length() != 12)
        {
            BadAadhaar e("Aadhar must be of 12 digits");
            throw e; // throws error if aadhaar is not of 12 digits
        }
        for(int i=0; i<aadhaar.length(); i++)
        {
            if(aadhaar[i] < '0' || aadhaar[i] > '9')
            {
                BadAadhaar e("Aadhar must contain digits from 0-9 only");
                throw e; // throws error if any character other than 0-9 is present
            }
        }
    }
    catch(BadAadhaar &e)
    {
        flag = 1;
        cerr << e.what() << endl;
    }
    catch(const exception &e)
    {
        flag = 1;
        cerr << e.what() << endl;
    }

    // checking if mobile no. is valid
    try
    {
        if (mobile.length() != 10)
        {
            BadMobile e("Mobile no. must be of 10 digits");
            throw e; // throws error if mobile no. of not of 10 digits
        }
        for(int i=0; i<mobile.length(); i++)
        {
            if(mobile[i] < '0' || mobile[i] > '9')
            {
                BadMobile e("Mobile no. must contain digits from 0-9 only");
                throw e; // throws error if mobile no. has any character other than 0-9
            }
        }
    }
    catch(BadMobile &e)
    {
        flag = 1;
        std::cerr << e.what() << endl;
    }
    catch(const exception &e)
    {
        flag = 1;
        std::cerr << e.what() << endl;
    }

    // checking if disabilityID is given only when disability is not None
    try
    {
        if("None" != disability.GetName() && disabilityID.length()==0)
        {
            BadPassenger e("ID is required when Divyaang Category is not None.");
            throw e;
        }
        if("None" == disability.GetName() && disabilityID.length()!=0)
        {
            BadPassenger e("ID is not required when Divyaang Category is None.");
            throw e;
        }
    }
    catch(BadPassenger &e)
    {
        flag = 1;
        cerr << e.what() << endl;
    }
    catch(exception &e)
    {
        flag = 1;
        cerr << e.what() << endl;
    }

    if(flag)
    {
        BadPassenger e("Invalid Passenger Information");
        throw e; // throws error if something goes wrong
    }

    Passenger *p = new Passenger(*name, *date, gender, aadhaar, mobile, disability, disabilityID);
    return p;
}