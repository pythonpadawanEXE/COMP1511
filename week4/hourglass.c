//z5165158 Jake Edwards 26/06/2021
/*Write a program called loop_sum.c that reads an integer n from standard input,
 and then scans in n integers from standard input, adds them together, then 
 prints the sum. 
*/
#include <stdio.h>

void print_line(int i,int linesize);

int main(void){
    int size;
    int line_num;
    
    printf("Please enter a size: ");
    scanf("%d", &size);
    
    for(line_num = 0; line_num < (size/2); line_num++) {
        print_line(line_num,size);
    }
   for(line_num = size/2 ; line_num >= 0; --line_num) {
        print_line(line_num, size);
    }


    return 0;
}

void print_line(int line_num, int linesize){

    for(int col = 0; col < linesize; col++) {
        if (line_num == 0 ||  line_num == (linesize-1)) {
            printf(" -"); 
        }
        else if (col >= line_num && col < linesize-line_num){
            printf("%2d", line_num);
        }
        else {
            printf(" -"); 
        }
    }
    printf("\n");

}
