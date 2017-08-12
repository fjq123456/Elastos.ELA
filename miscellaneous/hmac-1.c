#include "tomcrypt.h"

char *get_file(char *path) {

   FILE *file;
   int length;
   char *contents;

   file = fopen (path, "r+");
   fseek(file , 0 ,SEEK_END);
   length = ftell(file);
   fseek(file , 0 ,SEEK_SET);
   
   contents = malloc(length +1);
   fread(contents , 1 , length, file);

   fclose(file);

   return contents;
}

int main(int amount , char **arguments){
 
   int idx , flag;
   unsigned char key[16], dst[MAXBLOCKSIZE];
   unsigned long dstlen;
   char *file;

   if (register_hash(&sha256_desc) == -1){
   
      printf("error registering SHA256\n");
      return 0;
   }

   idx = find_hash("sha256");
//   file = get_file(arguments[1]);
   file = arguments[1];
   dstlen = sizeof(dst);
   flag = hmac_file(idx, file, key, 16, dst, &dstlen );
  
   if (flag !=CRYPT_OK){
     
      printf("error hmac_file...:%s\n", error_to_string(flag));
      exit(1);
   }
   
   printf("the hmac_file is %lu bypes long\n", dstlen);
   return 0 ;
}
