#define TFM_DESC
#include <tomcrypt.h>

int main(int count, char **arguments) {

   int digestor, flag, generator;
   rsa_key key;
   unsigned char *export;
   unsigned long count;

   if (register_prng(&sprng_desc) == -1)
      { exit(1); }

	ltc_mp = tfm_desc;

   if (register_hash(&sha1_desc) == -1)
      { exit(1); }

   generator = find_prng("sprng");
   digestor = find_hash("sha1");

   flag = rsa_make_key(0, generator, 128, 65537, &key);
   export = malloc(1024);
   flag = rsa_export(export, &count, 1, &key);

   printf("key: %d, %d, %d, %d%c", export[0], export[1], export[2], export[3], 10);
}


/*
int main(int argc,char * argv[]){


   int hash_idx;
   int prng_idx;
   int res, err;
   unsigned long l1, l2;
   unsigned char pt2[17] = { NULL }, out[1024] = { NULL }, out2[1024] = { NULL }, out3[1024] = { NULL };
   rsa_key key;

	int round = 0;
	if (register_prng(&sprng_desc) == -1)
	{
		return EXIT_FAILURE;
	}

	ltc_mp = tfm_desc;


	if (register_hash(&sha1_desc) == -1)
	{		
		return EXIT_FAILURE;
	}

	hash_idx = find_hash("sha1");
	prng_idx = find_prng("sprng");

	err = rsa_make_key(NULL,
		prng_idx,
		1024 / 8,
		65537,
		&key);
	if (err != CRYPT_OK)
	{
		printf("rsa make_key %s", error_to_string(err));
		return EXIT_FAILURE;
	}
        printf("hello world\n"); 
        if ((err = rsa_export(out, &l1, PK_PRIVATE, &key)) !=CRYPT_OK)
	{
		printf("rsa export %s", error_to_string(err));
		return EXIT_FAILURE;
	}

        printf("%x,%x,%x,%x shiyu \n",out[0], out[1], out[2], out[3]);        
    
	return 0;
}
*/
