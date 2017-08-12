#include "tomcrypt.h"

int main(int amount , char **arguments){
 
   int idx , flag;
   hmac_state hmac;
   unsigned char key[16], dst[MAXBLOCKSIZE];
   unsigned long dstlen;

   if (register_hash(&sha256_desc) == -1){
   
      printf("error registering SHA1\n");
      return 0;
   }

   idx = find_hash("sha256");
   flag = hmac_init( &hmac ,idx, key, 16);
  
   if (flag !=CRYPT_OK){
     
      printf("error setting up hmac:%s\n", error_to_string(flag));
      exit(1);
   }
   
   flag = hmac_process(&hmac, "hello",5);   

   if (flag !=CRYPT_OK){
     
      printf("error process up hmac:%s\n", error_to_string(flag));
      exit(1);
   }
   
   dstlen = sizeof(dst);
   flag = hmac_done(&hmac, dst, &dstlen);

   if (flag !=CRYPT_OK){
     
      printf("error done up hmac:%s\n", error_to_string(flag));
      exit(1);
   }

//   printf("the hmac is %lu bypes long\n%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x\n", dstlen,dst[0], dst[1], dst[2],dst[3], dst[4],dst[5], dst[6], dst[7],dst[8], dst[9], dst[10], dst[11], dst[12], dst[13], dst[14], dst[15],dst[16],dst[17], dst[18], dst[19], dst[20], dst[21], dst[22],dst[23],dst[24], dst[25], dst[26], dst[27],dst[28], dst[29],dst[30], dst[31]);
   printf("the hmac is %lu bypes long\n");
   return 0 ;
}
