#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

// Fungsi untuk membersihkan terminal
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk mencetak pesan error
void printError(const char *message) {
    printf("\n❌ Error: %s ❌\n", message);
    printf("Exiting program...\n");
    exit(0);
}

// Fungsi untuk menyimpan akun ke file
void saveAccountToFile(struct GameAccount account) {
    FILE *file = fopen("./Database/Login.bin", "ab");
    if (file == NULL) {
        printError("Unable to open file for saving");
    }
    fprintf(file, "%s@%s\n", account.username, account.password);
    fclose(file);
}

// Fungsi untuk memeriksa apakah username sudah ada di file
bool isUsernameTaken(const char *username) {
    FILE *file = fopen("./Database/Login.bin", "rb");
    if (file == NULL) return false;

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char storedUsername[50];
        sscanf(line, "%[^@]", storedUsername);
        if (strcmp(storedUsername, username) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}

// Fungsi untuk Sign Up
void signUp() {
    clearScreen();
    printf("========================================\n");
    printf("              🌟 Sign Up 🌟\n");
    printf("========================================\n");

    struct GameAccount account;

    printf("Enter username: \n");
    scanf("%s", account.username);

    if (isUsernameTaken(account.username)) {
        printError("Username already taken");
    }

    printf("Enter password: \n");
    scanf("%s", account.password);

    saveAccountToFile(account);
    printf("✅ Account successfully created! Proceeding to login...\n");
}

// Fungsi untuk Sign In
bool signIn() {
    clearScreen();
    printf("========================================\n");
    printf("              🌟 Sign In 🌟\n");
    printf("========================================\n");

    char username[50], password[50];

    printf("Enter username: \n");
    scanf("%s", username);
    printf("Enter password: \n");
    scanf("%s", password);

    FILE *file = fopen("./Database/Login.bin", "rb");
    if (file == NULL) {
        printError("No accounts registered yet");
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char storedUsername[50], storedPassword[50];
        sscanf(line, "%[^@]@%[^\n]", storedUsername, storedPassword);
        if (strcmp(storedUsername, username) == 0 && strcmp(storedPassword, password) == 0) {
            fclose(file);
            printf("✅ Sign In successful! Welcome back, %s.\n", username);
            return true;
        }
    }

    fclose(file);
    printError("Invalid username or password");
    return false; // Tidak akan sampai ke sini karena program exit
}

// Fungsi untuk menampilkan menu utama
void mainMenu() {
    int choice;
    while (1) {
        clearScreen();
        printf("========================================\n");
        printf("    🌟 WHO WANTS TO BE A MILLIONAIRE 🌟\n");
        printf("========================================\n");
        printf("CHOOSE AN OPTION\n");
        printf("1. Start Quiz\n");
        printf("2. Rules\n");
        printf("3. Info\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Starting the Quiz...\n");
                // Implementasikan fungsi runQuiz() jika perlu
                return;
            case 2:
                printf("=== RULES ===\n");
                printf("1. Answer the questions correctly to earn points.\n");
                printf("2. Each correct answer gives you 20 points.\n");
                printf("3. Total score is 100 points for all correct answers.\n");
                printf("4. Good luck and have fun!\n");
                getchar(); getchar();
                break;
            case 3:
                printf("=== INFO ===\n");
                printf("This is a simple Quiz Game system.\n");
                getchar(); getchar();
                break;
            case 4:
                printf("Thank you for playing. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
