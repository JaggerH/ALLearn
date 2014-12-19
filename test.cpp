#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include "string.h"
using namespace std;
class Solution {
public:
	string findrepeate(string source) {
		int left = 0,right = 1;
		while( left != source.length() - 1 ) 
		{
			while(source.substr(left, right - left) != source.substr(right, right))
			{
				cout << source.substr(left, right - left) << " " << source.substr(right + 1, right -left - 1) << endl;
				if( right == source.length() - 1)
					break;
				right++;	 	
			}
			left++;
			if(source.substr(left, right - left) == source.substr(right + 1, right - 1))
				return source.substr(0, left) + "("  + source.substr(left, right - left - 1) + ")";
		}
		return source;
	}	
	string fractionToDecimal(int numerator, int denominator) {
		double a = (double)numerator/denominator;
		ostringstream buffer;
		buffer << setprecision(16) << a;
		string str = buffer.str();
		int splitpos = str.find_first_of(".", 0);
		if(splitpos != string::npos)
		{
			string pre = str.substr(0, splitpos);
			string next = str.substr(splitpos + 1, str.length() - splitpos - 2);
			if( pre.length() + next.length() == 16)
			{
				return pre + "." + findrepeate(next);
			}
			else
				return pre+"."+next;
		}
		else
			return str;

    }
};

int main()
{
	Solution fi;
	cout <<fi.fractionToDecimal(1, 3) << endl;
	return 0;
}
