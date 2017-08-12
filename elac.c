/* Elastos Coin */

/* This file was written in 2017 by Yuan Xun. */

/* The license for this file has not yet been determined.
   Yuan Xun is hoping that some of these component files
   may be dual-licensed under the GPL and the Unlicense.
   Whereas the GPL is a strong libre license, the
   Unlicense is a weak libre license. This does not have
   to be a permanent arrangement. Mr Yuan would be
   contented if this happened only for the first one or
   two prereleases of Elastos Coin. That way, any useful
   subroutines of a customary nature contained within the
   codebase may be utilized by those who have possible
   disagreements with the GPL. */

/* The text of the Unlicense (without the second
   paragraph, which may not be necessary) is as follows: */

/* This is free and unencumbered software released into
   the public domain. Anyone is free to copy, modify,
   publish, use, compile, sell, or distribute this
   software, either in source code form or as a compiled
   binary, for any purpose, commercial or non-commercial,
   and by any means. In jurisdictions that recognize
   copyright laws, the author or authors of this software
   dedicate any and all copyright interest in the
   software to the public domain. We make this dedication
   for the benefit of the public at large and to the
   detriment of our heirs and successors. We intend this
   dedication to be an overt act of relinquishment in
   perpetuity of all present and future rights to this
   software under copyright law. */

/* The text of the GPL (the second version) is as
   follows: */

/* The text of the GPL (the third version) is as follows: */

#define TFM_DESC

#include "arpa/inet.h"
#include "dirent.h"
#include "netinet/in.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/socket.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "tomcrypt.h"
#include "unistd.h"

/* getinfo = 94, getwork = 81, submitblock = 35, addpeer = 21 */

// submit block is the number followed by size followed by block

struct _5349 {

   void *tag;
};

int main(int count, char **arguments) {

   int connection;
   struct sockaddr_in address;

   address.sin_family = 2;
   address.sin_port = htons(6005);
   address.sin_addr.s_addr = inet_addr("127.0.0.1");
   memset(address.sin_zero, 0, sizeof address.sin_zero);

   if ((connection = socket(2, 1, 0)) == -1)
      return 8155;

   if ((connect(connection, (struct sockaddr *) &address, sizeof address)) == -1)
      return 9018;

//   unsigned char *buffer = malloc(1000);
//   recv(connection, buffer, 6, 0);
//   printf("%s%c", buffer, 10);

   _exit(0);
}
