//z5165158 24/06/2021 Jake Edwards 
/*For this exercise, make a program called painterbot.c which will scan in 
indices until EOF and then print out a one dimensional array which has 36 '0's, 
except at the given indices it has a '1'.

You can assume that every number you are given will be between 0 and 35. 
You can assume you will never get the same number twice. 
by the user */ 

#include <stdio.h>

#define MAX_DIGITS 36

int main(void) {
    int painter[MAX_DIGITS] = {0};
    int index = 0;
    int result = 1;
    while (1 == result) {
        result = scanf("%d", &index);
        
        if (result == 1) {
            painter[index] = 1;
        }
    }
    for(int i = 0; i < MAX_DIGITS; i++) {
        printf("%d ", painter[i]);
    }
    printf("\n");
    
    return 0;
}
