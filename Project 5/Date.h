#ifndef Date_h
#define Date_h

#include <iostream>

class Date  //define class Date in header file
{
public: // public functions
    Date(int month, int day);
    
    int getMonth();
    int getDay();
    
private: // private values can only be accessed with public functions
    int mMonth, mDay;
};

#endif
