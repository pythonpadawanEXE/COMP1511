// Read characters until eof
// Andrew Taylor - andrewt@unsw.edu.au
// June 2021

#include <stdio.h>

int main(void) {
    // getchar returns an int which will contain either
    // the ASCII code of the character read or EOF

    int ch = getchar();
    while (ch != EOF) {
        putchar("'%c' read, ASCII code is %d\n", ch, ch);
        ch = getchar();
    }
    return 0;
}
