/* Jake Edwards (z5165158) 9/06/2021
*Create a program called addition.c, which will add together the 
number of students and tutors in a class.

This program should ask for two integers using the 
message Please enter the number of students and tutors:
 and then display the sum of the integers as students + tutors = sum.
*
*/

#include <stdio.h>

int main (void){
    int stu_num;
    int tut_num;
    
    printf("Please enter the number of students and tutors:");
    scanf("%d %d", &stu_num, &tut_num);
    int total = stu_num + tut_num;
    printf("%d + %d = %d\n", stu_num, tut_num, total);





    return 0;
}
