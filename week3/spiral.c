/* Jake Edwards z5165158 17/06/2021
*
*Write a program called spiral.c that reads an integer n from standard input. and prints an nxn pattern of asterisks and dashes in the shape of a spiral.
You can assume n is odd and >= 5.

This exercise must be completed without arrays.
*
*/
#include <stdio.h>
void print_spiral(int size);
void print_char(int col,int row,int size);
int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    print_spiral(size);
    //print_char(2,2,size);
    return 0;
}
void print_char(int col, int row, int size){
    int i = 0; //col
    int j = 0; //row
    //int sum = 0;
    int move = 1; 
    /*a move refers to an edge of a spiral the total amount of edges == the size
     of the spiral
    */ 
    int move_size = size;
    //move size refers to the length of the edge which slowly decreases 
    int count = 1; //counter within move size
    int cycle = 1;
    int right = 1;
    int down = 2;
    int left = 3;
    int up_ = 4;
    
    while (move <= size) {
        if (move == size ) {
            move_size = move_size + 1; //small kludge to write last asterisk
        }
        count = 1;    
        while (count < move_size) {
            
            
            if (i == col && j == row) {
                printf("*");
                return; 
            }   
            if (cycle == right) {
            
                i = i + 1;
            
            }
            else if (cycle == down) {
            
                j = j + 1;
            
            }
            
            else if (cycle == left) {
            
                i = i - 1;
            
            }
            else if (cycle == up_) {
            
                j = j - 1;
            }
            
            count =  count + 1; 
        }
        //reset cycle of left,down,right,up
        if (move % 4 == 0) {
            cycle = 0;
        }
        if (move == 1) {
            move_size = move_size + 0;//reduce move size only after first row 
                 
        }
        else if ((move - 1) % 2 == 0 && size-1 != move) {
            move_size = move_size - 2; 
            //reduce move size before each up/down move not including first change
        }
        move = move + 1;   
        cycle = cycle + 1; 
          
    }
    printf("-");
    return; //return if no row and column match to print("-")
}

void print_spiral(int size){

    int i = 0; //col
    int j = 0; //row
    //int sum = 0;
    while (j < size) {
        while (i < size) {
            print_char(i, j, size);
            i = i +1;
        
        }
        i = 0;
        printf("\n");
        j = j + 1;
    }

}

