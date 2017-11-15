#include "eckey.h"
#include <openssl/ec.h>
#include <openssl/ecdsa.h>   // for ECDSA_do_sign, ECDSA_do_verify
#include <openssl/ssl.h>
#include <openssl/bio.h>




EC_KEY * generate_eckey(int nid) 
{
    EC_KEY *eckey=EC_KEY_new();
    EC_GROUP *ecgroup= EC_GROUP_new_by_curve_name(nid);
    EC_KEY_set_group(eckey, ecgroup);
    EC_KEY_generate_key(eckey);

    return eckey;
}


void write_private_key_to_pem(const char *priv_key_file_name, EC_KEY *eckey)
{
    FILE *fp = fopen(priv_key_file_name, "w");
    PEM_write_ECPrivateKey(fp, eckey, NULL, NULL, 0, NULL, NULL);
    fclose(fp);
    
    return;
}


EC_KEY *read_private_key_from_pem(const char *priv_key_file_name)
{
    FILE *fp = fopen(priv_key_file_name, "r");
    EC_KEY *eckey = PEM_read_ECPrivateKey(fp, NULL, NULL, NULL);
    fclose(fp);
    
    return eckey;
}

void write_public_key_to_pem(const char *pubkey_file_name, EC_KEY *eckey)
{
    BIO *out = BIO_new_file(pubkey_file_name, "w");
    if(out == NULL)
    {
        printf("write public key to pem file failed! (%s:%d)\n", __FILE__,__LINE__);
    }
    PEM_write_bio_EC_PUBKEY(out, eckey);
    BIO_free(out);
    
    return ;
}

EC_KEY *read_public_key_from_pem(const char *pubkey_file_name)
{
    BIO *in = BIO_new_file(pubkey_file_name, "r");
    EC_KEY *eckey = EC_KEY_new();
    eckey = PEM_read_bio_EC_PUBKEY(in, &eckey, NULL, NULL);
    if (eckey == NULL)
    {
        printf("read public key pem failed! (%s:%d)\n", __FILE__, __LINE__);
    }
    BIO_free(in);
    
    return eckey;
}



int ecdsa_sign(const unsigned char *data, int datalen, 
				unsigned char *sig, unsigned int *siglen, EC_KEY *eckey)
{
	unsigned char md[EVP_MAX_MD_SIZE] = {0};
	unsigned int mdlen;
	
	EVP_Digest(data, datalen, md, &mdlen, EVP_sha256(), NULL);
	
	return ECDSA_sign(0, md, mdlen, sig, siglen, eckey);
}



int ecdsa_verify(const unsigned char *data, int datalen, 
				const unsigned char *sig, int siglen, EC_KEY *eckey)
{
	unsigned char md[EVP_MAX_MD_SIZE] = {0};
	unsigned int mdlen;
	
	EVP_Digest(data, datalen, md, &mdlen, EVP_sha256(), NULL);
	
	return ECDSA_verify(0,md, mdlen, sig, siglen, eckey);
}