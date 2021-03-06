// Function to print out a string that has had it's cases swapped.
// swap_case.c
//
// This program was written by YOUR-NAME-HERE (z5165158)
// on 15/07/2021
 
#include <stdio.h>

int swap_case(int character);

int main(void) {

    // TODO: Write this function, using the swap_case function.
    int ch_stream = getchar();
    while (ch_stream != EOF) {
        ch_stream = swap_case(ch_stream);
        putchar(ch_stream);
        
        ch_stream = getchar();
    }

    return 0;
}

int swap_case(int character) {
    // TODO: Write this function, which should:
    int lower_case_startlim = 96;
    int lower_case_endlim = 123;
    int upper_case_startlim = 64;
    int upper_case_endlim = 91;
    if (character < upper_case_endlim  && character > upper_case_startlim) {
        return character + 32;
    }
    else if (character < lower_case_endlim  && character > lower_case_startlim) {
        return character - 32;
    }
    //  - return character in upper case if it is an lower case letter
    //  - return the character unchanged otherwise

    return character;
}
