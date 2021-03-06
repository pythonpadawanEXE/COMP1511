// Function to create a casesar cipher
// 
//
// This program was written by Jake Edwards (z5165158)
// on 15/07/2021
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 26
int frequency(int input,int * identity);

int main(int argc, char *argv[]) {
    int alphabet[LENGTH] = {0};

    double total = 0;
    int iter = 0;
    
    int ch_stream = getchar();
    while (ch_stream != EOF) {
        iter = frequency(ch_stream, alphabet);
        total = total + iter;
        
        ch_stream = getchar();
    }
    double fraction;
    for(int i = 0; i < LENGTH; i++) {
        fraction = alphabet[i] / total;
        printf("'%c' %lf %d\n", 'a' + i, fraction, alphabet[i]);
    }
    
    return 0;
}

int frequency(int input, int * identity) {
    
    input = tolower(input);
    
    if (input >= 'a' && input <= 'z') {
        identity[input-'a'] = identity[input-'a'] + 1;
        return 1;    
    }
    
    return 0;
    
}
