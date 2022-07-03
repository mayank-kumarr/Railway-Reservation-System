/*
    Mayank Kumar
    19CS30029
    Date.cpp
*/

// Project Headers
#include "Date.h"
#include "Exception.h"

const vector<string> Date::sDayNames = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; // days of week
const vector<string> Date::sMonthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; // months of year

// Constructor
Date::Date(int d, int m, int y) : date_(d), month_(Month(m)), year_(y)
{
    #if _DEBUG
        cout << "Date Created\n";
    #endif // _DEBUG
    day_ = this->GetDay();
}

// Copy Constructor
Date::Date(const Date &d) : date_(d.date_), month_(d.month_), year_(d.year_), day_(d.day_)
{

}

// Destructor
Date::~Date()
{
    #if _DEBUG
        cout << "Date Destroyed\n";
    #endif // _DEBUG
}

// Function that gets day of the week when date is given
Day Date::GetDay() const
{
    struct tm curr = {0, 0, 0, date_, month_-1, year_-1900};
    time_t rawtime = mktime(&curr);
    return static_cast<Day>(localtime(&rawtime)->tm_wday);
}

// Function to find no. of days between two dates
int Date::subtract(const Date& date1, const Date& date2)
{
    int i, d1, d2, dy, lc, diff;
    d1 = d2 = lc = 0;

    for(i=1; i<date1.month_; i++)
    {
        if(i==1 ||i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
            d1+=31;
        else if(i==2)
            d1+=28;
        else
            d1+=30;
    }

    d1 += date1.date_;

    for(i=1; i<date2.month_; i++)
    {
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
            d2+=31;
        else if(i==2)
            d2+=28;
        else
            d2+=30;
    }

    d2+=date2.date_;
 
    dy=(date1.year_-date2.year_)*365;

    for(i=date2.year_; i<date1.year_; i++)
        if((i%4)==0)
            lc++;
 
    int y4 = date1.year_-date2.year_;
    
    while(y4>400)
    {
        lc++;
        y4-=400;
    }
    
    if((date1.month_>2) && (date1.year_%4)==0)
        lc++;
    
    if((date2.month_>2) && (date2.year_%4)==0)
        lc--;
    
    diff = dy+d1-d2+lc;
    
    return diff;
}

// Function that returns Today's date
Date Date::Today()
{
    time_t rawtime;
    time(&rawtime);
    struct tm *curr = localtime(&rawtime);
    Date date(curr->tm_mday, curr->tm_mon+1, curr->tm_year+1900);
    return date;
}

// Function that uses no. of days to calculate age
int Date::Age(const Date &d)
{
    return (subtract(Date::Today(), d) /365);
}

// Creating Date object when string is given
// All scenarios were kept in mind while creating object
Date* Date::CreateDate(const string& st)
{
    if (st.length()!=10 || st[2]!='/' || st[5]!='/')
    {
        BadDateFormat e("Invalid Date Format. Must be DD/MM/YYYY in " + st);
        throw e;
    }
    int pos1 = 0, pos2 = st.find('/');
    string date = st.substr(0, pos2-pos1);
    pos1 = pos2+1;
    pos2 = st.find('/', pos1);
    string month = st.substr(pos1, pos2-pos1);
    pos1 = pos2+1;
    string year = st.substr(pos1);
    int i;
    
    for(i=0; i<date.length(); i++)
        if(date[i]<'0' || date[i]>'9')
            {
                BadDateFormat e("Invalid Date Format. DD in DD/MM/YYYY must be a number in " + st);
                throw e;
            }
    
    for(i=0; i<month.length(); i++)
        if(month[i]<'0' || month[i]>'9')
            {
                BadDateFormat e("Invalid Date Format. MM in DD/MM/YYYY must be a number in " + st);
                throw e;
            }
    
    for(i=0; i<year.length(); i++)
        if(year[i]<'0' || year[i]>'9')
            {
                BadDateFormat e("Invalid Date Format. YYYY in DD/MM/YYYY must be a number in " + st);
                throw e;
            }

    int dd = stoi(date);
    int mm = stoi(month);
    int yy = stoi(year);

    if((mm==2) && (dd>29))
    {
        InvalidDate e("Invalid Date. DD out of range for MM in DD/MM/YYYY in " + st);
        throw e;
    }
    
    if(mm>12)
    {
        InvalidDate e("Invalid Date. MM out of range in DD/MM/YYYY in " + st);
        throw e;
    }
    if(dd>31)
    {
        InvalidDate e("Invalid Date. DD out of range in DD/MM/YYYY in " + st);
        throw e;
    }
    if((mm==4||mm==6||mm==9||mm==11) && (dd>30))
    {
        InvalidDate e("Invalid Date. DD out of range for MM in DD/MM/YYYY in " + st);
        throw e;
    }
    
    if((yy%4)!=0 && (mm==2) && (dd>28))
    {
        InvalidDate e("Invalid Date. DD out of range for MM in DD/MM/YYYY in " + st);
        throw e;
    }

    if(yy<1900 || yy>2099)
    {
        InvalidDate e("Date Out Of Bound. " + st + " must be between 1900 and 2099.");
        throw e;
    }

    return (new Date(dd, mm, yy));
}

// Output Stream Operator
ostream &operator<<(ostream &os, const Date &date)
{
    os << Date::sDayNames[date.day_] << ", " << date.date_ << "/" << Date::sMonthNames[static_cast<int>(date.month_) - 1] << "/" << date.year_;
    return os;
}