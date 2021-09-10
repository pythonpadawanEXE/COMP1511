// Solution to Going Electric
// Tom Kunc (t.kunc@unsw.edu.au) - 2020-06-20

#include <stdio.h>
#include <stdbool.h>

#define MAX_STATIONS 10000

int contains_nonzero(int size, int array[size]) {
    int i = 0;
    while (i < size) {
        if (array[i] > 0) {
            return true;
        }
        i++;
    }
    return false;
}

int find_max_index(int size, int array[size]) {
    int max_index = 0;

    int i = 0;
    while (i < size) {
        if (array[i] > array[max_index]) {
            max_index = i;
        }
        i++;
    }

    return max_index;

}

int main(void) {
    int stations[MAX_STATIONS] = {0};
    int num_stations = 0;
    while (scanf("%d", &stations[num_stations++]) == 1);

    int num_stops = 0;
    int fuel = 1;

    while (contains_nonzero(fuel, stations) && fuel < num_stations - 1) {
        int max_index = find_max_index(fuel, stations);
        fuel += stations[max_index];
        stations[max_index] = 0;
        num_stops++;
    }

    if (fuel >= num_stations - 1) {
        printf("%d\n", num_stops);
    } else {
        printf("%d\n", 0);
    }
    return 0;
}
