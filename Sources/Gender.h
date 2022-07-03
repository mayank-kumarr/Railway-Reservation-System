/*
    Mayank Kumar
    19CS30029
    Gender.h
*/

#ifndef __GENDER_H // Control inclusion of header files
#define __GENDER_H

// C++ Headers
#include <string>
#include <iostream>
using namespace std;

// Template for Male and Female
template <typename T>
class GenderType;

// Declaration for class Gender
class Gender
{
private:
    struct MaleType {}; // for gender Male
    struct FemaleType {}; // for gender Female
    const string name_; // to store name of gender

protected:
    // constructor
    Gender(const string &name) : name_(name)
    {

    };
    // destructor, v
    // irtual since class is inherited by GenderType
    virtual ~Gender()
    {

    };

public:
    typedef GenderType<MaleType> Male; // typedef for Male type
    typedef GenderType<FemaleType> Female; // typedef for Female type
    const string &GetName() const // return sname of the gender
    {
        return name_;
    };
    static bool isMale(const Gender &); // returns true for Male and false for female
    virtual const string &GetTitle() const = 0; // returns title for the gender
    static void UnitTestGender(); // for unit testing Gender class
    friend ostream& operator<<(ostream&, Gender&);
};

// declaration for GenderType class
template <typename T>
class GenderType : public Gender
{
private:
    static const string sName; // to store name of the gender
    static const string sSalutation; // to store salutation Mr. for Male and Ms. for Female
    // constructor
    GenderType(const string &name = GenderType<T>::sName) : Gender(name)
    {

    };
    // destructor
    ~GenderType()
    {

    };
public:
    // type function for singleton-ness
    static const GenderType<T> &Type()
    {
        static const GenderType<T> instance;
        return instance;
    }

    // returns title for the Gender
    const string &GetTitle() const
    {
        return sSalutation;
    };
};

// inline function that returs true is the gender is Male
inline bool Gender :: isMale(const Gender &gender)
{
    if(&gender == &Male::Type())
        return true;
    else
        return false;
}

#endif // __GENDER_H