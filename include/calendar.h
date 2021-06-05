#ifndef __CALENDAR_H
#define __CALENDAR_H

#include <stdbool.h>

#define NUM_MONTHS 12
#define NUM_DAYS 7

typedef struct
{
    int year; // numerical year
    int day_jan_one; // the day of the week that January 1 falls on
} calendar_t;

calendar_t* calendar_create(int year, int day_jan_one);
bool calendar_generate_csv(calendar_t* calendar, char* filename);

#endif /* __CALENDAR_H */
