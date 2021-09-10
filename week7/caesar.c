// Function to create a casesar cipher
// 
//
// This program was written by Jake Edwards (z5165158)
// on 15/07/2021
 
#include <stdio.h>
#include <stdlib.h>

int caesar_shift(int input,int shift);

int main(int argc, char *argv[]) {
    
    int ch_stream = getchar();
    while (ch_stream != EOF) {
        ch_stream = caesar_shift(ch_stream, atoi(argv[1]));
        putchar(ch_stream);
        
        ch_stream = getchar();
    }
    return 0;
}

int caesar_shift(int input, int shift) {
    int lower_case_startlim = 96;
    int lower_case_endlim = 123;
    int upper_case_startlim = 64;
    int upper_case_endlim = 91;
    int alphabet_len = 26;
    //make mod like python
    shift = ((shift % alphabet_len) + alphabet_len) % alphabet_len; 
    int pos;
    if (input < upper_case_endlim && input > upper_case_startlim ) {
        pos = (input + shift - (upper_case_startlim + 1));
        return pos %  alphabet_len + upper_case_startlim + 1;
    }
    else if (input < lower_case_endlim && input > lower_case_startlim ) {
        pos = (input + shift - (lower_case_startlim + 1));
        return pos %  alphabet_len + lower_case_startlim + 1;
    }
    else {
        return input;
    }
}
