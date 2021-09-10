#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i = 0;
    while (i < argc) {
        int string_length = strlen(argv[i]);
        if (string_length >= 3 && argv[i][2] == 'h') {
            printf("argv[%d]'s third character is 'h'!\n", i);
        }
        i++;
    }
}
