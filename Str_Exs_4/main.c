#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[100];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    char str2[100];
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] == '\n') {
            str1[i] = '\0';
            break;
        }
        i++;
    }

    i = 0;
    while (str2[i] != '\0') {
        if (str2[i] == '\n') {
            str2[i] = '\0';
            break;
        }
        i++;
    }

    int isTheSame = 1;
    int j = 0;
    while (str1[j] != '\0' || str2[j] != '\0') {
        if (str1[j] != str2[j]) {
            isTheSame = 0;
            break;
        }
        j++;
    }

    if(isTheSame){
        printf("The strings are the same.\n");
    }else{
        printf("The strings are not the same!!!\n");
    }

    return 0;
}
