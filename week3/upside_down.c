#include <stdio.h>

int main(void){
    double a;
    double b;
    double c;
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    if (a < b && b < c){
        printf("up\n");
    }
    else if(a > b && b > c){
        printf("down\n");
    }
    else {
        printf("neither\n");
    }





    return 0;
}
