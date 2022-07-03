/*
    Mayank Kumar
    19CS30029
*/

// Project Headers
#include "UnitTestName.h"

// Functuon body for unit testing Name class
void Name::UnitTestName()
{
    Name* name = NULL;

    // positive test case

    try
    {
        name = Name::CreateName("Mayank", "Kumar", "Baranwal");
    }
    catch(BadName& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert("Mayank"==name->firstName_ && "Kumar"==name->middleName_ && "Baranwal"==name->lastName_);

    // positive test case

    try
    {
        name = Name::CreateName("Mayank", "", "Kumar");
    }
    catch(BadName& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert("Mayank"==name->firstName_ && ""==name->middleName_ && "Kumar"==name->lastName_);

    // positive test case

    try
    {
        name = Name::CreateName("Mayank", "Kumar", "");
    }
    catch(BadName& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert("Mayank"==name->firstName_ && "Kumar"==name->middleName_ && ""==name->lastName_);

    // positive test case

    try
    {
        name = Name::CreateName("", "Kumar", "Baranwal");
    }
    catch(BadName& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(""==name->firstName_ && "Kumar"==name->middleName_ && "Baranwal"==name->lastName_);

    // positive test case

    try
    {
        name = Name::CreateName("", "", "Baranwal");
    }
    catch(BadName& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(""==name->firstName_ && ""==name->middleName_ && "Baranwal"==name->lastName_);

    // negative test case, all field are absent

    try
    {
        name = Name::CreateName("", "", "");
    }
    catch(BadName& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(""==name->firstName_ && ""==name->middleName_ && "Baranwal"==name->lastName_);

    // negative test case, both first name and last name is absent

    try
    {
        name = Name::CreateName("", "Kumar", "");
    }
    catch(BadName& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    assert(""==name->firstName_ && ""==name->middleName_ && "Baranwal"==name->lastName_);

    // positive test case

    Name* name2 = NULL;
    try
    {
        name2 = Name::CreateName("Mayank", "Kumar", "Baranwal");
    }
    catch(BadName& e)
    {
        cerr << e.what() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }

    // Testing the overloaded output stream operator <<

    stringstream expOut, out; // Creating the stringstream objects
    out << *name2; // Writing the Name object 'name2' to stringstream object 'out'
    
    ifstream log("GoldenUnitTestName.log");
    if(log)
    {
       expOut << log.rdbuf(); // Writing the expected output of Name object 'name2' to stringstream object 'out'
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
    Name::UnitTestName();
    return 0;
}