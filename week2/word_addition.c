/* Jake Edwards (z5165158) 9/06/2021
*
* This program should ask for two integers using the message Please enter two integers: and then display the sum of the integers as n + n = sum.

Any numbers that are between zero and ten should appear as words. This also applies to negative numbers between negative ten and zero. All other numbers should appear as decimal integers.
*
*/

#include <stdio.h>

int main (void) {
    int num_one;
    int num_two;
    int total;
    
    char one[ ] = "one";
    char two[ ] = "two";
    char three[ ] = "three";
    char four[ ] = "four";
    char five[ ] = "five";
    char six[ ] = "six";
    char seven[ ] = "seven";
    char eight[ ] = "eight";
    char nine[ ] = "nine";
    char ten[ ] = "ten";
    char zero[ ] = "zero";
    char n_one[ ] = "negative one";
    char n_two[ ] = "negative two";
    char n_three[ ] = "negative three";
    char n_four[ ] = "negative four";
    char n_five[ ] = "negative five";
    char n_six[ ] = "negative six";
    char n_seven[ ] = "negative seven";
    char n_eight[ ] = "negative eight";
    char n_nine[ ] = "negative nine";
    char n_ten[ ] = "negative ten";
    
    
    printf("Please enter two integers: ");
    scanf("%d %d", &num_one, &num_two);
    total = num_one + num_two;
    
    //validate first number to find corresponding string
    if (num_one <= 10 && num_one >= -10) {
        
        
        
        if (num_one == 1) {
            printf("%s", one);
        }
        else if (num_one == 0) {
            printf("%s", zero);
        }
        else if (num_one == 2) {
            printf("%s", two);
        }
        else if (num_one == 3) {
            printf("%s", three);
        }
        else if (num_one == 4) {
            printf("%s", four);
        }
        else if (num_one == 5) {
            printf("%s", five);
        }
        else if (num_one == 6) {
            printf("%s", six);
        }
        else if (num_one == 7) {
            printf("%s", seven);
        }
        else if (num_one == 8) {
            printf("%s", eight);
        }
        else if (num_one == 9) {
            printf("%s", nine);
        }
        else if (num_one == 10) {
            printf("%s", ten);
        }
        else if (num_one == -1) {
            printf("%s", n_one);
        }
        else if (num_one == -2) {
            printf("%s", n_two);
        }
        else if (num_one == -3) {
            printf("%s", n_three);
        }
        else if (num_one == -4) {
            printf("%s", n_four);
        }
        else if (num_one == -5) {
            printf("%s", n_five);
        }
        else if (num_one == -6) { 
            printf("%s", n_six);
        }
        else if (num_one == -7) {
            printf("%s", n_seven);
        }
        else if (num_one == -8) {
            printf("%s", n_eight); 
        }
        else if (num_one == -9) {
            printf("%s", n_nine);
        }
        else if (num_one == -10) {
            printf("%s", n_ten);
        }
    }
    else {
        printf("%d", num_one);
    }    
    printf(" + ");
    //validate second number to find corresponding string
    if (num_two <= 10 && num_two >= -10) {
    
        if (num_two == 1) {
            printf("%s", one);
        }
        else if (num_two == 0) {
            printf("%s", zero);
        }
        else if (num_two == 2) {
            printf("%s", two);
        }
        else if (num_two == 3) {
            printf("%s", three);
        }
        else if (num_two == 4) {
            printf("%s", four);
        }
        else if (num_two == 5) {
            printf("%s", five);
        }
        else if (num_two == 6) {
            printf("%s", six);
        }
        else if (num_two == 7) {
            printf("%s", seven);
        }
        else if (num_two == 8) {
            printf("%s", eight);
        }
        else if (num_two == 9) {
            printf("%s", nine);
        }
        else if (num_two == 10) {
            printf("%s", ten);
        }
        else if (num_two == -1) {
            printf("%s", n_one);
        }
        else if (num_two == -2) {
            printf("%s", n_two);
        }
        else if (num_two == -3) {
            printf("%s", n_three);
        }
        else if (num_two == -4) {
            printf("%s", n_four);
        }
        else if (num_two == -5) {
            printf("%s", n_five);
        }
        else if (num_two == -6) { 
            printf("%s", n_six);
        }
        else if (num_two == -7) {
            printf("%s", n_seven);
        }
        else if (num_two == -8) {
            printf("%s", n_eight); 
        }
        else if (num_two == -9) {
            printf("%s", n_nine);
        }
        else if (num_two == -10) {
            printf("%s", n_ten);
        }
    }
    else {
        printf("%d", num_two);
    }    
    printf(" = ");
    ////validate total number to find corresponding string if applicable
    if (total <= 10 && total >= -10) {
        if (total == 1) {
            printf("%s", one);
        }
        else if (total == 0) {
            printf("%s", zero);
        }
        else if (total == 2) {
            printf("%s", two);
        }
        else if (total == 3) {
            printf("%s", three);
        }
        else if (total == 4) {
            printf("%s", four);
        }
        else if (total == 5) {
            printf("%s", five);
        }
        else if (total == 6) {
            printf("%s", six);
        }
        else if (total == 7) {
            printf("%s", seven);
        }
        else if (total == 8) {
            printf("%s", eight);
        }
        else if (total == 9) {
            printf("%s", nine);
        }
        else if (total == 10) {
            printf("%s", ten);
        }
        else if (total == -1) {
            printf("%s", n_one);
        }
        else if (total == -2) {
            printf("%s", n_two);
        }
        else if (total == -3) {
            printf("%s", n_three);
        }
        else if (total == -4) {
            printf("%s", n_four);
        }
        else if (total == -5) {
            printf("%s", n_five);
        }
        else if (total == -6) { 
            printf("%s", n_six);
        }
        else if (total == -7) {
            printf("%s", n_seven);
        }
        else if (total == -8) {
            printf("%s", n_eight); 
        }
        else if (total == -9) {
            printf("%s", n_nine);
        }
        else if (total == -10) {
            printf("%s", n_ten);
        }
    }
    else {
        printf("%d", total);
    }
    printf("\n");    





    return 0;
}
