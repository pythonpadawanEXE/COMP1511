//z5165158 Jake Edwards 26/06/2021
/*Write a program called loop_sum.c that reads an integer n from standard input,
 and then scans in n integers from standard input, adds them together, then 
 prints the sum. 
*/
#include <stdio.h>

int main(void){
    int amount_num;
    int sum = 0;
    int tmp;
    
    printf("How many numbers: ");
    scanf("%d", &amount_num);
    
    for(int i = 0; i < amount_num; i++) {
        scanf("%d", &tmp);
        sum = sum + tmp;
    }
    printf("The sum is: %d\n", sum);


    return 0;
}
