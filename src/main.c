#include "calendar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_FILENAME 1024

// run with ./main arg1 arg2
// arg1: numerical year
// arg2: day of the week that Jan 1 falls on
//     Sunday: 0
//     Monday: 1
//     Tuesday: 2
//     Wednesday: 3
//     Thursday: 4
//     Friday: 5
//     Saturday: 6

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        fprintf(stderr, "error: wrong number of args\n");
        return EXIT_FAILURE;
    }

    int year = atoi(argv[1]);
    int day_jan_one = atoi(argv[2]);

    if(day_jan_one < 0 || day_jan_one > 6)
    {
        fprintf(stderr, "error: unacceptable day of the week\n");
        return EXIT_FAILURE;
    }

    char filename[SIZE_FILENAME];
    snprintf(filename, SIZE_FILENAME, "calendar_%i.csv", year);
    
    calendar_t* calendar = calendar_create(year, day_jan_one);
    calendar_generate_csv(calendar, filename);

    return 0;
}
