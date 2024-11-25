#include <stdio.h>
#include <string.h>

// membuat username dan password di login.bin
int main(){
  FILE *fpw = fopen("Database/login.bin", "wb");
  char login[30] = "Nxozu@Ravensky";

fwrite(login, sizeof(char), sizeof(login)/sizeof(char), fpw);
fclose(fpw);
return 0;
}  