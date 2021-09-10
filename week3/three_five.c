/* Jake Edwards z5165158 17/06/2021
*
*Write a program three_five.c that reads a positive integer n and print all the positive integers < n divisible by 3 or 5. All of the numbers printed should be in ascending order.
*
*/
#include <stdio.h>

int main(void) {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    
    //initialise counter
    int counter = 1;
    
    //print number if divisble by 5 or 3 in ascending order 
    while (counter < num) {
        
        if (counter % 5 == 0 || counter % 3 == 0) {
            printf("%d\n", counter);
        }
        counter = counter + 1;
    }

    return 0;
}
