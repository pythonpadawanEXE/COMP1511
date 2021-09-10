// Function to create a casesar cipher
// 
//
// This program was written by Jake Edwards (z5165158)
// on 15/07/2021
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int decode(int input1,int input2);

int main(int argc, char *argv[]) {

    int result;
    
    int ch_stream1 = getchar();
    int ch_stream2 = getchar();
    while (ch_stream1 != EOF && ch_stream2 != EOF) {
        
        result = decode(ch_stream1, ch_stream2);
        putchar(result);
        
        ch_stream1 = getchar();
        ch_stream2 = getchar();
    }
    printf("\n");
    return 0;
}

int decode(int input1, int input2) {
    
    if (input1 > input2) {
        return input2;
    }
    return input1;
    
        
    
    
    
}
