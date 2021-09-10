// Function to create a casesar cipher
// 
//
// This program was written by Jake Edwards (z5165158)
// on 15/07/2021
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 256
int decode(int input,char *identity);

int main(int argc, char *argv[]) {
    int pos;
    char string[LENGTH];
    fgets(string, LENGTH, stdin);
    scanf("%d", &pos);
    printf("The character in position %d is '%c'\n", pos, string[pos]);
    return 0;
}

