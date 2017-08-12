#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/socket.h"
#include "arpa/inet.h" //inet_addr

int main(int count,char **arguments){

    int flag ,outer;
    struct sockaddr_in address;

    //create socket
    outer = socket(AF_INET , SOCK_STREAM , 0);

    if(outer == -1){

       printf("socket() failed%c",10);
       exit(1);
     }

    printf("socket() succeed%d%c",outer,10);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(6000);
    
   //connect to addr port

   flag = connect(outer ,(const struct sockaddr *) &address , sizeof(address));

   if(flag == -1){

       printf("connect() failed%c",10);
       exit(1);
   }

    printf("connect() succeed%d%c",flag,10);

}



