#include <stdio.h>
#include <stdlib.h>

void stringLen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        if (str[length] == '\n') {
            str[length] = '\0';
            break;
        }
        length++;
    }
    printf("Length is: %d\n", length);
}

int main() {
    char str[100];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    stringLen(str);

    return 0;
}
