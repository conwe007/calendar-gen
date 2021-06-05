# Calendar Generator
### John Conwell - June 2021

This program generates a csv file representing a calendar for a given year. It takes two arguments: year and day_jan_one.

`year: the numerical calendar year`

`day_jan_one: the day of the week that January 1st falls on (0-6, where 0 corresponds to Sunday)`

This program automatidally accounts for leap year based on the supplied year argument. This program relies on correct input arguments to generate a correct output calendar.

### To Compile:

`make`

### To Run:

`./main year day_jan_one`