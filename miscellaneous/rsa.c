#define TFM_DESC
#include <tomcrypt.h>

void _start() {

   int digestor, flag, generator;
   rsa_key key;
   unsigned char *export;
   unsigned long count;

   if (register_prng(&sprng_desc) == -1)
      { _exit(1); }

	ltc_mp = tfm_desc;

   if (register_hash(&sha1_desc) == -1)
      { _exit(1); }

   generator = find_prng("sprng");
   digestor = find_hash("sha1");

   flag = rsa_make_key(0, generator, 128, 65537, &key);
   export = malloc(1024);
   flag = rsa_export(export, &count, 1, &key);

   printf("%d, %d, %d, %d%c", export[0], export[1], export[2], export[3], 10);
   _exit(1);
}
