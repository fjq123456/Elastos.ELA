#define TFM_DESC
#include <tomcrypt.h>
#include <string.h>

char *get_file(char *path) {

   FILE *file;
   int length;
   char *contents;

   file = fopen(path, "r+");
   fseek(file, 0, SEEK_END);
   length = ftell(file);
//   fseek(file, 0, SEEK_SET);

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
	unsigned long l1, l2, l3;
        unsigned char hash_out[256],
                           out[1024],
                        en_out[512],
                        de_out[512];
     
        memset(hash_out, 0, 256);
        memset(out, 0, 1024);
        memset(en_out, 0, 512);
        memset(de_out, 0, 512);
	
        ecc_key key;
        const ltc_ecc_set_type dp[]={32,    
                          "ECC-256",
        "FFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF", 
        "5AC635D8AA3A93E7B3EBBD55769886BC651D06B0CC53B0F63BCE3C3E27D2604B",
        "FFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551", 
        "6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296", 
        "4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5"} 
                                 ;
                

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

	err = ecc_make_key_ex(0, prng_idx, &key, dp);

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
 
   memset(buf, 0, 256);

   if((err=yarrow_start(&prng))!=CRYPT_OK){
     printf("Start error:%s\n",error_to_string(err));
    }

   if((err=yarrow_add_entropy(get_random(),100,&prng))!=CRYPT_OK){
     printf("Add_entropy error:%s\n",error_to_string(err));
    }

    if((err=yarrow_ready(&prng))!=CRYPT_OK){
      printf("Ready error:%s\n",error_to_string(err));
    }


   yarrow_read(buf,sizeof(buf),&prng);

        err = ecc_encrypt_key(file, strlen(file), en_out, &l2, &prng, prng_idx, hash_idx,  &key);        
//        err = ecc_encrypt_key(hash_out, sizeof(hash_out),sign_out, &l2, &prng, prng_idx, &key);        
//        printf(",.%d.,\n", l2);        
        
     	if (err != CRYPT_OK)
	{
		printf("ecc_encrypt_key %s", error_to_string(err));
		return EXIT_FAILURE;
	}

        printf("encrypt value: ");        
        
        int i;
        for(i=0;i<l2;i++){
                printf("%x",en_out[i]); 
        }            
                printf("\n"); 
      
    

        err = ecc_decrypt_key(en_out, l2, de_out, &l3, &key);

     	if (err != CRYPT_OK)
	{
		printf("ecc_decrypt_key %s", error_to_string(err));
		return EXIT_FAILURE;
	}

        printf("decrypt value:\n");        
        
        int j;
        for(j=0;j<l3;j++){
                printf("%x",de_out[j]); 
        }            
                printf("\n"); 
                
	return 0;
}


