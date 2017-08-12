#include "stdio.h"
#include "tomcrypt.h"
#include "tommath.h"

char *get_random() {

   FILE *file;
   char *buffer;

   buffer = malloc(10000);

   int flag;

   file = fopen("/dev/urandom", "r");
   flag = fread(buffer, 1, 10000, file);

   printf("fread: %d%c", flag, 10);

   return buffer;
}

void _start() {

   int flag;
   unsigned char *buffer;
   prng_state generator;

   buffer = malloc(100);

   flag = yarrow_start(&generator);
   printf("%d%c", flag, 10);
   flag = yarrow_add_entropy(get_random(), 10000, &generator);
   printf("%d%c", flag, 10);
   flag = yarrow_ready(&generator);
   printf("%d%c", flag, 10);
   flag = yarrow_read(buffer, 10, &generator);
   printf("%d%c", flag, 10);

   printf("%02x%02x%02x%02x%c", buffer[0], buffer[1], buffer[2], buffer[3], 10);
   _exit(0);
}
