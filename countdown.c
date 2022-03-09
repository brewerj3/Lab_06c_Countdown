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

time_t secondsSinceRefrence(time_t secondsFromEpochToRefrence){
    time_t currentSecondsSinceEpoch = time(NULL);
    time_t diffrenceInSeconds;
    diffrenceInSeconds = difftime( currentSecondsSinceEpoch, secondsFromEpochToRefrence );
    return diffrenceInSeconds;
}

int main() {
    char buffer[80];
    struct tm refrenceTime;

    refrenceTime.tm_year = refrenceYear-1900;
    refrenceTime.tm_mon = refrenceMonth - 1;
    refrenceTime.tm_mday = refrenceDayOfMonth;
    refrenceTime.tm_hour = refrenceHour - hstOffset;
    refrenceTime.tm_min = refrenceMinute;
    refrenceTime.tm_sec = refrenceSecond;
    refrenceTime.tm_isdst = -1;

    int secondsFromEpochToRefrence = mktime( &refrenceTime);
    char *timeZone[4] = {"HST"};

    strftime(buffer, sizeof(buffer), "%a %b %d %X %p", &refrenceTime);
    printf("Refrence time: %s %s %d \n", buffer, timeZone[0], refrenceYear);

    while ( true ){
        time_t diffrence = secondsSinceRefrence( secondsFromEpochToRefrence );
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
