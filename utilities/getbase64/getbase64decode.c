#include "tomcrypt.h"
#include "stdio.h"
#include "string.h"

char *get_file(char *path){

   FILE *file;
   int length;
   char *contents;

   file = fopen (path, "r+");
   fseek(file ,0 ,SEEK_END);
   length = ftell(file);
   fseek(file ,0,SEEK_SET);

   contents = malloc(length + 1);
   fread (contents, 1, length , file );

   fclose(file );

   return contents;
}

int main(int count, char **arguments) {
   
   unsigned char *file, 
                  outlen[1024],
               de_outlen[1024];  
   unsigned long length1,length2 ;
  
   file = get_file(arguments[1]) ;
   length1=strlen(file);
   length2=sizeof(outlen);

   base64_encode(file,length1, outlen, &length2);

   base64_decode(outlen,length2,de_outlen, &length1);

   printf("%s\n", de_outlen);

   return 0;
}

