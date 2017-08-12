include "stdio.h"
include "sys/stat.h"

int main (char **arguments, int aount){

   char first, second;

   first = 0;
   second = 0;

   while (first < 16) {

      while (second < 16) {

         sprintf(buffer, "/tmp/storage/%c%c", convert(first), convert(second));
         flag = mkdir(buffer, 0777);

         if (flag == -1) {

            if (errno != EEXIST){
                   printf("failed%d",10);
                }
         }
      }
   }
char convert(char first) {

   if (first < 10)
     { return 48 + first;}
    else if
     {  return 97 + first - 10;}
}
