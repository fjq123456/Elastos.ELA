#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "assorted.h"
#include "storage.h"

int main(int _3840, char **_2458)
{
   struct storage *storage;
   struct record *record;

   storage = create_storage("", "/tmp/chain");
   record = create_record("", "hello");
   update_storage(storage, record);
}

int test_0428()
{
   char *_6247;

   _6247 = string_wrap("hello world");
   _6247 = string_slice(_6247, 0, 10);
   _6247 = string_unwrap(_6247);

   printf("%s == %s%c", "hello worl", _6247, 10);
}

int test_9881()
{
   char *_6247;

   _6247 = string_wrap("hello world");
   _6247 = string_slice(_6247, 0, 11);
   _6247 = string_unwrap(_6247);

   printf("%s == %s%c", "hello world", _6247, 10);
}
