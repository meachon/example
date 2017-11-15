/******************************************************************************
 *  Copyright(c) 2015-2023 XMCOIN                                      *
 *  All rights reserved.                                                      *
 *                                                                            *
 *  @license                                                                  *
 *                                                                            *
 *****************************************************************************/ 
/**
 *  @file    Base58Data.h
 *  @brief   base58编解码
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


#ifndef XMCOIN_BASE58DATA_H
#define XMCOIN_BASE58DATA_H

#include <vector>
#include <string>

/**
 *  @brief   输入字符串序列，输出string类型的base58编码字符串
 *
 *
 *  @param[in]  unsigned char* pbegin   字符串序列起始指针，不能为空
 *  @param[in]  unsigned char* pend     字符串序列尾指针，不能为空
 *  @exception
 *  @return   std::string   base58编码字符串
 *
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
std::string EncodeBase58(const unsigned char* pbegin, const unsigned char* pend);


/**
 *  @brief   输入vector字符数组，输出string类型的base58编码字符串
 *
 *
 *  @param[in]  std::vector<unsigned char>& vch   vector字符数组 ，不能为空
 *  @exception
 *  @return   std::string   base58编码字符串
 *
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
std::string EncodeBase58(const std::vector<unsigned char>& vch);


/**
 *  @brief  把char类型base58编码字符串解码为源字符串
 *
 *
 *  @param[in]  std::string& str   base58编码字符串
 *  @param[out] vector<unsigned char>& vchRet   源字符串
 *  @exception
 *  @return   bool   true  表示解码成功   false  表示解码失败
 *
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
bool DecodeBase58(const char* psz, std::vector<unsigned char>& vchRet);


/**
 *  @brief  把string类型base58编码字符串解码为源字符串
 *
 *
 *  @param[in]  std::string& str   base58编码字符串
 *  @param[out] vector<unsigned char>& vchRet   源字符串
 *  @exception
 *  @return   bool   true  表示解码成功   false  表示解码失败
 *
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
bool DecodeBase58(const std::string& str, std::vector<unsigned char>& vchRet);


/**
 *  @class   Base58Data
 *  @brief   base58编解码
 *  @author  zwj
 *  @note
 *
 *
 */
class Base58Data
{
public:
	Base58Data();
	~Base58Data();

public:

/**
 *  @brief  把输入的base58编码字符串解码为源字符串
 *
 *
 *  @param[in]  char* psz   base58编码字符串
 *  @param[out] std::string  &strSource   源字符串
 *  @exception
 *  @return   bool   true  表示解码成功   false  表示解码失败
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
	bool Decode(const char* psz, std::string  &strSource);

/**
 *  @brief  把string类型base58编码字符串解码为源字符串
 *
 *
 *  @param[in]  std::string& str   base58编码字符串
 *  @param[out] std::string  &strSource   源字符串
 *  @exception
 *  @return   bool   true  表示解码成功   false  表示解码失败
 *
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
bool Decode(const std::string& str, std::string  &strSource);


/**
 *  @brief   把输入的字符串编码为base58的string字符串
 *
 *
 *  @param[in]  char* pdata   输入字符串
 *  @exception
 *  @return   string     base58字符串
 *
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
	std::string Encode(const char* pdata);

	/**
 *  @brief   把输入的字符串编码为base58的string字符串
 *
 *
 *  @param[in]  const std::string  strdata   输入string字符串
 *  @exception
 *  @return   string     base58字符串
 *
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
	std::string Encode(const std::string  strdata);

protected:

    /**
 *  @brief   把输入的字符串转换为int256的vector数组
 *
 *
 *  @param[in]  const std::string  strdata   输入string字符串
 *  @param[out] std::vector<unsigned char>& vch   输出的int256的vector数组
 *  @exception
 *  @return   NULL
 *
 *  @note 
 *  @par
 *  @code:
 *
 *  @endcode
 *  @see
 *  @deprecated 
 *  @remarks
 */
	 void  hexStringToBytes(const char *hexstring, std::vector<unsigned char>& vch);
	
private:

    std::string                  strEncodedata;
    std::vector<unsigned char>   vchData;   //将字符串指针临时存储到vector的字符数组中
};

#endif  //XMCOIN_BASE58DATA_H
