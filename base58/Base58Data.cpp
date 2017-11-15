/******************************************************************************
 *  Copyright(c) 2015-2023 XMCOIN                                      *
 *  All rights reserved.                                                      *
 *                                                                            *
 *  @license                                                                  *
 *                                                                            *
 *****************************************************************************/ 
/**
 *  @file    Base58Data.cpp
 *  @brief
 *
 *  @version   0.85
 *  @author    zwj
 *  @email 
 *  @date      2017-09-22
 *  
 * 
 *  Change History:
 *  @author 
 *  @email 
 *  @date
 *  @brief
 *  
 */

#include "Base58Data.h"

#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <string>
#include <stdio.h>  
#include <stdlib.h>  

#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/static_visitor.hpp>


/** All alphanumeric characters except for "0", "I", "O", and "l" */

static const char* pszBase58 = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

bool DecodeBase58(const char* psz, std::vector<unsigned char>& vch)
{
	// Skip leading spaces.
	while (*psz && isspace(*psz))
		psz++;
	// Skip and count leading '1's.
	int zeroes = 0;
	int length = 0;
	while (*psz == '1') {
		zeroes++;
		psz++;
	}
	// Allocate enough space in big-endian base256 representation.
	int size = strlen(psz) * 733 / 1000 + 1; // log(58) / log(256), rounded up.
	std::vector<unsigned char> b256(size);
	// Process the characters.
	while (*psz && !isspace(*psz)) {
		// Decode base58 character
		const char* ch = strchr(pszBase58, *psz);
		if (ch == NULL)
			return false;
		// Apply "b256 = b256 * 58 + ch".
		int carry = ch - pszBase58;
		int i = 0;
		for (std::vector<unsigned char>::reverse_iterator it = b256.rbegin(); (carry != 0 || i < length) && (it != b256.rend()); ++it, ++i) {
			carry += 58 * (*it);
			*it = carry % 256;
			carry /= 256;
		}
		assert(carry == 0);
		length = i;
		psz++;
	}
	// Skip trailing spaces.
	while (isspace(*psz))
		psz++;
	if (*psz != 0)
		return false;
	// Skip leading zeroes in b256.
	std::vector<unsigned char>::iterator it = b256.begin() + (size - length);
	while (it != b256.end() && *it == 0)
		it++;
	// Copy result into output vector.
	vch.reserve(zeroes + (b256.end() - it));
	vch.assign(zeroes, 0x00);
	while (it != b256.end())
		vch.push_back(*(it++));
	return true;
}

std::string EncodeBase58(const unsigned char* pbegin, const unsigned char* pend)
{
	// Skip & count leading zeroes.
	int zeroes = 0;
	int length = 0;
	while (pbegin != pend && *pbegin == 0) {
		pbegin++;
		zeroes++;
	}
	// Allocate enough space in big-endian base58 representation.
	int size = (pend - pbegin) * 138 / 100 + 1; // log(256) / log(58), rounded up.
	std::vector<unsigned char> b58(size);
	// Process the bytes.
	while (pbegin != pend) {
		int carry = *pbegin;
		int i = 0;
		// Apply "b58 = b58 * 256 + ch".
		for (std::vector<unsigned char>::reverse_iterator it = b58.rbegin(); (carry != 0 || i < length) && (it != b58.rend()); it++, i++) {
			carry += 256 * (*it);
			*it = carry % 58;
			carry /= 58;
		}

		assert(carry == 0);
		length = i;
		pbegin++;
	}
	// Skip leading zeroes in base58 result.
	std::vector<unsigned char>::iterator it = b58.begin() + (size - length);
	while (it != b58.end() && *it == 0)
		it++;
	// Translate the result into a string.
	std::string str;
	str.reserve(zeroes + (b58.end() - it));
	str.assign(zeroes, '1');
	while (it != b58.end())
		str += pszBase58[*(it++)];
	return str;
}

std::string EncodeBase58(const std::vector<unsigned char>& vch)
{
	return EncodeBase58(vch.data(), vch.data() + vch.size());
}

bool DecodeBase58(const std::string& str, std::vector<unsigned char>& vchRet)
{
	return DecodeBase58(str.c_str(), vchRet);
}


Base58Data::Base58Data()
{
	strEncodedata = "";
}


Base58Data::~Base58Data()
{
	vchData.clear();
}

void  Base58Data::hexStringToBytes(const char *hexstring, std::vector<unsigned char>& vch)
{
	unsigned char work[] = { 0x00, 0x00, 0x00 };
	int i;

	// assert lenght %2 == 0  
	for (i = 0; i < (int)strlen(hexstring); i += 2) {
		work[0] = hexstring[i];
		work[1] = hexstring[i + 1];
		vch.push_back((unsigned char)strtoul((char *)work, (char **)NULL, 16));
	}

}

bool Base58Data::Decode(const char * psz, std::string  &strSource)
{
	if(psz == NULL)
	{
		return  false;
	}
	
	vchData.clear();
	bool  bsuc = DecodeBase58(psz, vchData);
	
	if(bsuc)
	{
		strSource = "";
		char c[2];
		for (std::vector<unsigned char>::iterator it = vchData.begin(); it != vchData.end(); ++it)
		{
			sprintf(c, "%02X", (static_cast<short>(*it) & 0xff));
			strSource += c;
		}
	}
	
	return bsuc;
}

bool Base58Data::Decode(const std::string& str, std::string  &strSource)
{
	if(str == "")
	{
		return  false;
	}
	
	vchData.clear();
	bool  bsuc = DecodeBase58(str.c_str(), vchData);
	
	if(bsuc)
	{
		strSource = "";
		char c[2];
		for (std::vector<unsigned char>::iterator it = vchData.begin(); it != vchData.end(); ++it)
		{
			sprintf(c, "%02X", (static_cast<short>(*it) & 0xff));
			strSource += c;
		}
	}
	
	return bsuc;
}

std::string Base58Data::Encode(const char * pdata)
{
	if(pdata == NULL)
	{
		return  "";
	}
	
	strEncodedata = pdata;
	if (strEncodedata.length() % 2) strEncodedata.insert(strEncodedata.begin(), '0');
	
	vchData.clear();
	hexStringToBytes(strEncodedata.c_str(),vchData);
	
	return  EncodeBase58(vchData.data(), vchData.data() + vchData.size());
}

std::string Base58Data::Encode(const std::string  strdata)
{
	if (strdata.empty())
	{
		return  "";
	}
	
	strEncodedata = strdata;
	if (strEncodedata.length() % 2) strEncodedata.insert(strEncodedata.begin(), '0');
	
	vchData.clear();
	hexStringToBytes(strEncodedata.c_str(),vchData);
	
	return  EncodeBase58(vchData.data(), vchData.data() + vchData.size());
}

