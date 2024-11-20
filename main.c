#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fungsi untuk clear terminal
void clear_terminal()
    {printf("\e[1;1H\e[2J");} 

int main(int argc, char *argv[]){

    if (argc != 3)
    {
       printf("Gagal login !");
       printf("\ncara penggunaan : ./FileProgramUtama username password");
    }
    char usernameInput[10], passwordInput[10];
    strcpy(usernameInput, argv[1]);
    strcpy(passwordInput, argv[2]);
    
    FILE *fpr; // file pointer

    // mengecek apakah file tersebut bisa dibuka atau tidak
    if ((fpr = fopen("database/login.bin", "rb")) == NULL) // NULL = Kosong (fopen = membuka file )
    {
        printf("apalah");
        return EXIT_FAILURE;  // keluar dari program
    }
    // jk bisa membuka file bin tersebut maka :
    char akun[30];
    fread(akun, sizeof(char), sizeof(akun)/sizeof(char), fpr); // akan membaca 30 kalimat dalam file yang akan dibuka menggunakan pointer fpr lalu disimpan di dalam var akun

    // jika tidak digunakan lagi maka kita tutup file nya
    fclose(fpr);
    
    char *string[3];
    char username[20], password[20];
    int ctrl = 0;

    string[0] = strtok(akun, "@");
    while (string[ctrl++] != NULL){
        string[ctrl] = strtok(NULL, "@"); 
    }
    strcpy(username, string[0]);
    strcpy(password, string[1]);

    if ((strcmp(usernameInput, username) == 0) && (strcmp( passwordInput ,password) == 0)) {
        printf("Horee dah bisa login bejir\n");
    } else
    {
        printf("Ga bisa pulang sana dek bagi dua sama mamak");
    }
    
    return 0;
}
