// Function to print out a string from arv to lower case
// 
//
// This program was written by YOUR-NAME-HERE (z5165158)
// on 15/07/2021
 
#include <stdio.h>
#include <string.h>

void lower_arg(char string[]);

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        lower_arg(argv[i]);
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}

void lower_arg(char string[]) {

    int upper_case_startlim = 64;
    int upper_case_endlim = 91;

    
    for(int i = 0; i < strlen(string); i++) {
        if (string[i] < upper_case_endlim  && string[i] > upper_case_startlim) {
            string[i] = string[i] + 32;
        }
       
    }
}
