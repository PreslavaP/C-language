#include <stdio.h>
#include <stdlib.h>

void convertToLower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
}
int main()
{
    char str[100];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    convertToLower(str);

    printf("Converted string: %s", str);

    return 0;
}
