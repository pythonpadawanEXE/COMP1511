/* Jake Edwards z5165158 17/06/2021
*
*Write a program perfect.c that reads a positive integer n from standard input and prints all the factors of n, their sum and indicates whether n is a perfect number.
*
*/
#include <stdio.h>

int main(void) {
    int num;
    int sum = 0;
    int count = 1;
    
    printf("Enter number: ");
    scanf("%d", &num);
    printf("The factors of %d are:\n", num);
    /*
    While loop to check divisibility of numbers from 1-number and sum factors
    */
    
    while (count <= num) {
        if (num % count == 0) {
            printf("%d\n", count);
            sum = sum + count;
        }
        count = count + 1;
    }
    printf("Sum of factors = %d\n", sum);
    if (num + num == sum) {
        printf("%d is a perfect number\n", num);
    }
    else {
        printf("%d is not a perfect number\n", num);
    }
    return 0;
}
