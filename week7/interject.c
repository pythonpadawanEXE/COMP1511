// COMP1511 Week 7 Test: Interject
//
// This program was written by Jake Edwards (z5165158)
// on 16/07/2021
//
// This program adds interjections to strings.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1002

// Modify str so that it contains interject at the given index.
void interject(char *str, char *interject, int index) {
    // TODO: complete this function.
    
    
    char newstring[MAX_SIZE];
    for(int i = 0;i < strlen(str)+strlen(interject); i++) {
        if(i < index){
            newstring[i] = str[i];
        }
        else if(i >= index && i < index + strlen(interject)) {
            newstring[i] = interject[i - index];
        }
        else if ( i >= index + strlen(interject)) {
            newstring[i] = str[i - strlen(interject)];
        }
    }
    newstring[strlen(str)+strlen(interject)] = '\0';
    //printf("%s\n",newstring);
    strcpy(str, newstring);
}


// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    return 0;
}
