#define TFM_DESC
#include <tomcrypt.h>
#include <string.h>

int main(int argc,char **arguments){

   int hash_idx;
   int prng_idx;
   int err;
   unsigned long l1, l2;
   unsigned char prk_out[1024],
                 puk_out[1024];
     
   memset(prk_out, 0, 1024);
   memset(puk_out, 0, 1024);
	
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
                err = ecc_export(prk_out, &l1, PK_PUBLIC, &key);

	if (err != CRYPT_OK)
	{
		printf("ecc_export%s", error_to_string(err));
		return EXIT_FAILURE;
	}

        int i;

        printf("private key:");

        for (i=0; i<l1; i++){
        
        printf("%x", prk_out[i]);
        }		
        printf("\n");

        err = ecc_export(prk_out, &l2, PK_PRIVATE, &key);

	if (err != CRYPT_OK)
	{
		printf("ecc_export%s", error_to_string(err));
		return EXIT_FAILURE;
	}

        int j;

        printf("public key:");

        for (j=0; j<l2; j++){
        
        printf("%x", prk_out[j]);
        }		
        printf("\n");


	return 0;
}



