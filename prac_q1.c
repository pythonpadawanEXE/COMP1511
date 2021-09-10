#include <stdio.h>
#define TEST_ARRAY_SIZE 100

// Return the maximum sum of a row in the 2D array.
int max_row_sum(int array[TEST_ARRAY_SIZE][TEST_ARRAY_SIZE], int side_length) {
    // PUT YOUR CODE HERE (you must change the next line!)
    return 42;
}

// This is a simple main function which could be used
// to test your max_row_sum function.
// It will not be marked.

int main(void) {
    int test_array[TEST_ARRAY_SIZE][TEST_ARRAY_SIZE] = {
        { 1,    2,    3,    4 },
        { 1,   11,  111,  111 },
        { 1,    1,    1,    1 },
        { 22,  22,    2,    2 }
    };

    int result;

    result = max_row_sum(test_array, 1);
    printf("Max row sum in 1x1 array: %d\n", result);

    result = max_row_sum(test_array, 2);
    printf("Max row sum in 2x2 array: %d\n", result);

    result = max_row_sum(test_array, 3);
    printf("Max row sum in 3x3 array: %d\n", result);

    result = max_row_sum(test_array, 4);
    printf("Max row sum in 4x4 array: %d\n", result);

    return 0;
}
