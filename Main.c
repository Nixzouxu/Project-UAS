#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// ANSI Color Codes for Styling
#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define BOLD "\033[1m"


// function to clear terminal
void clear_terminal(){
    #ifdef _WIN32
        system("cls"); // clear terminal for windows
    #else
        system("clear"); // clear terminal for linux/unix
    #endif
}
// function to display header
void display_header(const char *subtitle){
    clear_terminal();
    printf(BOLD CYAN "************************************\n" RESET);
    printf(BOLD CYAN "*        WHO WANTS TO BE A         *\n" RESET);
    printf(BOLD CYAN "*           MILLIONAIRE            *\n" RESET);
    printf(BOLD CYAN "************************************\n" RESET);
    if (subtitle != NULL) {
        printf(YELLOW BOLD "%s\n\n" RESET, subtitle);
    }
}
// Function to display main menu
void display_main_menu() {
    display_header("CHOOSE SOME OPTION BELOW");
    printf("1. " BLUE "Start Quiz" RESET "\n");
    printf("2. " GREEN "Rules" RESET "\n");
    printf("3. " MAGENTA "Info" RESET "\n");
    printf("4. " RED "Exit" RESET "\n");
    printf("\n" BOLD "Enter your choice: " RESET);
}

void showRules() {
    clear_terminal();
    display_header("RULES");
    printf(GREEN "***************************************************\n" RESET);
    printf(BLUE    "1. The quiz contains 5 multiple-choice questions.\n" RESET);
    printf(YELLOW  "2. Each correct answer gives you 1 points.       \n" RESET);
    printf(MAGENTA "3. You must score as high as possible to win.    \n" RESET);
    printf(RED     "4. Enjoy the game and give your best!            \n" RESET);
    printf(GREEN "***************************************************\n" RESET);
    printf("\nPress Enter to return to the main menu...");
    getchar(); getchar(); // Pause hingga pengguna menekan Enter
    clear_terminal();
}

void showInfo() {
    clear_terminal();
    display_header("INFO");
    printf(MAGENTA "*******************************************************\n" RESET);
    printf(CYAN    "1. This quiz game is developed in C.                   \n" RESET);
    printf(YELLOW  "2. It demonstrates the use of functions, file handling,\n" RESET);
    printf(BLUE    "and user interactions for a simple text-based game.    \n" RESET);
    printf(MAGENTA "*******************************************************\n" RESET);
    printf("\nPress Enter to return to the main menu...");
    getchar(); getchar(); // Pause hingga pengguna menekan Enter
    clear_terminal();
}

// function to start Quiz
void start_quiz(){

    display_header("QUIZ TIME!");

    printf(BOLD "Starting the quiz in 5 seconds....\n" RESET);
    sleep(5);
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
    if (answer == 'D' || answer == 'd') score++;

    // Pertanyaan 2
    printf("\n2. Siapa Penulis buku Harry Potter\n");
    printf("A. Jane Austen\nB. William Shakespeare\nC. J.K Rowling\nD. Adolf Hitler\n");
    printf("Your Answer (A/B/C/D): ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') score++;

    // Pertanyaan 3
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


   // Display final score
    clear_terminal();
    printf(GREEN BOLD "************************************\n" RESET);
    printf(BOLD CYAN "           QUIZ OVER!               \n" RESET);
    printf(GREEN BOLD "************************************\n" RESET);
    printf(YELLOW "Your total score is: " RESET);
    printf(BOLD GREEN "%d/5\n" RESET, score);
    printf(MAGENTA "\nThank you for playing! <3\n" RESET);
    printf("\nPress Enter to return to the main menu...");
    // Tambahkan getchar untuk memastikan buffer kosong
    getchar(); 
    getchar(); // Tunggu pengguna menekan Enter sebelum kembali
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
        printf("Login berhasil. Akan dilanjutakan ke menu.\n");
        getchar(); // pause sebelum masuk menu
 } else
    {
        printf("Gagal login. Coba lagi");
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
                printf( BOLD MAGENTA "Makasih udah main <3\n" RESET);
                return EXIT_SUCCESS;
            default:
                printf(RED BOLD"Pilihan tidak valid. Coba lagi.\n"RESET);
                getchar(); // menangkap newline
                getchar(); // pause sebelum kembali ke menu
        }
    }    
    return 0;
}
