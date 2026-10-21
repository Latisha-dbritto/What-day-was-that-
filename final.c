#include <stdio.h>
#include <time.h> 

// Check if year is leap year
int is_leap_year(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Return days in a given month
int get_days_in_month(int month, int year) {
    if (month == 2) return is_leap_year(year) ? 29 : 28;
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) return 31;
    return 30;
}

// Calculate day of week (0 = Sunday, 1 = Monday, etc)
int calculate_day_of_week(int day, int month, int year){
    //Refrence date: January 1, Year 1 was a Monday (1)
    
    int total_days = 0;

    for (int y = 1; y < year; y++) {
            total_days += is_leap_year(y) ? 366 : 365;

    }

    for(int m= 1; m < month; m++){
        total_days += get_days_in_month(m, year);
    }
    total_days += day - 1;

    //Calculate day of week (January 1, Year 1 was Monday = 1)
    int day_of_week = (1+ total_days) % 7;

    return day_of_week;

}

const char* zodic_sign (int day, int month){
    if((month == 1 && day >= 20) || (month ==2 && day <=18)) return "Aquarius";
    if((month == 2 && day >= 19) || (month ==3 && day <=20)) return "Pisces";
    if((month == 3 && day >= 21) || (month ==4 && day <=19)) return "Aries";
    if((month == 4 && day >= 20) || (month ==5 && day <=20)) return "Taurus";
    if((month == 5 && day >= 21) || (month ==6 && day <=20)) return "Gemini";
    if((month == 6 && day >= 21) || (month ==7 && day <=22)) return "Cancer";
    if((month == 7 && day >= 23) || (month ==8 && day <=22)) return "Leo";
    if((month == 8 && day >= 23) || (month ==9 && day <=22)) return "Virgo";
    if((month == 9 && day >= 23) || (month ==10 && day <=22)) return "Libra";
    if((month == 10 && day >= 23) || (month ==11 && day <=21)) return "Scorpio";
    if((month == 11 && day >= 22) || (month ==12 && day <=21)) return "Sagittarius";
    return "Capricon";
}

int main() {
    int day, month, year;
    int today_day, today_month, today_year;

    
    // Welcome message
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("        WHAT DAY WAS THAT?\n");
    printf("     Your Personal Day Calculator\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Enter a date (day ,month, year):");
    if (scanf("%d %d %d", &day, &month, &year) != 3){
        printf("Invalid input! Please enter three numbers.\n");
        return 1;
    }

    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    days_in_month[1] = 29;

    if (month < 1 || month > 12 || day < 1 || day > days_in_month[month - 1]){
        printf("Invalid date entered!\n");
        return 1;
    }
    
    time_t now = time(0); 
    struct tm *today = localtime(&now);
    today_day = today->tm_mday;
    today_month = today->tm_mon + 1;
    today_year = today->tm_year + 1900;

    int status = (year < today_year) ? -1 : //For past dates
                 (year > today_year) ? +1 : //For future dates
                 (month < today_month) ? -1 :
                 (month > today_month) ? 1 :
                 (day < today_day) ? -1 :
                 (day > today_day) ? 1: 0;

    int year_diff, month_diff, day_diff;
        
    if (status == 1){
        year_diff = (year - today_year);
        month_diff = (month - today_month);
        day_diff = (day - today_day);
    } 
    else if (status == -1) {
        year_diff = (today_year - year);
        month_diff = (today_month - month);
        day_diff = (today_day - day);
    }
    else {
        year_diff = month_diff = day_diff = 0;
    }

    if (day_diff < 0){
        month_diff = month_diff -1;
        day_diff = day_diff + 31;
    }
    if (month_diff < 0){
        year_diff--;
        month_diff += 12;
    }
     
    int result = calculate_day_of_week(day, month, year);
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    printf("It was a %s\n", days[result]);

    if (is_leap_year(year)) {
        printf("%d is a Leap Year!\n", year);
    } else {
        printf("%d is Not a leap year.\n", year);
    }

    if (status == -1){
        printf("It was %d years, %d months, %d days ago\n", year_diff, month_diff, day_diff);
    } else if (status == 1) {
        printf("This day will be %d years, %d months, %d days from today\n", year_diff, month_diff, day_diff);
    } else {
        printf("That's today!\n");
    }

    printf("Zodiac Sign is %s\n", zodic_sign(day, month));
 
    
    return 0;
}
