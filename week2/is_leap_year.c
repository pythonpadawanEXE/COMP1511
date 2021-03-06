/* Jake Edwards (z5165158) 9/06/2021
*
*Write a C program is_leap_year.c that reads a year and then prints whether that year is a leap year
Using this algorithm  https://en.wikipedia.org/wiki/Leap_year#Algorithm
*/

#include <stdio.h>

int main (void) {
    int year;
    
    printf("Enter year: ");
    scanf("%d", &year);
    // where does the newline character exist between printf and scanf
    if (year % 4 != 0) {
        printf("%d is not a leap year.\n", year);
    }
    else if (year % 100 != 0) {
        printf("%d is a leap year.\n", year);
    }
    else if (year % 400 != 0) {
        printf("%d is not a leap year.\n", year);
    }
    else {
        printf("%d is a leap year.\n", year);
    }


    return 0;
}
