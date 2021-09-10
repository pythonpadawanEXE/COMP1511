// Function to create a casesar cipher
// 
//
// This program was written by Jake Edwards (z5165158)
// on 15/07/2021
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int substitution(int input,char *identity);

int main(int argc, char *argv[]) {


    
    int ch_stream = getchar();
    while (ch_stream != EOF) {
        ch_stream = substitution(ch_stream, argv[1]);
        putchar(ch_stream);
        
        ch_stream = getchar();
    }
    return 0;
}

int substitution(int input, char * identity) {
    
    for(int i = 0; i < strlen(identity); i ++) {
        if (input == ('a' + i) && input >= 'a' && input <= 'z') {
            return identity[i];
        }
        else if (input == ('A' + i) && input >= 'A' && input <= 'Z') {
            return toupper(identity[i]);
        }
    
    }
    
    return input;
    
}
