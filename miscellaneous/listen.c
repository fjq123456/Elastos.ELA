#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "sys/socket.h"
#include "arpa/inet.h"

int main(char **arguments, int count) {

   int flag, inner, outer;
   struct sockaddr_in address;

   address.sin_family = AF_INET;
   address.sin_addr.s_addr = INADDR_ANY;
   address.sin_port = 28695;

   outer = socket(AF_INET, SOCK_STREAM, 0);

   if (outer == -1) {

      printf("socket() failed%c", 10);
      exit(1);
   }

   printf("socket() succeeded: %d%c", outer, 10);

   flag = bind(outer, (struct sockaddr *) &address, sizeof (address));

   if (flag == -1) {

      printf("bind() failed%c", 10);
      exit(1);
   }

   printf("bind() succeeded%c", 10);

   flag = listen(outer, 64);

   if (flag == -1) {

      printf("listen() failed%c", 10);
      exit(1);
   }

   printf("listen() succeeded%c", 10);

   inner = accept(outer, 0, 0);

   if (inner == -1) {

      printf("accept() failed%c", 10);
      exit(1);
   }

   printf("accept() succeeded%c", 10);
}
