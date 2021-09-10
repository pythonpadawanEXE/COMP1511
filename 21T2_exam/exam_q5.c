// exam_q5.c
//
// This program was written by z5165158
// on 18/08/2021


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 
int check_if_suffix(char *suffix,char *ptr){
    //printf("suffx:%s ptr:%s",suffix,ptr);
    /*while(suffix[0] != '\n' || suffix[0] != '\0'){
        if(suffix[0] != ptr[0]){
            return 0;
        }
        //printf("suffx:%s ptr:%s",suffix,ptr);
        suffix++;
        ptr++;
    }*/
    int res = strncmp(suffix,ptr,strlen(suffix));
    //printf("%d\n",res);
    return res;
}

int main(int argc, char *argv[]) {
    char *  ptr ;
    //int idx;
    //int continue = 1;
    char *line = calloc(MAX_LINE_SIZE,sizeof(char));
    while(fgets(line, MAX_LINE_SIZE , stdin)){
        for(int i = 1; i < argc; i++){
            if(argv[i] != NULL && strlen(argv[i]) < strlen(line)){
                //idx = strlen(line)-strlen(argv[i]);
                //printf("idx:%d\n",idx);
                ptr = &line[strlen(line)-strlen(argv[i])-1];
                if( check_if_suffix(argv[i],ptr) == 0){
                    
                    printf("%s",line);
                }
            }
        }
    }
    free(line);
    return 0;
}
