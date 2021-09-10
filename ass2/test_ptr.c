//testing pointers
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void ptr_fun(int * x);


int main(void){
/*
    int*    x;  // Allocate the pointers x and y
    int*    y;  // (but not the pointees)
    
    x = malloc(sizeof(int));    // Allocate an int pointee,
                                // and set x to point to it
    
    *x = 42;    // Dereference x to store 42 in its pointee
    
    *y = 13;    // CRASH -- y does not have a pointee yet
    
    y = x;      // Pointer assignment sets y to point to x's pointee
    
    *y = 13;    // Dereference y to store 13 in its (shared) pointee
*/

    int * x = malloc(sizeof(int *));
    *x = 42;
    int *pp = x;
    int **ppp = &x;
    
    printf("val %d  address %p\n or is it value %d  address %p?\n",*x , pp,*x, ppp );
    // i think first address is of the value and second is memory adress of the pointer
    return 0;
}

void ptr_fun(int *x){

 
}
