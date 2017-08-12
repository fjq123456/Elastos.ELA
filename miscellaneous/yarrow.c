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

   return buffer;
}

int main(int count, char **arguments) {
   
   prng_state generator;
   unsigned char buffer[10];
   int error;

   if (yarrow_start(&generator) != 0)
      { exit(1); }

   exit(4);

   if (yarrow_add_entropy(get_random(), 100, &generator) != 0)
      { exit(2); }

   if (yarrow_ready(&generator) != 0)
      { exit(3); }

   yarrow_read(buffer, 10, &generator);
   printf("%02x%02x%02x%02x%c", buffer[0], buffer[1], buffer[2], buffer[3], 10);

   exit(0);
}
