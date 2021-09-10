//z5165158 15/07/2021
#include <stdio.h>

int is_vowel(int character);

int main(void) {

    int ch_stream = getchar();
    while (ch_stream != EOF) {
        if (is_vowel(ch_stream) == 0 && ch_stream != EOF) {
            printf("%c\n", ch_stream);
        }
        ch_stream = getchar();
    }

    //printf("\n");
    return 0;
}

int is_vowel(int character){
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int len = sizeof(vowels)/sizeof(vowels[0]);
    for(int i = 0; i < len; i++) {
        if (vowels[i] == character) {
            return 1;
        }
    }
    return 0;
}
