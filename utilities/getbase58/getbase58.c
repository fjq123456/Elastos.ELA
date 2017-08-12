#include "libbase58.h"
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

int main(int count,  char **arguments){

   unsigned char b58[1000];
   unsigned long  l1;

   char *file;
   file = get_file(arguments[1]);


   b58enc(b58, &l1, file, strlen(file));  
   printf("%s\n", b58);

   return 0 ;
}
