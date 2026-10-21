# What-day-was-that-

Project Description
The "What Day Was That?" project is a comprehensive date calculator program written in C that determines the day of the week for any given date. The program goes beyond basic day calculation by providing additional features such as leap year detection, zodiac sign determination, and time difference calculations from the current date. This interactive console application serves as a personal day calculator that can handle both historical and future dates with accuracy.

------------------------------------------------------------------------------------------------------------------

List of Modules
 1. Leap Year Detection Module (`is_leap_year` function)
This module implements the standard leap year algorithm to determine if a given year is a leap year. It correctly handles the Gregorian calendar rules: years divisible by 4 are leap years, except for century years which must be divisible by 400.

 2. Days in Month Calculator (`get_days_in_month` function)
This module calculates the number of days in any given month for a specific year. It accounts for leap years when determining February's length and correctly assigns 30 or 31 days to other months based on the standard calendar.

 3. Day of Week Calculator (`calculate_day_of_week` function)
The core module that calculates which day of the week a given date falls on. It uses January 1, Year 1 as a reference point (Monday) and counts total days elapsed to determine the day of the week using modular arithmetic.

 4. Zodiac Sign Determination (`zodic_sign` function)
This module determines the astrological zodiac sign based on the input date. It implements the traditional zodiac date ranges for all twelve signs from Aquarius to Capricorn.

5. Date Validation and Input Processing Module
Handles user input validation, ensuring that entered dates are valid according to calendar rules. It checks for proper month ranges (1-12), appropriate day ranges for each month, and handles leap year considerations.

6. Time Difference Calculator
Calculates the difference between the input date and the current system date, determining whether the date is in the past, present, or future, and providing the exact time difference in years, months, and days.

----------------------------------------------------------------------------------------------------------------------------------------------

Technologies Used
- Programming Language: C (Standard C99/C11)
- Standard Libraries
  - ‘stdio.h’ (version depends on compiler) - for input/output operations
  - ‘time.h’ (version depends on compiler) - for current date/time functionality
- Development Environment Compatible with GCC, Clang, or any standard C compiler
- Platform: Cross-platform (Windows, Linux, macOS)
