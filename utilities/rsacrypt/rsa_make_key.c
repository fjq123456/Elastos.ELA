#define TFM_DESC
#include <tomcrypt.h>

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
		printf("伪随机数生成错误！");
		return EXIT_FAILURE;
	}

	ltc_mp = tfm_desc;


	if (register_hash(&sha1_desc) == -1)
	{		
		printf("注册数学库失败！");
		return EXIT_FAILURE;
	}

	hash_idx = find_hash("sha1");

	prng_idx = find_prng("sprng");

	err = rsa_make_key(NULL,/*PRNG state*/
		prng_idx,/*PRNG idx*/
		1024 / 8,/*1024-bit key*/
		65537,/*we like e=65537*/
		&key);/*where to store the key*/
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


