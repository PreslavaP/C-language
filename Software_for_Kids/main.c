#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amOfCommands, command, number;
    printf("Enter the number of commands: ");
    scanf("%d", &amOfCommands);

    int numbers[100];
    int size = 0;

    for(int i = 0; i < amOfCommands; i++){
        printf("Enter command(1-3): ");
        scanf("%d", &command);

        switch(command){
        case 1:
            printf("Executing command 1: Enter a number: ");
            scanf("%d", &number);
            numbers[size++] = number;
            printf("Adding number %d to the set of numbers.\n", number);
            break;
        case 2:
            printf("Executing command 2: Enter a number: ");
            scanf("%d", &number);
            int found = 0;
            printf("Searching the number %d for deleting... \n", number);
            for(int i=0; i < size; i++){
                if (numbers[i] == number) {
                    found = 1;
                    for (int k = i; k < size - 1; k++) {
                        numbers[k] = numbers[k + 1];
                    }
                    size--;
                    break;
                }
            }
            if(found){
                printf("The number %d is deleted!\n", number);
            }else{
                printf("The number %d is not found!\n", number);
            }
            break;
        case 3:
            printf("Executing command 3: Searching the smallest value...\n");
            int smallest = numbers[0];
            for(int i = 0; i < size; i++){
                if(numbers[i]<smallest){
                    smallest = numbers[i];
                }
            }
            printf("The smallest value is %d!", smallest);
            break;
        }
    }

    return 0;
}
