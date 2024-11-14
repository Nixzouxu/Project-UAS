#include <stdio.h>
#include <string.h>

int main(){
    
    // deklarasi variabel
    char kalimat[20] = "ini adalah kalimat";
    char *kata[10]; // alamat dari "kata" (Pointer)
    int banyakKata = 0;

    // pemecahan kalimat dengan pemisah nya adalah spasi (" ") menggunakan strtok
    // strtok = string token
    kata[0] = strtok(kalimat, " ");
    // menjadi : 
    /* ini menjadi 1 kata
       adalah menjadi 1 kata
       kalimat menjadi 1 kata
    */  
   while (kata[banyakKata++] != NULL) { // perulangan untuk mengiterasi variabel kalimat hingga variabel kata hingga menemukan null
        kata[banyakKata] = strtok(NULL, "");
   }
   printf("%s", kata[0]);
   return 0;
}
