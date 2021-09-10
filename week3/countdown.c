/* Jake Edwards z5165158 17/06/2021
*
*In this exercise you will use a loop to print a countdown from 10 to 0. Start by creating a file called countdown.c, and copying the above code. Modify this code so that the loop counts down from 10 until 0.
*
*/
#include <stdio.h>

int main(void) {
    
    //initialise counter to 10
    int counter = 10; 
    // loop until not <= 0
    while (counter >= 0) { // Have printed all numbers between 0 and counter
        // print counter
        printf("%d\n", counter);
        // decrease counter
        counter = counter - 1; 
    } // counter == 0


    return 0;
}
