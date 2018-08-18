#include "ZodiacReader.h"

using namespace std;

ZodiacReader::ZodiacReader( Date yea) //defines constructor
    : mDate (yea) {}

ZodiacReader::Sign ZodiacReader::checkSign() //looks in ZodiacReader class to retrieve checkSign() fuction
{
    if (mDate.getMonth() == 1) // if January, check day
    {
        if ( mDate.getDay() <= 19 ) //seperates the days to their signs
            return ZodiacReader::Sign(9); //returns sign
        else
            return ZodiacReader::Sign(10);
    }
    else if (mDate.getMonth() == 2)
    {
        if ( mDate.getDay() <= 18 )
            return ZodiacReader::Sign(10);
        else
            return ZodiacReader::Sign(11);
    }
    else if (mDate.getMonth() == 3)
    {
        if ( mDate.getDay() <= 20 )
            return ZodiacReader::Sign(11);
        else
            return ZodiacReader::Sign(0);
    }
    else if (mDate.getMonth() == 4)
    {
        if ( mDate.getDay() <= 19 )
            return ZodiacReader::Sign(0);
        else
            return ZodiacReader::Sign(1);
    }
    else if (mDate.getMonth() == 5)
    {
        if ( mDate.getDay() <= 20 )
            return ZodiacReader::Sign(1);
        else
            return ZodiacReader::Sign(2);
    }
    else if (mDate.getMonth() == 6)
    {
        if ( mDate.getDay() <= 20 )
            return ZodiacReader::Sign(2);
        else
            return ZodiacReader::Sign(3);
    }
    else if (mDate.getMonth() == 7)
    {
        if ( mDate.getDay() <= 22 )
            return ZodiacReader::Sign(3);
        else
            return ZodiacReader::Sign(4);
    }
    else if (mDate.getMonth() == 8)
    {
        if ( mDate.getDay() <= 22 )
            return ZodiacReader::Sign(4);
        else
            return ZodiacReader::Sign(5);
    }
    else if (mDate.getMonth() == 9)
    {
        if ( mDate.getDay() <= 22 )
            return ZodiacReader::Sign(5);
        else
            return ZodiacReader::Sign(6);
    }
    else if (mDate.getMonth() == 10)
    {
        if ( mDate.getDay() <= 22 )
            return ZodiacReader::Sign(6);
        else
            return ZodiacReader::Sign(7);
    }
    else if (mDate.getMonth() == 11)
    {
        if ( mDate.getDay() <= 21 )
            return ZodiacReader::Sign(7);
        else
            return ZodiacReader::Sign(8);
    }
    else //last if statement is an else statement. Must be December
    {
        if ( mDate.getDay() <= 21 )
            return ZodiacReader::Sign(8);
        else
            return ZodiacReader::Sign(9);
    }
}

bool ZodiacReader::onCusp() //looks in Zodiac Reader class for onCusp() function
{
    cout.setf(ios::boolalpha); // sets output to "true" or "false"
    
    bool output;
    
    if (mDate.getDay()<3) // so day does not go below 1
        return false;
    
    if (mDate.getDay()>29) //so day does not go above 31
        return false;
    
    ZodiacReader plus2(Date(mDate.getMonth(),mDate.getDay()+2)); //creates date two days after
    ZodiacReader minus2(Date(mDate.getMonth(),mDate.getDay()-2)); //creates date two days before
    ZodiacReader original(mDate); //converts mDate to ZodiacReader
    
    if (plus2.checkSign() !=  original.checkSign() || minus2.checkSign() !=  original.checkSign()) //if mDate plus/minus two days gives a new sign, then it is on a cusp period.
    {
        output = true;
    }
    
    else output = false; //if not, it is not on cusp
    
    return output;
}

ZodiacReader::Sign ZodiacReader::cuspSign()
{
    Sign output;
    int integer = 0;
    
    if (mDate.getDay()<3) // so day does not go below 1
        return Sign(0);
    
    if (mDate.getDay()>29) //so day does not go above 31
        return Sign(0);
    
    ZodiacReader plus2(Date(mDate.getMonth(),mDate.getDay()+2));
    ZodiacReader minus2(Date(mDate.getMonth(),mDate.getDay()-2));
    ZodiacReader original(mDate);
    
    if (plus2.checkSign() != original.checkSign()) // checks if the sign changed after two days
    {
        integer = original.checkSign() + 1;
    }
    else if (minus2.checkSign() != original.checkSign()) // checks if the sign changed two days before
    {
        integer = original.checkSign() - 1;
    }
    else
        integer = 0;
    
    if (integer == -1) //if the original sign was at the edge of Sign make it loop back around
        integer = 11;
    else if (integer == 12)
        integer = 0;
    
    output = Sign(integer);
    
    return output;
}

string ZodiacReader::stringifySign( ZodiacReader::Sign sign )
{
    string output;
    
    switch (sign) //switch function that goes to the number of the sign
    {
        case 0:
            output = "Aries"; //if Sign was 0, it prints out "Aries" and so on
            break;
        case 1:
            output = "Taurus";
            break;
        case 2:
            output = "Gemini";
            break;
        case 3:
            output = "Cancer";
            break;
        case 4:
            output = "Leo";
            break;
        case 5:
            output = "Virgo";
            break;
        case 6:
            output = "Libra";
            break;
        case 7:
            output = "Scorpio";
            break;
        case 8:
            output = "Sagittarius";
            break;
        case 9:
            output = "Capricorn";
            break;
        case 10:
            output = "Aquarius";
            break;
        case 11:
            output = "Pisces";
            break;
    }
    
    return output;
}






