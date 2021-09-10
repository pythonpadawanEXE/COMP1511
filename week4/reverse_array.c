//z5165158 24/06/2021 Jake Edwards 
/* Write a C program, reverse_array.c, which reads integers line by line, and when it reaches the end of input, prints those integers in reverse order, line by line.

You will never be given more than 100 integers to print out.

The output from your program should look exactly like this: */ 

#include <stdio.h>

#define MAX_NUM 100
int square(int num1);
int powers(int num1, int num2);
int main(void) {
    int array[MAX_NUM] = {0};
    int result = 1;
    int index = -1;
    printf("Enter numbers forwards:\n");
    while (1 == result) {
        index ++;
        result = scanf("%d", &array[index]);
        
    }
    index = index - 1;
    printf("Reversed:\n");
    while (index >= 0) {
        printf("%d\n", array[index]);
        index = index-1; 
    }     
   
    return 0;
}
    
