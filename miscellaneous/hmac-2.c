#include "tomcrypt.h"

int main(int amount , char **arguments){
 
   int idx , flag;
   unsigned char key[16], dst[MAXBLOCKSIZE];
   unsigned long dstlen;

   if (register_hash(&sha256_desc) == -1){
   
      printf("error registering SHA256\n");
      return 0;
   }

   idx = find_hash("sha256");
   dstlen = sizeof(dst);
   flag = hmac_memory(idx, key, 16, "hello", 5, dst, &dstlen );
  
   if (flag !=CRYPT_OK){
     
      printf("error hmac_memory:%s\n", error_to_string(flag));
      exit(1);
   }
   
   printf("the hmac_memory is %lu bypes long\n", dstlen);
   return 0 ;
}
