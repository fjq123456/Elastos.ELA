#define TFM_DESC

#include "tomcrypt.h"
#include "stdio.h"
#include "stdlib.h"

char *get_random(int count) {

   FILE *file;
   char *buffer;

   buffer = malloc(count + 1);
   buffer[count] = 0;

   int flag;

   file = fopen("/dev/urandom", "r");
   flag = fread(buffer, 1, count, file);

   printf("fread: %d%c", flag, 10);

   return buffer;
}

int main(int count, char **arguments){

   prng_state generator;
   ecc_key key[32];

   register_prng(&yarrow_desc);

   ltc_mp = tfm_desc;

   yarrow_start(&generator);
   yarrow_add_entropy(get_random(500), 500, &generator);
   yarrow_ready(&generator);
   int flag = ecc_make_key(&generator, 10, 32, key);

   printf("%d%c", flag, 10);

   return 0;
}
