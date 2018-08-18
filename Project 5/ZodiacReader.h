#ifndef ZodiacReader_h
#define ZodiacReader_h
#include "Date.h"

class ZodiacReader //creates class ZodiacReader in header file
{
public: //public functions
    ZodiacReader(Date date); //constructor
    
    enum Sign{ ARIES, TAURUS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SCORPIO, SAGITTARIUS, CAPRICORN, AQUARIUS, PISCES};
    
    ZodiacReader::Sign checkSign(), cuspSign();
    
    bool onCusp();
    
    std::string stringifySign( ZodiacReader::Sign sign);
    
private: //private values stored here
    Date mDate;
};

#endif
