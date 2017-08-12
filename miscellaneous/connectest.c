
#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "sys/socket.h"
#include  "sys/types.h"
#include "netinet/in.h"
#include "arpa/inet.h"

int main(int count,char **arguments){

    int flag ,inner,len;
     struct sockaddr_in server;
     char buf[BUFSIZ];
     memset(&server,0,sizeof(server));

    //create socket
    inner = socket(AF_INET , SOCK_STREAM , 0);

    if(inner == -1){

       printf("socket() failed%c",10);
       exit(1);
     }

    printf("socket() succeed%d%c",inner,10);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr =inet_addr("47.94.19.190");
    server.sin_port = htons(6000);
    
   //connect to addr port

   flag = connect(inner ,(struct sockaddr *) &server , sizeof(struct sockaddr));

   if(flag== -1){

       printf("connect() failed%c",10);
       exit(1);
   }

     printf("connect() succeed%d%c",flag,10);

     len=recv(inner,buf,BUFSIZ,0);
      buf[len]='/0';
     printf("%s",buf);
    

       while(1){
         printf("Enter string to send:");
         scanf("%s",buf);
         if(!strcmp(buf,"quit")){
          break;
        }
        len=send(inner,buf,strlen(buf),0);
        len=recv(inner,buf,BUFSIZ,0);
        buf[len-1]='/0';
        printf("received:%s%c",buf,10);
     }
    
     close(inner);
     
}



