
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/obj_mac.h> // for curves list


/*generate ec key*/
EC_KEY * generate_eckey(int nid);


void write_private_key_to_pem(const char *priv_key_file_name, EC_KEY *eckey);
EC_KEY *read_private_key_from_pem(const char *priv_key_file_name);

void write_public_key_to_pem(const char *pubkey_file_name, EC_KEY *eckey);
EC_KEY *read_public_key_from_pem(const char *pubkey_file_name);

int ecdsa_sign(const unsigned char *data, int datalen, 
				unsigned char *sig, unsigned int *siglen, EC_KEY *eckey);
int ecdsa_verify(const unsigned char *data, int datalen, 
				const unsigned char *sig, int siglen, EC_KEY *eckey);