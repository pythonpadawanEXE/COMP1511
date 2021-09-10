#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void fibo(int prev, int cur,int end);
int main(int argc ,char * argv[]){

    int end = atol(argv[1]);

    fibo(0,1,end);


    return 0;
}

void fibo(int prev, int cur, int end){
    if(cur > end){
        printf("%d\n",cur);
        return;
    }
    else{
        printf("%d ", cur);
        return fibo(cur,prev+cur,end);
    }
}
