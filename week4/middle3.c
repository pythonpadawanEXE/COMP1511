//z5165158 Jake Edwards 26/06/2021
//Write a C program middle3.c that reads 3 integers and prints the middle 
//integer. 
#include <stdio.h>

int main(void){
    int num_one;
    int num_two;
    int num_three;
    int tmp;
    
    printf("Enter integer: ");
    scanf("%d", &num_one);
    printf("Enter integer: ");
    scanf("%d", &num_two);
    printf("Enter integer: ");
    scanf("%d", &num_three);
    
    if (num_one > num_three) {
        tmp = num_one;
        num_one = num_three;
        num_three = tmp;
    }
    
    if (num_one > num_two) {
        tmp = num_one;
        num_one = num_two;
        num_two = tmp;
    }

    if (num_two > num_three) {
        tmp = num_two;
        num_two = num_three;
        num_three = tmp;
    }
    
    printf("Middle: %d\n", num_two);




    return 0;
}
