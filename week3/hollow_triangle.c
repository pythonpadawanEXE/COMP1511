/* Jake Edwards z5165158 17/06/2021
*
*Write a program called hollow_triangle.c that reads an integer n from standard input. and prints a pattern of asterisks forming a hollow triangle.

You can assume n is greater than 3.

Make your program match the examples below exactly.
*
*/
#include <stdio.h>

void print_line(int idx_one, int idx_two, int size);
void print_triangle(int size);
int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    print_triangle(size);

    return 0;
}

//print each line of the triangle picture
void print_line(int idx_one, int idx_two, int size){

    int count = 0;
    while (count < size) {
        if (count ==  idx_one || count == idx_two) {
            printf("*");
        }
        else if (idx_two == size-1){
            printf("*");
        }
        else {
            printf(" ");
        }
        count = count + 1;   
    
    
    }
    printf("\n");


}

/*call print_line and determines how to cycle through 
indices of asterisk positions to create triangle shape
*/
void print_triangle(int size){
    int count = 0;
    int idx_one = 0;
    int idx_two = 0;
    
    while (count < size) {
        print_line(idx_one, idx_two, size);
        count = count + 1;
        idx_two = idx_two + 1;
        
    
    
    }

}
