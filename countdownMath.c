///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Lab_06c_Countdown - EE 205 - Spr 2022
///
/// @file countdownMath.c
/// @version 1.0
///
/// @author Joshua Brewer <brewerj3@hawaii.edu>
/// @date   09_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <time.h>

#include "countdownMath.h"

long secondsSinceReference( long secondsFromEpochToReference){
    long currentSecondsSinceEpoch = time(NULL);
    long differenceInSeconds;
    differenceInSeconds = ( currentSecondsSinceEpoch - secondsFromEpochToReference );
    return differenceInSeconds;
}

long getDifferenceInYears( long difference) {
    return ( difference / 31557600 );
}
long getDifferenceInDays( long difference ) {
    return ( ( difference % 31557600 ) / 86400 );
}
long getDifferenceInHours( long difference ) {
    return ( ( difference % 86400 ) / 3600 );
}
long getDifferenceInMinutes( long difference ) {
    return ( ( difference % 3600 ) / 60 );
}
long getDifferenceInSeconds( long difference ) {
    return ( difference % 60 );
}