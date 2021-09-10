// COMP1511 Week 4 Lab: Circle Facts
//
// This program was written by Jake Edwards (z5165158)
// on 24/06/2021
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    
    return M_PI * pow(radius, 2); 
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {
    
    return 2 * M_PI * radius; 
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {
    
    return 2 * radius; 
}
