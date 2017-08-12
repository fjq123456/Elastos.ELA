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

   file = get_file(arguments[1]);

   md5_init(&state);
   md5_process(&state, file, strlen(file));
   md5_done(&state, out);

   for(int i=0;i<strlen(out);i++){
       printf("%x",out[i]);
   }
   printf("\n");
   return 0;
}
