// exam_q7.c
//
// This program was written by z5165158
// on 18/08/21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Do not change these #defines, or your program will fail the autotests!
#define TRUE 1
#define FALSE 0

#define MAX_REGEX_SIZE 128

// matches should return TRUE if the string `text` matches the
// regular expression `regex`, or FALSE otherwise.
//https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
int matches(char *regex, char *text) {
    char array_of_str[MAX_REGEX_SIZE][MAX_REGEX_SIZE];
    //length of each section
    int size_sections[MAX_REGEX_SIZE] = {0};
    //flag if section of array_of_str is within [] characters as 1 or 0 otherwise
    int reg_flag[MAX_REGEX_SIZE] = {0};
    const char s[2] = "]";
    char *str;
    char *token;
    strcpy(str,regex);
    token = strtok(str, s);
    
    int i = 0;
    strcpy(array_of_str[i],token);
    
    size_sections[i] = strlen(token);
    //need to fix to give flags and sizes correctly
    while( token != NULL ) {
      strcpy(array_of_str[i],token);
      size_sections[i] = strlen(token);  
      token = strtok(NULL, s);
      i++;
      
    }
    
    int result = 1;
    int sections = i;
    int iter_sections = 0;
    int iter_text = 0;
    
    for(int ii = 0; ii < MAX_REGEX_SIZE;ii++){
        if(strstr(&array_of_str[ii][MAX_REGEX_SIZE],"[") != NULL){
            reg_flag[ii] = 1;
        }
    }
    
    
    while( iter_text < strlen(text)){
    
        if(reg_flag[i] == 1){
            if(strstr(&array_of_str[iter_sections][MAX_REGEX_SIZE],&text[iter_text]) == NULL){
                return 0;
            }
            iter_text++;
            iter_sections++;
        }
        else{ 
            if(strncmp(&array_of_str[i][MAX_REGEX_SIZE],&text[iter_text],size_sections[iter_sections]) != 0){
                return 0;
            }
            iter_text = iter_text + size_sections[iter_sections];
            iter_sections++;
    }
    return result; 
}


///////////////////////////////////////////////////////////////
//
// YOU DO NOT NEED TO UNDERSTAND CODE BELOW THIS COMMENT
// 
// DO NOT CHANGE CODE BELOW THIS COMMENT
//
// IF YOU THINK YOU NEED TO CHANGE ANYTHING BELOW THIS COMMENT,
// YOU HAVE MISUNDERSTOOD THE QUESTION
//
///////////////////////////////////////////////////////////////

int scan_regex(char *regex);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // Check that we got the right number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s text_to_match\n", argv[0]);
        exit(1);
    }

    char *text = argv[1];
    char regex[MAX_REGEX_SIZE];;

    while (scan_regex(regex)) {
        if (matches(regex, text)) {
            printf("MATCH\n");
        } else {
            printf("NO_MATCH\n");
        }
    }

    return 0;
}


// DO NOT CHANGE THIS FUNCTION
// Scans in a line with fgets, and removes the newline character (if
// there was one).
// Returns 1 if it managed to read a line, and 0 otherwise.
int scan_regex(char *regex) {
    if (fgets(regex, MAX_REGEX_SIZE, stdin) == NULL) {
        return 0;
    }

    // If the line from fgets contains a newline, replace it with a '\0'.
    regex[strcspn(regex, "\n")] = '\0';

    return 1;
}
