#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ext/hash_map>
#include "string.h"
using namespace std;
//class Solution {
//	public:
		string fractionToDecimal(int numerator, int denominator) {
			if(numerator == 0) return 0;
			hash_map<int,string> result;
			hash_map<int,string>::iterator it;
			ostringstream buffer;
			buffer << numerator/denominator;
			int remainder = numerator % denominator;	
			if( remainder == 0 )
				return buffer.str();
			else
				buffer << ".";
			while(true) {
				if(remainder == 0)
					break;
				remainder *= 10;	
				ostringstream temp;
				while( remainder < denominator )
				{
					remainder *= 10;
					temp << 0;	
				}
				int quotient = remainder / denominator;
				temp << quotient;	
				it = result.find(remainder);
				if(it == result.end())
				{
					cout << "remainder:" << remainder << "; quotient:" << temp.str()  << endl;
					string _temp_str = temp.str();
					result.insert(make_pair<int, string>(remainder, _temp_str));
				}
				else
				{
					break;
				}
				remainder = remainder % denominator;
			}
			//map to buffer
			for(map<int,string>::iterator _it = result.begin(); _it != result.end(); _it++)	
			{
				if(it == _it)
					buffer << "(";
				cout << "_it:" << _it->first << " " << _it->second << endl;
				buffer << _it->second;
			}
			if(it != result.end())
				buffer << ")";
			return buffer.str();
		}
//};
int main()
{
	//Solution fi;
	//cout <<fi.fractionToDecimal(1, 3) << endl;
	//cout <<fi.fractionToDecimal(1, 6) << endl;
	//cout <<fi.fractionToDecimal(1, 17) << endl;
	//cout <<fi.fractionToDecimal(1, 19) << endl;
	//cout <<fi.fractionToDecimal(1, 99) << endl;
	//cout <<fi.fractionToDecimal(2, 5) << endl;
	cout << fractionToDecimal(1, 17) << endl;
	cout << setprecision(16) << (long double)1/17 << endl;
	//cout <<fi.fractionToDecimal(1, 19) << endl;
	//cout << setprecision(16) << (long double)1/19 << endl;
	return 0;
}
