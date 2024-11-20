#include <stdio.h>
#include "function.h"

int main() {
    int registerChoice;

    printf("========================================\n");
    printf("         🌟 Welcome To Quiz Game 🌟     \n");
    printf("        WHO WANTS TO BE A MILLIONARE      \n");
    printf("========================================\n");
    printf("Do you want to Register? (1 for Yes, 0 for no): ");
    scanf("%d", &registerChoice);

    if (registerChoice == 1) {
        signUp();
        signIn();
    } else {
        signIn();
    }

    mainMenu();

    return 0;
}
