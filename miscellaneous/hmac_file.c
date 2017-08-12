#include "tomcrypt.h"

int main(int amount , char **arguments){
 
   int idx , flag;
   unsigned char key[16], dst[MAXBLOCKSIZE];
   unsigned long dstlen;
   char *file;

   if (register_hash(&md5_desc) == -1){
   
      printf("error registering md5\n");
      return 0;
   }

   idx = find_hash("md5");
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
