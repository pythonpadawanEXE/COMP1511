/* JAKE E (z5165158) 9/06/2021
*Write a program that uses scanf to get a number from a user 
and prints "Don't be so negative!" if they entered a negative number.
If the number is positive, the program should print 
"You have entered a positive number."
If the user enters the number 0, the program should print 
"You have entered zero."
Note: you can assume that the number will always be a whole number 
(i.e. an integer)
*/
#include <stdio.h>


int main(void){
    int num;
    //printf("Enter a Number:\n");
    scanf("%d", &num);
    if (num == 0) {
        printf("You have entered zero.\n");
    }
    else if (num > 0) {
        printf("You have entered a positive number.\n");
    }   
    else {
        printf("Don't be so negative!\n");
    }



    return 0;
}
