///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Lab_06c_Countdown - EE 205 - Spr 2022
///
/// @file countdown.c
/// @version 1.0
///
/// @author Joshua Brewer <brewerj3@hawaii.edu>
/// @date   09_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#include "countdown.h"

time_t secondsSinceReference(time_t secondsFromEpochToReference){
    time_t currentSecondsSinceEpoch = time(NULL);
    time_t diffrenceInSeconds;
    diffrenceInSeconds = difftime( currentSecondsSinceEpoch, secondsFromEpochToReference );
    return diffrenceInSeconds;
}

int main() {
    char buffer[80];
    struct tm referenceTime;

    referenceTime.tm_year = referenceYear - 1900;
    referenceTime.tm_mon = referenceMonth - 1;
    referenceTime.tm_mday = referenceDayOfMonth;
    referenceTime.tm_hour = referenceHour - hstOffset;
    referenceTime.tm_min = referenceMinute;
    referenceTime.tm_sec = referenceSecond;
    referenceTime.tm_isdst = -1;

    int secondsFromEpochToReference = mktime( &referenceTime);
    char *timeZone[4] = {"HST"};

    strftime(buffer, sizeof(buffer), "%a %b %d %X %p", &referenceTime);
    printf("Reference time: %s %s %d \n", buffer, timeZone[0], referenceYear);

    while ( true ){
        time_t diffrence = secondsSinceReference( secondsFromEpochToReference );
        int years = ( diffrence / 31557600 );
        int days = ( ( diffrence % 31557600 ) / 86400 );
        int hours = ( ( diffrence % 86400 ) / 3600 );
        int minutes = ( ( diffrence % 3600 ) / 60 );
        int seconds = ( diffrence % 60 );
        printf("Years :%d Days: %d  Hours: %d Minutes: %d   Seconds: %d \n", years, days, hours, minutes, seconds);
        sleep(1);
    }

    return 0;
}
