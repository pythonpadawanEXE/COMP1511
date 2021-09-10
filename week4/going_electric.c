
#include <stdio.h>
#include <stdlib.h>
#define MAX_STOPS 10000


int length(int *array);
int longest_possible(int *array);
int process_fuel(int *array);
int longest_possible(int *array);
int total_fuel(int *array);

int main(void){
    int array[MAX_STOPS] = {0};
    for(int i=0; i < MAX_STOPS;i++){
        array[i] = -1;
    }
    int c;
    int check = scanf("%d ",&c);
    int i = 0;
    while( check != EOF){
        array[i] = c;
        i++;
        check = scanf("%d ",&c);
    }
    i = 0;
    int result  = process_fuel(array);
    
    return 0;
}
int total_fuel(int *array){
   int i = 0;
   int fuel = 0;
    while(array[i] != -1){
        i++;
        fuel = fuel + array[i];
    } 
    return fuel;
}

int length(int *array){
    int i = 0;
    while(array[i] != -1){
        i++;
    
    }
    return i;
}
int longest_possible(int *array){
    int fuel = array[0];
    int idx = 0;
    int stops = 0;
    while(fuel > 0){
        fuel =  fuel - 1;
        if(array[idx] != 0) {
            fuel = fuel + array[idx];
            stops++;
        }
        idx++;
    }
    if(idx >= length(array)){
        return stops;
    }
    else{
        return -1;
    }
}


int process_fuel(int *array){
    int fuel = array[0];
    int idx = 0;
    int longest_stops = longest_possible(array);
    if( longest_stops != -1){
        while(fuel != 0){
        //need to print least amount of charging stops
        //need to decide how far to drive and when to charge
        //i.e. get initial charge search for last possible charger that will work
        //first check how much fuel is available to see if drive is possible
        //then compare fuel to remaining drive need 
            idx = idx + fuel;
            
            fuel = array[idx] + fuel;
        }
    }
    else  {
        printf("0\n");
    
    
    }

}
