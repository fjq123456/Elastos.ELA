#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// /tmp/storage

int main(char **arguments, int count) {

   DIR *folder;
   struct dirent *entry;

   folder = opendir("/tmp/storage");

   if (! folder) {

      printf("the folder could not be opened%c", 10);
      exit(1);
   }

   while (1) {

      entry = readdir(folder);

      if (! entry)
         { break; }

      if (strcmp(entry->d_name, ".") == 0)
         { continue; }

      if (strcmp(entry->d_name, "..") == 0)
         { continue; }

      printf("%s%c", entry->d_name, 10);
   }
}
