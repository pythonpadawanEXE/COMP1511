#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int main(void){

    int array1[] = {1,2,3,4,5,6,7,8,9,0};
    int array2[SIZE] = {1,2,3,4,5,6,7,8,9,0};
    char *str1 = "abcdefghi";
    char str2[SIZE] = {'a','b','c','d','e','f','g','h','i','\0'};
    printf("%d %d\n", array1[0], array2[0]);
    printf("%c %c\n", str1[8], str2[8]);
    
    





    return 0;
}
