#include "rmd160.h"

int main(int count, char **arguemnts){

   unsigned char out[160];
   memset(out, 0, 160);
   unsigned long l1;
   
   l1 = sizeof(out);
  
   MDfinish(&out, "abc", l1, 3 );

   for(int i=0; i<l1; i++){

      printf("%x",out[i]);
   }
      printf("\n");

   return 0;
}
