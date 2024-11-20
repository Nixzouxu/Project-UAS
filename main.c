#include <stdio.h>
#include "function.h"

int main() {
    int registerChoice;
    char Y,n;

    printf("========================================\n");
    printf("         🌟 Welcome To Quiz Game 🌟     \n");
    printf("        WHO WANTS TO BE A MILLIONARE      \n");
    printf("========================================\n");
    printf("Do you want to Register? (Y/n): ");
    scanf("%d", &registerChoice);

    if (registerChoice == Y) {
        signUp();
        signIn();
    } else {
        signIn();
    }

    mainMenu();

    return 0;
}
