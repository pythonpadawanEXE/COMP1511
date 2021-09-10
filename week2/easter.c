/* Jake Edwards (z5165158) 10/06/2021
*
* Write a program easter.c which allows the user to enter a year, then calculates the date of Easter Sunday for that year. 
https://www.drupal.org/node/1180480
*/
#include <stdio.h>

int main (void) {
    int year;
    
    printf("Enter year: ");
    scanf("%d", &year);
    
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    int Easter_Month = (h + l - 7 * m + 114) / 31; // [3=March, 4=April, etc.]
    int p = (h + l - 7 * m + 114) % 31;
    int Easter_Date = p + 1; //(date in Easter Month)
    if (Easter_Month == 3) {
        printf("Easter is March %d in %d.\n", Easter_Date, year);
    }
    else if (Easter_Month == 4) {
        printf("Easter is April %d in %d.\n", Easter_Date, year);
    }
    else {
        printf("Error!\n");
    }
    
    return 0;
}
