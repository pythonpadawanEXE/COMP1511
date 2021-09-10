//z5165158 24/06/2021 Jake Edwards 
/*For this exercise, make a program called cs_calculator.c which will scan in 
instructions until EOF and prints the output as specified below. An instruction
is a sequence of positive integers. The first integer identifies what type the
instruction is.

If the first number in the instruction is 1, then your program should print
out the square of the next number in the instruction.
If the first number in the instruction is 2, then your program should print 
out the value of the next number raised to the power of the number after 
next.

You can assume that the first number in the instruction is only either 1 or 2

You can assume that for each instruction, the correct number of successive 
positive integers will be given.*/ 

#include <stdio.h>


int square(int num1);
int powers(int num1, int num2);
int main(void) {
    int result = 1;
    int instruction;
    int number;
    int power;
    
    while (1 == result) {
        printf("Enter instruction:");
        result = scanf("%d", &instruction);
        if (instruction == 1) {
            scanf("%d", &number);
            printf("%d\n", square(number));
        }
        else if (instruction == 2) {
            scanf("%d", &number);
            scanf("%d", &power);
            printf("%d\n", powers(number, power) );
        }
        instruction = 0;
    }
    
   
    return 0;
}
int square(int num1) {
    return num1 * num1;
}

int powers(int num1, int num2) {
    int multiplier = num1;
    if (num2 == 0) {
        return 1;
    }
    else if (num2 == 1) {
        return num1;
    }
    for(int i = 0; i < num2 - 1; i++) {
        num1 = num1 * multiplier;
    }
    return num1;
}
