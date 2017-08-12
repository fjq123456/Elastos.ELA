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

   int idx, err;
   unsigned long len;

   char *files;

   files = get_file(arguments[1]);

   
   unsigned char out[MAXBLOCKSIZE];
   
   /* register the hash */
   
   if (register_hash(&sha256_desc) == -1) {
   
      printf("Error registering SHA-256.\n");
   return -1;
   }
   
   /* get the index of the hash */
   
   idx = find_hash("sha256");
   /* call the hash */
   
   len = sizeof(out);
   
   if ((err =hash_memory(idx, files, strlen(files), out, &len)) != CRYPT_OK) {
     
      printf("Error hashing data: %s\n", error_to_string(err));
      return -1;
   }

   for(int i=0;i<len;i++){
      printf("%x", out[i]);
   }
      printf("\n");

   return 0;
}
