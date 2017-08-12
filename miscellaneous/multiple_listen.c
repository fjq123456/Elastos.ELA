
#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "sys/socket.h"
#include "sys/types.h"
#include "netinet/in.h"
#include "arpa/inet.h"

int main(int count,char **arguments) {

    int flag, inner, outer,sin_size,len;
    struct sockaddr_in address, server;
    char buf[BUFSIZ]; 
     
   memset(&address,0,sizeof(address));
   address.sin_family = AF_INET;
   address.sin_addr.s_addr = INADDR_ANY;
   address.sin_port = 28695;

   outer = socket(AF_INET, SOCK_STREAM, 0);

   if (outer == -1) {

      printf("socket() failed%c", 10);
      exit(1);
   }

   printf("socket() succeeded: %d%c", outer, 10);

   flag = bind(outer, (struct sockaddr *) &address, sizeof  (address));

   if (flag == -1) {

      printf("bind() failed%c", 10);
      exit(1);
   }

   printf("bind() succeeded%c", 10);

   flag = listen(outer, 64);
   sin_size=sizeof(struct sockaddr_in);

   if (flag == -1) {

      printf("listen() failed%c", 10);
      exit(1);
   }

   printf("listen() succeeded%c", 10);

   inner=accept(outer,(struct sockaddr *)&server,&sin_size);
   if(inner==-1){
      printf("accept() failed%c", 10);
      exit(1);
   
     }
   printf("accept() succeeded %s%c",inet_ntoa(server.sin_addr));
   len=send(inner,"Welcome to my server/n",21,0);


   while((len=recv(inner,buf,BUFSIZ,0)>0)){
      buf[len-1]='/0';  
      printf("%s%c",buf,10);
      if(send(inner,buf,len,0)==-1){
        printf("send() failed%c", 10);
        exit(1);
        
      } 
   }
   close(outer);
   close(inner);
  
}
