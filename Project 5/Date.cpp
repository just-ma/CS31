#include "Date.h"

Date::Date(int month, int day) : mMonth(month), mDay(day)//define constructor
{
    if (month < 1 || month > 12) //weeds out months out of range 1 to 12
        exit(EXIT_FAILURE);
    if ((day< 1) ||(day > 31)) // weeds out days out of range 1 to 31
        exit(EXIT_FAILURE);
}

int Date::getMonth() //retrieves private value mMonth
{
    return mMonth;
}

int Date::getDay() //retrieves private value mDay
{
    return mDay;
}
