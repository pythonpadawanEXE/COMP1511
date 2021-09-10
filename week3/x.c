/* Jake Edwards z5165158 17/06/2021
*
*Write a program called x.c that reads an integer n from standard input, and prints an nxn pattern of asterisks and dashes in the shape of an "X".

You can assume n is odd and >= 5.

Make your program match the examples below exactly.

This exercise is designed to give you practice with while loops, if statements and some mathematical operators. Do not use arrays for this exercise!
*
*/
#include <stdio.h>

void print_line(int idx_one, int idx_two, int size);
void print_x(int size);
int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    print_x(size);

    return 0;
}

//print each line of the x picture
void print_line(int idx_one, int idx_two, int size){

    int count = 0;
    while (count < size) {
        if (count ==  idx_one || count == idx_two) {
            printf("*");
        }
        else {
            printf("-");
        }
        count = count + 1;   
    
    
    }
    printf("\n");


}

//call print_line and determines how to cycle through indices of asterisk positions to create x shape
void print_x(int size){
    int count = 0;
    int idx_one = 0;
    int idx_two = size-1;
    
    while (count < size) {
        print_line(idx_one, idx_two, size);
        count = count + 1;
        if (count >= size/2 + 1) {
            idx_one = idx_one - 1;
            idx_two = idx_two + 1;   
        }
        else if (count < size/2 + 1) {
            idx_one = idx_one + 1;
            idx_two = idx_two - 1;   
        }
        
    
    
    }

}
