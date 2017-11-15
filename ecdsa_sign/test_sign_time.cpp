#include <iostream>
#include <sys/time.h>
#include <string.h>
#include <openssl/ec.h>
#include "test_sign_time.h"
#include "eckey.h"

static void test_sign_verify_time(char *buff, int nid, char *name)
{
	std::cout << name << "====================================================>>>" << std::endl; 
	
	EC_KEY *key = generate_eckey(nid);
	int len = ECDSA_size(key);
	unsigned char *sig = (unsigned char*)malloc(sizeof(char) * len);
	unsigned int siglen;
	
	struct timeval timestamp1, timestamp2, timestamp3, timestamp4;
	gettimeofday(&timestamp1,NULL); 
	int sign_ret = ecdsa_sign((unsigned char*)buff, strlen(buff), sig, &siglen, key);
	gettimeofday(&timestamp2,NULL); 
	gettimeofday(&timestamp3,NULL); 
	int vrf_ret = ecdsa_verify((unsigned char*)buff, strlen(buff), sig, siglen, key);
	gettimeofday(&timestamp4,NULL); 
	
	if(1 == sign_ret && 1 == vrf_ret)
	{
		std::cout << "sign time  : " << ((timestamp2.tv_sec*1000000 + timestamp2.tv_usec) - (timestamp1.tv_sec*1000000 + timestamp1.tv_usec)) << " ---->>>success" << std::endl;
		std::cout << "verify time: " << ((timestamp4.tv_sec*1000000 + timestamp4.tv_usec) - (timestamp3.tv_sec*1000000 + timestamp3.tv_usec)) << " ---->>>success" << std::endl;
	}
	else if(1 != sign_ret)
	{
		std::cout << "sign failed!" << std::endl;
	}
	else if(1 != vrf_ret)
	{
		std::cout << "verify failed!" << std::endl;
	}
	
	free(sig);
}


