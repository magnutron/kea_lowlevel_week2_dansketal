#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

// Menu function
void showMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Enter a number\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    int num;

    while (1) {
        // Display the menu
        showMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            // Get the number from the user
            printf("Give me a number between 0 and 999,999: ");
            scanf("%d", &num);

            if (num < 0 || num > 999999) {
                printf("Invalid number! Please enter a number between 0 and 999,999.\n");
                continue;  // Return to the start of the menu
            }

            // Get the Danish number equivalent
            char* danishNum = danishnumbers(num);
            printf("Danish number: %s\n", danishNum);

            // Free the allocated memory
            free(danishNum);
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;  // Exit the loop
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}