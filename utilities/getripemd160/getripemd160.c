#include "tomcrypt.h"

char *get_file(char *path) {

   FILE *file;
   int length;
   char *contents;

   file = fopen(path, "r+");
   fseek(file, 0, SEEK_END);
   length = ftell(file);
   fseek(file, 0, SEEK_SET);

   contents = malloc(length + 1);
   fread(contents, 1, length, file);

   fclose(file);

   return contents;
}

int main(int count, char **arguments) {

   hash_state state;
   unsigned char out[160];
   char *file;
   unsigned long x;   
   int flag;
   x=sizeof(out);
   file = get_file(arguments[1]);
   
   if((flag=rmd160_init(&state))!=CRYPT_OK){
     printf("rmd160_init error: %s\n", error_to_string(flag));
     return -1;
  }

   if((flag=rmd160_process(&state, file, strlen(file)))!=CRYPT_OK){
     printf("rmd160_process error: %s\n", error_to_string(flag));
     return -1;  
  }

   if((flag=rmd160_done(&state, out))!=CRYPT_OK){
     printf("rmd160_done error: %s\n", error_to_string(flag));
     return -1;
  }


   for(int i=0;i<strlen(out);i++){
       printf("%x", out[i]);
   }
   printf("\n");
   return 0;
}
