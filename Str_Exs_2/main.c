#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    int word_count = 0, in_word = 0;
    char* ptr = str;

    while (*ptr) {
        if (isalpha(*ptr)) {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
        ptr++;
    }

    printf("Amount of words: %d\n", word_count);
    return 0;
}
