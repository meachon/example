#include <iostream>
#include "Base58Data.h"

int main()
{
	Base58Data  b58;
	std::string hexstring = "00010966776006953d5567439e5e39f86a0d273beed61967f6";
	std::string hexstring1 = "000A08201462985DF5255E4A6C9D493C932FAC98EF791E2F22";
	std::string hexstring2 = "00066C0B8995C7464E89F6760900EA6978DF18157388421561";
	std::string hexstring3 = "000003A";
	
	std::cout << "test1  start" << std::endl;
	std::cout <<  "soure :"  <<  hexstring << std::endl;

	std::string  b58Encode = b58.Encode(hexstring.c_str());
	std::cout <<  "Encode :" << b58Encode << std::endl;

	std::string  strDecode = "";
	b58.Decode(b58Encode, strDecode);
	std::cout <<  "Decode :"  <<  strDecode << std::endl;
	
	std::cout << "test1  end" << std::endl;
	
	std::cout << "test2  start" << std::endl;
	std::cout <<  "soure :"  <<  hexstring1 << std::endl;
	b58Encode = b58.Encode(hexstring1.c_str());
	std::cout <<  "Encode :" << b58Encode << std::endl;

	b58.Decode(b58Encode, strDecode);
	std::cout <<  "Decode :"  <<  strDecode << std::endl;
	
	std::cout << "test2  end" << std::endl;
	
	
	std::cout << "test3  start" << std::endl;
	std::cout <<  "soure :"  <<  hexstring2 << std::endl;
	b58Encode = b58.Encode(hexstring2.c_str());
	std::cout <<  "Encode :" << b58Encode << std::endl;

	b58.Decode(b58Encode, strDecode);
	std::cout <<  "Decode :"  <<  strDecode << std::endl;
	
	std::cout << "test3  end" << std::endl;
	
	
	
	std::cout << "test4  start" << std::endl;
	std::cout <<  "soure :"  <<  hexstring3 << std::endl;
	b58Encode = b58.Encode(hexstring3.c_str());
	std::cout <<  "Encode :" << b58Encode << std::endl;

	b58.Decode(b58Encode, strDecode);
	std::cout <<  "Decode :"  <<  strDecode << std::endl;
	
	std::cout << "test4  end" << std::endl;

    return 0;
}