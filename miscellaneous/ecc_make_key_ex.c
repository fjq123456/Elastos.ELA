#define TFM_DESC
#include <tomcrypt.h>

char *get_file(char *path) {

   FILE *file;
   int length;
   char *contents;

   file = fopen(path, "r+");
   fseek(file, 0, SEEK_END);
   length = ftell(file);
   fseek(file, 0, SEEK_SET);

   contents = malloc(length + 1);
   fread(contents, 1, length, file);

   fclose(file);

   return contents;
}

char *get_random() {

   FILE *file;
   char *buffer;

   buffer = malloc(100);

   int flag;

   file = fopen("/dev/urandom", "r");
   flag = fread(buffer, 1, 100, file);

   printf("fread: %d%c", flag, 10);

   return buffer;
}


int main(int argc,char **arguments){

	int hash_idx;
	int prng_idx;
	int res, err;
	unsigned long l1, l2;
	unsigned char hash_out[256] = { NULL }, out[1024] = { NULL }, sign_out[256] = { NULL };
	ecc_key key;
        const ltc_ecc_set_type dp[]={32,    
                          "ECC-256",
        "FFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF", 
        "5AC635D8AA3A93E7B3EBBD55769886BC651D06B0CC53B0F63BCE3C3E27D2604B",
        "FFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551", 
        "6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296", 
        "4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5"} 
                                 ;
                

	int round = 0;
	if (register_prng(&sprng_desc) == -1)
	{
		printf("register prng error");
		return EXIT_FAILURE;
	}

	ltc_mp = tfm_desc;


	if (register_hash(&sha256_desc) == -1)
	{		
		printf("register hash error");
		return EXIT_FAILURE;
	}

	hash_idx = find_hash("sha256");

	prng_idx = find_prng("sprng");

	err = ecc_make_key_ex(NULL, prng_idx, &key, &dp);

	if (err != CRYPT_OK)
	{
		printf("ecc make_key %s", error_to_string(err));
		return EXIT_FAILURE;
	}
        
        hash_state state;
        char *file;      
     
        file = get_file(arguments[1]);

        sha256_init(&state);
        sha256_process(&state, file, strlen(file));
        sha256_done(&state, hash_out);


   prng_state prng;
   unsigned char buf[256];

   if((err=yarrow_start(&prng))!=CRYPT_OK){
     printf("Start error:%s\n",error_to_string(err));
    }

   if((err=yarrow_add_entropy(get_random(),100,&prng))!=CRYPT_OK){
     printf("Add_entropy error:%s\n",error_to_string(err));
    }

    if((err=yarrow_ready(&prng))!=CRYPT_OK){
      printf("Ready error:%s\n",error_to_string(err));
    }


   yarrow_read(buf, sizeof(buf), &prng);

        err = ecc_sign_hash(hash_out, sizeof(hash_out),sign_out, &l2, buf, prng_idx, &key);        
        
     	if (err != CRYPT_OK)
	{
		printf("ecc_sign_hash %s", error_to_string(err));
		return EXIT_FAILURE;
	}

        printf("signature value: ");        
        
        for(int i=0;i<75;i++){
                printf("%02x,",sign_out[i]); 
        }            
                printf("\n"); 
      
        int *stat;
                  
        err = ecc_verify_hash(sign_out, &l2, hash_out, sizeof(hash_out), &stat, &key);        
        
     	if (err != CRYPT_OK)
	{
		printf("ecc_verify_hash %s", error_to_string(err));
		return EXIT_FAILURE;
	}

   printf("return non-value if the signature is valid: %d\n", stat);               

	return 0;
}


