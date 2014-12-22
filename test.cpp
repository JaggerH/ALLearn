#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>
#include "string.h"
using namespace std;
class Solution {
public:
	vector<int>::iterator find(vector<int> source, int destination) {
		vector<int>::iterator it;
		for(it = source.begin(); it != source.end(); it++)
		{
			if(*it == destination)
				return it;
		}
		return source.end();
	}
	string fractionToDecimal(int numerator, int denominator) {
		int pre = numerator/denominator;
		ostringstream buffer;
		buffer << pre;
		int next = numerator%denominator;
		if(next == 0)
			return buffer.str();
		else
		{
			vector<int> result;
			vector<int> yushu;
			vector<int>::iterator repeate;
			int yu = numerator % denominator;	
			bool limited = false;
			buffer << ".";	
			while(true)
			{
				if(yu == 0)
				{
					limited = true;	
					break;	
				}
				yu *= 10;	
				while(yu < denominator)
				{
					result.push_back(0);	
					yu *= 10;	
				}
				int value = yu/denominator;
				cout << "当前结果:" << value << endl;
				repeate = find(yushu, yu);
				if(repeate == yushu.end())
				{
					cout << "没找到" << endl;
					yushu.push_back(yu);
					result.push_back(value);
				}
				else
				{
					cout << "找到了" << endl;
					break;
				}
				yu  = yu%denominator;
			}
			vector<int>::iterator it;
			if(limited)
			{
				for(it = result.begin(); it != result.end(); it++)
					buffer << *it;	
			}	
			else
			{
				cout << *repeate << endl;
				for(it = result.begin(); it != result.end(); it++)
				{
					if(it == repeate)
						buffer << "(";	
					buffer << *it;
				}	
					buffer << ")";
			}
		}	
		return buffer.str();
    }
};
int main()
{
	Solution fi;
	cout <<fi.fractionToDecimal(1, 3) << endl;
	//cout <<fractionToDecimal(1, 6) << endl;
	//cout <<fractionToDecimal(1, 17) << endl;
	//cout <<fractionToDecimal(1, 19) << endl;
	//cout <<fractionToDecimal(1, 99) << endl;
	//cout <<fractionToDecimal(2, 5) << endl;
	return 0;
}
