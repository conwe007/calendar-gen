#include "calendar.h"
#include <stdlib.h>
#include <stdio.h>

int month_num_days[NUM_MONTHS] =
{
    31, // jan
    28, // feb
    31, // mar
    30, // apr
    31, // may
    30, // jun
    31, // jul
    31, // aug
    30, // sep
    31, // oct
    30, // nov
    31  // dec
};

const char month_name[NUM_MONTHS][4] =
{
    "jan",
    "feb",
    "mar",
    "apr",
    "may",
    "jun",
    "jul",
    "aug",
    "sep",
    "oct",
    "nov",
    "dec"
};

/**
 * Creates a calendar structure and returns a pointer to it
 * 
 * @param year the numerical year of the calendar
 * @param day_jan_one the day of the week that January 1 falls on
 * @return a pointer to the created calendar structure
 */
calendar_t* calendar_create(int year, int day_jan_one)
{
    calendar_t* calendar = (calendar_t*)malloc(sizeof(calendar_t));

    calendar->year = year;

    if(year % 4 == 0)
    {
        month_num_days[1] = 29;
    }

    calendar->day_jan_one = day_jan_one;

    return calendar;
}

/**
 * Generates the calendar based on parameters and writes the result to a csv
 * 
 * @param calendar the calendar to generate/write
 * @param filname the name of the file to write to
 * @return true if successful, false otherwise
 */
bool calendar_generate_csv(calendar_t* calendar, char* filename)
{
    int count_day = 0;
    int current_day = calendar->day_jan_one;
    int current_day_temp = 0;

    // open a file to write to
    FILE* fp = fopen(filename, "w");

    if(fp != NULL)
    {
        // print the year at the top of the file
        fprintf(fp, "%i,", calendar->year);

        // print the weekday guide
        fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,\n", "Su", "M", "Tu", "W", "Th", "F", "S");

        // print jan to begin with
        fprintf(fp, "%s,", month_name[0]);

        // loop through the empty days of the week
        while(current_day_temp < current_day)
        {
            fprintf(fp, ",");

            current_day_temp++;
        }

        for(int month = 0; month < NUM_MONTHS; month++)
        {
            count_day = 1;

            // print each day, newlining at the end of each week
            while(count_day < month_num_days[month] + 1)
            {
                fprintf(fp, "%i,", count_day);

                count_day++;

                current_day++;
                current_day = current_day % NUM_DAYS;

                // newline at the end of each week
                if(current_day == 0)
                {
                    // if the next month will begin this week, print its name
                    if((count_day + NUM_DAYS > month_num_days[month] + 1) && (month + 1 < NUM_MONTHS))
                    {
                        fprintf(fp, "\n%s,", month_name[month + 1]);
                    }
                    else
                    {
                        fprintf(fp, "\n,");
                    }
                }
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}
