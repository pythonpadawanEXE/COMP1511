//test ptrs

#include <stdio.h>

int main (void) {
    
    char n_ten[ ] = "yes";
    printf("%s\n",n_ten);
    char *str_total;   
    int total = -10;
    if (total == -10) {
             str_total = n_ten;
             
        } 
    printf("%s\n",str_total);    
    
    return 0;
}
