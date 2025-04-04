#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countLetters(char *str) {
    int count[128] = {0};
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            count[str[i]]++;
        }
    }
    for (i = 'A'; i <= 'Z'; i++) {
        if (count[i] > 0) {
            printf("%c: %d\n", i, count[i]);
        }
    }
    for (i = 'a'; i <= 'z'; i++) {
        if (count[i] > 0) {
            printf("%c: %d\n", i, count[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    countLetters(str);

    return 0;
}
