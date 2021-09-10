/* Jake Edwards z5165158 15/06/2021
*
* Write a C program order3_challenge2.c that reads 3 integers and prints them from smallest to largest.

You are only permitted to have 3 variables in your program and they must be of type int.

The restrictions of the previous challenge exercise also apply.

You are not permitted to use if statements.

You are not permitted to use loops (e.g. while).

You are not permitted to call functions other than printf and scanf. For example, you are not permitted to use functions from the math library.

You are not permitted to use printf inside expressions - you can only use printf as a statement (the way it has been used in lectures).

You are not permitted to assign variables inside expressions - you can only assign variables as a statement (the way it has been done in lectures).

For example, both of these are invalid:

(a <= b) && printf("a"); // invalid

(a <= b) && (a = b); // invalid

You can use printf to print the value of an expression, in other words you can have an expression inside printf.

You are only permitted to use parts of C covered in the weeks 1 and 2 lectures. For example, you are not permitted to use the ternary ?: operator. You are not permitted to use arrays. You are not permitted to define functions. 
*/


#include <stdio.h>

int main(void) {
int a;
int b;
int c;



printf("Enter integer:");
scanf("%d",&a);

printf("Enter integer:");
scanf("%d",&b);

printf("Enter integer:");
scanf("%d",&c);


printf("The integers in order are: %d %d %d\n",(a < b && a < c)*a + (b < c && b < a)* b + (c < a && c < b) * c + (a == b && a < c)*a + (b == c && b < a)*b + (c == a && c < b)*c + (a == b && a == c)*a ,((b <= a && a <= c) || (c <= a && a <= b)) * a + ((a <= b && b <= c) || (c <= b && b <= a)) * b + ((b <= c && c <= a) || (a <= c && c <= b)) * c -(a == c)* a -(a == b)* a - (b == c) * b + (a == b && b == c)*c,a + b + c -(((b <= a && a <= c) || (c <= a && a <= b)) * a + ((a <= b && b <= c) || (c <= b && b <= a)) * b + ((b <= c && c <= a) || (a <= c && c <= b)) * c -(a == c)* a -(a == b)* a - (b == c) * b + (a == b && b == c)*c)-((a < b && a < c)*a + (b < c && b < a)* b + (c < a && c < b) * c + (a == b && a < c)*a + (b == c && b < a)*b + (c == a && c < b)*c + (a == b && a == c)*a ) );
return 0;
}
