/* Jake Edwards (z5165158) 10/06/2021
*
*We will often roll multiple dice at the same time.

Write a C program dice_range.c that reads the number of sides on a set of dice and how many of them are being rolled. It then outputs the range of possible totals that these dice can produce as well as the average value.

Hint: use the examples below to clarify the expected behaviour of your program. 
*
*/

#include <stdio.h>
#define A 1
double average(double min, double max);

int main (void) {
    int num_sides;
    int num_dice;
    int min_range;
    int max_range;
    double avg;
    
    int my_var =  A;
    
    printf("Enter the number of sides on your dice:");
    scanf("%d", &num_sides);
    printf("Enter the number of dice being rolled:");
    scanf("%d", &num_dice);
    
    max_range = num_dice * num_sides;
    min_range = num_dice;
    avg = average (num_dice, max_range);
    if (min_range > 0 &&  max_range > 0) {
        printf ("Your dice range is %d to %d.\n", min_range, max_range);
        printf ("The average value is %f\n", avg);
    }
    else {
        printf ("These dice will not produce a range.\n");
    }
    
    return 0;
}
    
        
        


double average(double min, double max) { 
        
        
        
    
    return max/2 + min/2;
}