void test_time()
{
	char *buff = "hello world";
	
	//NID_secp112r1
	test_sign_verify_time(buff, NID_secp112r1, "NID_secp112r1");

	//NID_secp112r2
	test_sign_verify_time(buff, NID_secp112r2, "NID_secp112r2");
	
	//NID_secp128r1 
	test_sign_verify_time(buff, NID_secp128r1, "NID_secp128r1");
	
	//NID_secp128r2
	test_sign_verify_time(buff, NID_secp128r2, "NID_secp128r2");
	
	//NID_secp160k1
	test_sign_verify_time(buff, NID_secp160k1, "NID_secp160k1");
	
	//NID_secp160r1
	test_sign_verify_time(buff, NID_secp160r1, "NID_secp160r1");
	
	//NID_secp224k1
	test_sign_verify_time(buff, NID_secp224k1, "NID_secp224k1");
	
	//NID_secp224r1
	test_sign_verify_time(buff, NID_secp224r1, "NID_secp224r1");
	
	//NID_secp224r1
	test_sign_verify_time(buff, NID_secp224r1, "NID_secp224r1");
	
	//NID_secp256k1
	test_sign_verify_time(buff, NID_secp256k1, "NID_secp256k1");
	
	//NID_secp384r1
	test_sign_verify_time(buff, NID_secp384r1, "NID_secp384r1");
	
	//NID_secp521r1
	test_sign_verify_time(buff, NID_secp521r1, "NID_secp521r1");
	
	//NID_secp521r1
	test_sign_verify_time(buff, NID_secp521r1, "NID_secp521r1");
	
	//NID_X9_62_prime192v1
	test_sign_verify_time(buff, NID_X9_62_prime192v1, "NID_X9_62_prime192v1");
	
	//NID_X9_62_prime192v2
	test_sign_verify_time(buff, NID_X9_62_prime192v2, "NID_X9_62_prime192v2");
	
	//NID_X9_62_prime192v3
	test_sign_verify_time(buff, NID_X9_62_prime192v3, "NID_X9_62_prime192v3");
	
	//NID_X9_62_prime239v1
	test_sign_verify_time(buff, NID_X9_62_prime239v1, "NID_X9_62_prime239v1");
	
	//NID_X9_62_prime239v2
	test_sign_verify_time(buff, NID_X9_62_prime239v2, "NID_X9_62_prime239v2");
	
	//NID_X9_62_prime239v3
	test_sign_verify_time(buff, NID_X9_62_prime239v3, "NID_X9_62_prime239v3");
	
	//NID_X9_62_prime256v1
	test_sign_verify_time(buff, NID_X9_62_prime256v1, "NID_X9_62_prime256v1");
	
	//NID_sect113r1
	test_sign_verify_time(buff, NID_sect113r1, "NID_sect113r1");
	
	//NID_sect113r2
	test_sign_verify_time(buff, NID_sect113r2, "NID_sect113r2");
	
	//NID_sect131r1
	test_sign_verify_time(buff, NID_sect131r1, "NID_sect131r1");
	
	//NID_sect131r2
	test_sign_verify_time(buff, NID_sect131r2, "NID_sect131r2");
	
	//NID_sect163k1
	test_sign_verify_time(buff, NID_sect163k1, "NID_sect163k1");
	
	//NID_sect163r1
	test_sign_verify_time(buff, NID_sect163r1, "NID_sect163r1");
	
	//NID_sect163r2
	test_sign_verify_time(buff, NID_sect163r2, "NID_sect163r2");
	
	//NID_sect193r1
	test_sign_verify_time(buff, NID_sect193r1, "NID_sect193r1");
	
	//NID_sect193r2
	test_sign_verify_time(buff, NID_sect193r2, "NID_sect193r2");
	
	//NID_sect233k1
	test_sign_verify_time(buff, NID_sect233k1, "NID_sect233k1");
	
	//NID_sect233r1
	test_sign_verify_time(buff, NID_sect233r1, "NID_sect233r1");
	
	//NID_sect239k1
	test_sign_verify_time(buff, NID_sect239k1, "NID_sect239k1");
	
	//NID_sect283k1
	test_sign_verify_time(buff, NID_sect283k1, "NID_sect283k1");
	
	//NID_sect283r1
	test_sign_verify_time(buff, NID_sect283r1, "NID_sect283r1");
	
	//NID_sect409k1
	test_sign_verify_time(buff, NID_sect409k1, "NID_sect409k1");
	
	//NID_sect409r1
	test_sign_verify_time(buff, NID_sect409r1, "NID_sect409r1");
	
	//NID_sect571k1
	test_sign_verify_time(buff, NID_sect571k1, "NID_sect571k1");
	
	//NID_sect571r1
	test_sign_verify_time(buff, NID_sect571r1, "NID_sect571r1");
	
	//NID_X9_62_c2pnb163v1
	test_sign_verify_time(buff, NID_X9_62_c2pnb163v1, "NID_X9_62_c2pnb163v1");
	
	//NID_X9_62_c2pnb163v2
	test_sign_verify_time(buff, NID_X9_62_c2pnb163v2, "NID_X9_62_c2pnb163v2");
	
	//NID_X9_62_c2pnb163v3
	test_sign_verify_time(buff, NID_X9_62_c2pnb163v3, "NID_X9_62_c2pnb163v3");
	
	//NID_X9_62_c2pnb176v1
	test_sign_verify_time(buff, NID_X9_62_c2pnb176v1, "NID_X9_62_c2pnb176v1");
	
	//NID_X9_62_c2tnb191v1
	test_sign_verify_time(buff, NID_X9_62_c2tnb191v1, "NID_X9_62_c2tnb191v1");
	
	//NID_X9_62_c2tnb191v2
	test_sign_verify_time(buff, NID_X9_62_c2tnb191v2, "NID_X9_62_c2tnb191v2");
	
	//NID_X9_62_c2tnb191v3
	test_sign_verify_time(buff, NID_X9_62_c2tnb191v3, "NID_X9_62_c2tnb191v3");
	
	//NID_X9_62_c2pnb208w1
	test_sign_verify_time(buff, NID_X9_62_c2pnb208w1, "NID_X9_62_c2pnb208w1");
	
	//NID_X9_62_c2tnb239v1
	test_sign_verify_time(buff, NID_X9_62_c2tnb239v1, "NID_X9_62_c2tnb239v1");
	
	//NID_X9_62_c2tnb239v2
	test_sign_verify_time(buff, NID_X9_62_c2tnb239v2, "NID_X9_62_c2tnb239v2");
	
	//NID_X9_62_c2tnb239v3
	test_sign_verify_time(buff, NID_X9_62_c2tnb239v3, "NID_X9_62_c2tnb239v3");
	
	//NID_X9_62_c2pnb272w1
	test_sign_verify_time(buff, NID_X9_62_c2pnb272w1, "NID_X9_62_c2pnb272w1");
	
	//NID_X9_62_c2pnb304w1
	test_sign_verify_time(buff, NID_X9_62_c2pnb304w1, "NID_X9_62_c2pnb304w1");
	
	//NID_X9_62_c2tnb359v1
	test_sign_verify_time(buff, NID_X9_62_c2tnb359v1, "NID_X9_62_c2tnb359v1");
	
	//NID_X9_62_c2pnb368w1
	test_sign_verify_time(buff, NID_X9_62_c2pnb368w1, "NID_X9_62_c2pnb368w1");
	
	//NID_X9_62_c2tnb431r1
	test_sign_verify_time(buff, NID_X9_62_c2tnb431r1, "NID_X9_62_c2tnb431r1");
	
	//NID_wap_wsg_idm_ecid_wtls1
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls1, "NID_wap_wsg_idm_ecid_wtls1");
	
	//NID_wap_wsg_idm_ecid_wtls3
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls3, "NID_wap_wsg_idm_ecid_wtls3");
	
	//NID_wap_wsg_idm_ecid_wtls4
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls4, "NID_wap_wsg_idm_ecid_wtls4");
	
	//NID_wap_wsg_idm_ecid_wtls5
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls5, "NID_wap_wsg_idm_ecid_wtls5");
	
	//NID_wap_wsg_idm_ecid_wtls6
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls6, "NID_wap_wsg_idm_ecid_wtls6");
	
	//NID_wap_wsg_idm_ecid_wtls7
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls7, "NID_wap_wsg_idm_ecid_wtls7");
	
	//NID_wap_wsg_idm_ecid_wtls8
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls8, "NID_wap_wsg_idm_ecid_wtls8");
	
	//NID_wap_wsg_idm_ecid_wtls9
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls9, "NID_wap_wsg_idm_ecid_wtls9");
	
	//NID_wap_wsg_idm_ecid_wtls10
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls10, "NID_wap_wsg_idm_ecid_wtls10");
	
	//NID_wap_wsg_idm_ecid_wtls11
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls11, "NID_wap_wsg_idm_ecid_wtls11");
	
	//NID_wap_wsg_idm_ecid_wtls12
	test_sign_verify_time(buff, NID_wap_wsg_idm_ecid_wtls12, "NID_wap_wsg_idm_ecid_wtls12");
	
	//NID_ipsec3
	test_sign_verify_time(buff, NID_ipsec3, "NID_ipsec3");
	
	//NID_ipsec4
	test_sign_verify_time(buff, NID_ipsec4, "NID_ipsec4");
	
	//NID_brainpoolP160r1
	test_sign_verify_time(buff, NID_brainpoolP160r1, "NID_brainpoolP160r1");
	
	//NID_brainpoolP160t1
	test_sign_verify_time(buff, NID_brainpoolP160t1, "NID_brainpoolP160t1");
	
	//NID_brainpoolP192r1
	test_sign_verify_time(buff, NID_brainpoolP192r1, "NID_brainpoolP192r1");
	
	//NID_brainpoolP192t1
	test_sign_verify_time(buff, NID_brainpoolP192t1, "NID_brainpoolP192t1");
	
	//NID_brainpoolP224r1
	test_sign_verify_time(buff, NID_brainpoolP224r1, "NID_brainpoolP224r1");
	
	//NID_brainpoolP224t1
	test_sign_verify_time(buff, NID_brainpoolP224t1, "NID_brainpoolP224t1");
	
	//NID_brainpoolP256r1
	test_sign_verify_time(buff, NID_brainpoolP256r1, "NID_brainpoolP256r1");
	
	//NID_brainpoolP256t1
	test_sign_verify_time(buff, NID_brainpoolP256t1, "NID_brainpoolP256t1");
	
	//NID_brainpoolP320r1
	test_sign_verify_time(buff, NID_brainpoolP320r1, "NID_brainpoolP320r1");
	
	//NID_brainpoolP320t1
	test_sign_verify_time(buff, NID_brainpoolP320t1, "NID_brainpoolP320t1");
	
	//NID_brainpoolP384r1
	test_sign_verify_time(buff, NID_brainpoolP384r1, "NID_brainpoolP384r1");
	
	//NID_brainpoolP384t1
	test_sign_verify_time(buff, NID_brainpoolP384t1, "NID_brainpoolP384t1");
	
	//NID_brainpoolP512r1
	test_sign_verify_time(buff, NID_brainpoolP512r1, "NID_brainpoolP512r1");
	
	//NID_brainpoolP512t1
	test_sign_verify_time(buff, NID_brainpoolP512t1, "NID_brainpoolP512t1");
	
	
	return ;
}