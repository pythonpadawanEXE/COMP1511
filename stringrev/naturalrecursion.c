#include <stdio.h>

void natural_numbers(int start,int end);
int main(void){
    
    natural_numbers(0,50);

    return 0;
}

void natural_numbers(int start,int end){
    if(start == end){
        printf("%d\n",start);
        return;
    }
    else{
        printf("%d\n",start);
        return natural_numbers(start+1,end);
    }
}
