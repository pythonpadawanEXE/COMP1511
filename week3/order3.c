/* Jake Edwards z5165158 17/06/2021
*
*Write a C program order3.c using if statements (no loops) that reads 3 integers and prints them from smallest to largest.
*
*/

#include <stdio.h>
void swap(int *var_one, int *var_two);

int main(void){

    int int_one;
    int int_two;
    int int_three;

    printf("Enter integer:");
    scanf("%d", &int_one);

    printf("Enter integer:");
    scanf("%d", &int_two);

    printf("Enter integer:");
    scanf("%d", &int_three);



    if (int_one >= int_three) {
        swap(&int_one, &int_three);
    }
    if (int_one >= int_two) {
        swap(&int_one, &int_two);
    }
    if (int_two >= int_three) {
        swap(&int_two, &int_three);
    }

    printf("The integers in order are: %d %d %d\n", int_one, int_two, int_three);

    return 0;
}

/*  
    SWAP FUNCTION
----------------------------------
    parse addresses of two variables to pointer variables and swap addresses
*/
void swap(int *var_one, int *var_two) { 
    int tmp;
    tmp = *var_one; //create temporary pointer variable
    *var_one = *var_two; //rewrite pointer to new address
    *var_two = tmp; //rewrite pointer to new address to complete swap of addresses
}
