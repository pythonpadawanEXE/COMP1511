/* Jake Edwards (z5165158) 9/06/2021
*
* Make a program called number_words.c.

This program will ask for a number with the message Please enter an integer: .

For numbers between 1 and 5, display the number as a word in the message You entered number.

For numbers less than 1, display the message You entered a number less than one.

For numbers greater than 5, display the message You entered a number greater than five.
*
*/

#include <stdio.h>

int main (void) {
    char five[ ] = "five";
    char four[ ] = "four";
    char three[ ] = "three";
    char two[ ] = "two";
    char one[ ] = "one";
    int num;
    
    printf("Please enter an integer:");
    scanf("%d", &num);
    if ((num <= 5) && (num >= 1)) {
        if (num == 1) { 
            printf("You entered %s.\n", one);
        }
        if (num == 2) { 
            printf("You entered %s.\n", two);
        }
        if (num == 3) { 
            printf("You entered %s.\n", three);
        }
        if (num == 4) { 
            printf("You entered %s.\n", four);
        }
        if (num == 5) { 
            printf("You entered %s.\n", five);
        }
    }    
    else if (num > 5) {
        printf("You entered a number greater than five.\n");
    }
    else {
        printf("You entered a number less than one.\n");
    }        



    return 0;
}
