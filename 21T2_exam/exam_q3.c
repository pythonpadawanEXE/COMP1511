// exam_q3.c
//
// This program was written by z165158
// on 18/08/21
#define MAX_LENGTH 10000

#include <stdio.h>

int main(void) {
  
    int array[MAX_LENGTH] = {0};
    int c = 1;
    int iter = 0;
    while(c != 0){
        scanf("%d",&c);
        array[iter] = c;
        iter++;
    }
    int i = 0;
    while(i < iter && array[i] != 0){
        if(i % 2 == 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    i = 0;
    while(i < iter && array[i] != 0){
        if(i % 2 != 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
