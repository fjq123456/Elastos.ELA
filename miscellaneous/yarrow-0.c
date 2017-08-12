#include "tomcrypt.h"
#include "stdio.h"
#include "stdlib.h"

char *get_random() {

   FILE *file;
   char *buffer;

   buffer = malloc(100);

   int flag;

   file = fopen("/dev/urandom", "r");
   flag = fread(buffer, 1, 100, file);

   printf("fread: %d%c", flag, 10);

   return buffer;
}

int main(int count,char **arguments){
   
   prng_state prng;
   unsigned char buf[10];
   int err;

   if((err=yarrow_start(&prng))!=CRYPT_OK){
     printf("Start error:%s\n",error_to_string(error));
    }

   if((err=yarrow_add_entropy(get_random(),100,&prng))!=CRYPT_OK){
     printf("Add_entropy error:%s\n",error_to_string(error));
    }

    if((err=yarrow_ready(&prng))!=CRYPT_OK){
      printf("Ready error:%s\n",error_to_string(error));
    }

    // printf("Read %lu bytes from yarrow\n",yarrow_read(buf,sizeof(buf),&prng));

   yarrow_read(buf,sizeof(buf),&prng);
   printf("%02x%02x%02x%02x%c", buf[0], buf[1], buf[2], buf[3], 10);

    return 0;

}
