#include <iostream>

#include "RLP.h"

using namespace std;
using namespace dev;

template <class Iterator>
std::string toHex(Iterator _it, Iterator _end, std::string _prefix)
{
	typedef std::iterator_traits<Iterator> traits;
	static_assert(sizeof(typename traits::value_type) == 1, "toHex needs byte-sized element type");

	static char const* hexdigits = "0123456789abcdef";
	size_t off = _prefix.size();
	std::string hex(std::distance(_it, _end)*2 + off, '0');
	hex.replace(0, off, _prefix);
	for (; _it != _end; _it++)
	{
		hex[off++] = hexdigits[(*_it >> 4) & 0x0f];
		hex[off++] = hexdigits[*_it & 0x0f];
	}
	return hex;
}

/// Convert a series of bytes to the corresponding hex string.
/// @example toHex("A\x69") == "4169"
template <class T> std::string toHex(T const& _data)
{
	return toHex(_data.begin(), _data.end(), "");
}

/// Convert a series of bytes to the corresponding hex string with 0x prefix.
/// @example toHexPrefixed("A\x69") == "0x4169"
template <class T> std::string toHexPrefixed(T const& _data)
{
	return toHex(_data.begin(), _data.end(), "0x");
}


int main()
{
	RLPStream rs0;
	int cc = 0xFFFF;
	string arr_str[] = {"aaa","bbbb"};
	RLPStream rs_arr;
	rs_arr<<arr_str[0] << arr_str[1];
	rs0<< cc;
	//rs0<< cc << arr_str[0] << arr_str[1];
	rs0.appendList(rs_arr);
	cout<< toHex(rs0.out()) <<endl;
	
    RLPStream rs;
    int i = 22;
    string s = "abcdef";
    
    rs.appendList(4);
    rs<<i<<s;
	rs.appendRaw(rs0.out());
	//rs.appendList(rs0);
	
	std::vector<std::string> vec_str = {"niubi","niubiplus"};
	rs.append(vec_str);
	
	cout <<"==================================" << endl;
    cout<< toHex(rs.out()) <<endl;
   
    RLP r(bytesConstRef(rs.out().data(),rs.out().size()), RLP::AllowNonCanon|RLP::ThrowOnFail);
    cout << r << endl;
	cout << r[0] << endl;
	cout << r[1].toString() << endl;
	cout << r[2].toInt() << endl;
	cout << r[3] << endl;
	//cout << r[3][0].toString() << endl;
	//cout << r[3][1].toString() << endl;
	
	
	cout <<"==================================" << endl;
	
	RLPStream rs1;
	//rs1.appendList(1);
	char *str = "AAAaaa";
	rs1<<str;
	cout<< toHex(rs1.out()) <<endl;
	//RLP r1(bytesConstRef(rs1.out().data(),rs1.out().size()), RLP::AllowNonCanon|RLP::ThrowOnFail);
	bytesConstRef bs(rs1.out().data(),rs1.out().size());
	std::uint8_t *buff = new std::uint8_t[bs.size()];
	memcpy(buff, bs.data(), bs.size());
	cout << "-------------------------------->>>" << endl;
	cout << std::hex;
	for(int c=0; c<bs.size(); c++)
	{
		cout << buff[c];
	}
	cout << std::dec << endl;
	cout << "--------------------------------<<<" << endl;
	//cout << r1.toString() << endl;
	//cout << r1[0].toString() << endl;
    //cout << "--------------------------------" << endl;
	RLP r2(bytesConstRef(buff, bs.size()),RLP::AllowNonCanon|RLP::ThrowOnFail);
	cout << r2 << endl;
	cout << r2.toString() << endl;
	
    //output(cout, rs)
	//RLPStreamer::Prefs prefs;
    //RLPStreamer s(cout, prefs);
    //s.output(rs);
    //cout << endl;

    return 0;
}
