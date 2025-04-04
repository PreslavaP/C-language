#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int countVowels(char *str) {
    int count = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            count++;
        }
    }

    return count;
}

int main() {
    char str[100];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    int vowels = countVowels(str);
    printf("%d\n", vowels);

    return 0;
}
