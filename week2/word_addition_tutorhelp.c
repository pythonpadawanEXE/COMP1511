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
    
    char str_one_chk = 0;
    char str_two_chk = 0;
    char str_total_chk = 0;
    
    char str_one;
    char str_two;
    char str_total;
    
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
    if(num_one <= 10 && num_one >= -10){
        
        str_one_chk = 1;
        
        if (num_one == 1) {
           str_one = one;
        }
        else if (num_one == 0) {
           str_one = zero;
        }
        else if (num_one == 2) {
            str_one = two;
        }
        else if (num_one == 3) {
            str_one = three;
        }
        else if (num_one == 4) {
            str_one = four;
        }
        else if (num_one == 5) {
            str_one = five;
        }
        else if (num_one == 6) {
            str_one = six;
        }
        else if (num_one == 7) {
            str_one = seven;
        }
        else if (num_one == 8) {
            str_one = eight;
        }
        else if (num_one == 9) {
            str_one = nine;
        }
        else if (num_one == 10) {
            str_one = ten;
        }
        else if (num_one == -1) {
            str_one = n_one;
        }
        else if (num_one == -2) {
            str_one = n_two;
        }
        else if (num_one == -3) {
            str_one = n_three;
        }
        else if (num_one == -4) {
            str_one = n_four;
        }
        else if (num_one == -5) {
            str_one = n_five;
        }
        else if (num_one == -6) { 
            str_one = n_six;
        }
        else if (num_one == -7) {
            str_one = n_seven;
        }
        else if (num_one == -8) {
            str_one = n_eight; 
        }
        else if (num_one == -9) {
            str_one = n_nine;
        }
        else if (num_one == -10) {
            str_one = n_ten;
        }
    }
    
    //validate second number to find corresponding string
    
    if(num_two <= 10 && num_two >= -10){
        
        str_two_chk = 1;
        
        if (num_two == 1) {
            str_two = one;
        }
        else if (num_two == 0) {
            str_two = zero;
        }
        else if (num_two == 2) {
            str_two = two;
        }
        else if (num_two == 3) {
            str_two = three;
        }
        else if (num_two == 4) {
            str_two = four;
        }
        else if (num_two == 5) {
            str_two = five;
        }
        else if (num_two == 6) {
            str_two = six;
        }
        else if (num_two == 7) {
            str_two = seven;
        }
        else if (num_two == 8) {
            str_two = eight;
        }
        else if (num_two == 9) {
            str_two = nine;
        }
        else if (num_two == 10) {
            str_two = ten;
        }
        else if (num_two == -1) {
            str_two = n_one;
        }
        else if (num_two == -2) {
            str_two = n_two;
        }
        else if (num_two == -3) {
            str_two = n_three;
        }
        else if (num_two == -4) {
            str_two = n_four;
        }
        else if (num_two == -5) {
            str_two = n_five;
        }
        else if (num_two == -6) { 
            str_two = n_six;
        }
        else if (num_two == -7) {
            str_two = n_seven;
        }
        else if (num_two == -8) {
           str_two = n_eight; 
        }
        else if (num_two == -9) {
            str_two = n_nine;
        }
        else if (num_two == -10) {
            str_two = n_ten;
        }
    }
   
    ////validate total number to find corresponding string if applicable
    
    if(total <= 10 && total >= -10){
    
        str_total_chk = 1;
        
        if (total == 1) {
            str_total = one;
        }
        else if (total == 0) {
             str_total = zero;
        }
        else if (total == 2) {
             str_total = two;
        }
        else if (total == 3) {
             str_total = three;
        }
        else if (total == 4) {
             str_total = four;
        }
        else if (total == 5) {
             str_total = five;
        }
        else if (total == 6) {
             str_total = six;
        }
        else if (total == 7) {
             str_total = seven;
        }
        else if (total == 8) {
             str_total = eight;
        }
        else if (total == 9) {
             str_total = nine;
        }
        else if (total == 10) {
             str_total = ten;
        }
        else if (total == -1) {
             str_total = n_one;
        }
        else if (total == -2) {
             str_total = n_two;
        }
        else if (total == -3) {
             str_total = n_three;
        }
        else if (total == -4) {
             str_total = n_four;
        }
        else if (total == -5) {
             str_total = n_five;
        }
        else if (total == -6) { 
             str_total = n_six;
        }
        else if (total == -7) {
             str_total = n_seven;
        }
        else if (total == -8) {
            str_total = n_eight; 
        }
        else if (total == -9) {
             str_total = n_nine;
        }
        else if (total == -10) {
             str_total = n_ten;
        } 
    }
    
    
    if(str_total_chk != 0 && str_one_chk != 0 && str_two_chk != 0){
        printf("%s + %s = %s\n", str_one, str_two, str_total);
    }
    else if(str_total_chk == 0 && str_one_chk != 0 && str_two_chk != 0){
        printf("%s + %s = %d\n", str_one, str_two, total);
    }
    else if(str_total_chk == 0 && str_one_chk != 0 && str_two_chk == 0){
        printf("%s + %d = %d\n", str_one, num_two, total);
    }
    else if(str_total_chk == 0 && str_one_chk == 0 && str_two_chk != 0){
        printf("%d + %s = %d\n", num_one, str_two, total);
    }
    
    else if (str_total_chk == 0 && str_one_chk == 0 && str_two_chk == 0){
        printf("%d + %d = %d\n", num_one, num_two, total);
    }
    else {
        printf("AN INPUT ERROR HAS OCCURRED :(\n");
    }





    return 0;
}
