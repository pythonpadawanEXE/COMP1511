// Prints the first n digits of pi, where n is specified 
// by the user z5165158 24/06/2021 Jake Edwards

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    printf("How many digits of pi would you like to print? ");
    int num_digits;
    scanf("%d", &num_digits);
    for(int i = 0; i < num_digits;i++) {
        if (i == 1) {
            printf(".%d", pi[i]);
        }
        else {
            printf("%d", pi[i]);
        }
        
    }
    
    printf("\n");
    
    return 0;
}
