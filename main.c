#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// function to clear terminal
void clear_terminal(){
    #ifdef _WIN32
        system("cls"); // clear terminal for windows
    #else
        system("clear"); // clear terminal for linux/unix
    #endif
}
// Function to display main menu
void display_main_menu() {
    printf("\n  WELCOME TO QUIZ GAME    \n");
    printf("WHO WANTS TO BE A MILLIONARE\n\n");
    printf("Select Your Option\n");
    printf("1. Start Quiz\n");
    printf("2. Rules\n");
    printf("3. Info\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

void showRules() {
    clear_terminal();
    printf(" ======================================== \n");
    printf("                  Rules                   \n");
    printf(" ======================================== \n");
    printf("1. The quiz contains 5 multiple-choice questions.\n");
    printf("2. Each correct answer gives you 20 points.\n");
    printf("3. You must score as high as possible to win.\n");
    printf("4. Enjoy the game and give your best!\n");
    printf("\nPress Enter to return to the main menu...");
    getchar(); getchar(); // Pause hingga pengguna menekan Enter
    clear_terminal();
}

void showInfo() {
    clear_terminal();
    printf(" ======================================== \n");
    printf("                  Info                    \n");
    printf(" ======================================== \n");
    printf("This quiz game is developed in C.\n");
    printf("It demonstrates the use of functions, file handling,\n");
    printf("and user interactions for a simple text-based game.\n");
    printf("\nPress Enter to return to the main menu...");
    getchar(); getchar(); // Pause hingga pengguna menekan Enter
    clear_terminal();
}

// function to start Quiz
void start_quiz(){
    int score = 0;
    char answer;

    clear_terminal();
    printf("\n*******************************\n");
    printf("*     Welcome to the Quiz  *\n");
    printf("*******************************\n");
    // Pertanyaan 1
    printf("\n1. Siapa Penulis buku Laskar Pelangi\n");
    printf("A. Tere Liye\nB. Eka Kurniawan\nC. Angga Suherta\nD. Andrea Hirata\n");
    printf("Your Answer (A/B/C/D): ");
    scanf(" %c", &answer);
    if (answer == 'D' || answer == 'D') score++;

    // Pertanyaan 2
    printf("\n2. Siapa Penulis buku Harry Potter\n");
    printf("A. Jane Austen\nB. William Shakespeare\nC. J.K Rowling\nD. Adolf Hitler\n");
    printf("Your Answer (A/B/C/D): ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') score++;

    // Pertanyaan 3 - Soal Matematika Menjebak
    printf("\n3. Siapa penulis buku Six of Crows\n");
    printf("A. Leigh Bardugo\nB. Arthur Conan Doyle\nC. Lewis Carroll\nD. Emily Bronte\n");
    printf("Your Answer (A/B/C/D): ");
    scanf(" %c", &answer);
    if (answer == 'A' || answer == 'a') score++;

    // Pertanyaan 4
    printf("\n4. Dalam Konteks literatur apa yang dimaksud dengan Plot Twist\n");
    printf("A. Pengembangan karakter yang mendalam\nB. Perubahan mendadak dalam alur cerita yang tidak terduga\nC. Kejadian yang terjadi seketika\nD. Hal yang tidak terduga namun tetap mengikuti alur cerita\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') score++;

    // Pertanyaan 5
    printf("\n5. Apa tujuan utama dari penggunaan metafora dalam sebuah buku?\n");
    printf("A. Memberikan keindahan dan kedalaman pada tulisan\nB. Menyampaikan informasi dengan cara yang langsung dan mudah dipahami\nC.  Menyembunyikan makna dari pembaca\nD. Menghindari pengulangan kata yang sama\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    if (answer == 'A' || answer == 'a') score++;


    // Display the final Score
    clear_terminal();
    printf("\n**************************************\n");
    printf("              QUIZ OVER!                   \n");
    printf("*     Your Total Score: %d from 5        *\n", score);
    printf("       Thank you for playing <3         \n");
    printf("****************************************\n");
    printf("\nPress Enter to return to the main menu...\n");
    getchar();
    
}
int main(int argc, char *argv[]){

    if (argc != 3)
    {
       printf("Gagal login !");
       printf("\ncara penggunaan : ./FileProgramUtama <username> <password>");
    }
    char usernameInput[10], passwordInput[10];
    strcpy(usernameInput, argv[1]);
    strcpy(passwordInput, argv[2]);
    
    FILE *fpr; // file pointer

    // mengecek apakah file tersebut bisa dibuka atau tidak
    if ((fpr = fopen("database/login.bin", "rb")) == NULL) // NULL = Kosong (fopen = membuka file )
    {
        printf("Anda Gagal login");
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
        getchar(); // pause sebelum masuk menu
 } else
    {
        printf("Ga bisa lah lek.. apalah");
        return EXIT_FAILURE;
    }
    int choice;
    while(1){
        display_main_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clear_terminal();
                start_quiz();
                break;
            case 2:
                clear_terminal();
                showRules();
                break;
            case 3:
                clear_terminal();
                showInfo();
                break;
            case 4:
                printf("Makasih udah main <3\n");
                return EXIT_SUCCESS;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
                getchar(); // menangkap newline
                getchar(); // pause sebelum kembali ke menu
        }
    }    
    return 0;
}
