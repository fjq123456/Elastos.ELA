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
   unsigned char out[16];
   char *file;

   file = get_file(arguments[1]);

   md5_init(&state);
   md5_process(&state, file, strlen(file));
   md5_done(&state, out);

   printf("%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%c", out[0], out[1], out[2], out[3], out[4], out[5], out[6], out[7], out[8], out[9], out[10], out[11], out[12], out[13], out[14], out[15], 10);

   return 0;
}
