#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

// Struct untuk akun permainan
struct GameAccount {
    char username[50];
    char password[50];
};

// Deklarasi fungsi
void clearScreen();
void printError(const char *message);
void saveAccountToFile(struct GameAccount account);
bool isUsernameTaken(const char *username);
void signUp();
bool signIn();
void mainMenu();

#endif
