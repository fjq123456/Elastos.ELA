#include "rmd160.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


main(int *count, char **arguments){

   FILE *file;  
   unsigned long l1;    

   file = get_file(arguments[1]);

   dword out[1024];
   MDfinish(out, file, sizeof(out), strlen(file));   
    
   int i;

   printf("value of rmd160");
   printf("\n,,%d.%d .%d ,,", strlen(out), strlen(file), sizeof(out));
   
 //  for (i=0; i<strlen(out); i++){
   for (i=0; i<160; i++){

   printf("%02x,", out[i]);
   }


   printf("\n");


   return 0;

}
