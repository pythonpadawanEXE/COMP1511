#include <stdio.h>

int main(void){
    int a;
    int b;
    scanf("%d %d",&a,&b);
    if (a < 0){
        a = a*-1;
    }
    if (b < 0){
        b = b*-1;
    }
    if (a*b != 0){
        printf("%u\n",a*b);
    }
    else{
        printf("zero\n");
    }





    return 0;
}
