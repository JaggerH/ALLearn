#include <iostream>
#include <algorithm>
#include <vector>
#include "string.h"
using namespace std;
class Solution {
	public:
		int findMin(vector<int> &num) {
			if(num.size() == 1)
				return num[0];
			if(num.size() == 2)
				if(num[0] < num[1])
					return num[0];
				else 
					return num[1];
			int left=0, right = num.size() - 1, middle = 0;
			while(left <= right)
			{
				middle = (left + right)/2;
				if( right - left == 1 && num[right] < num[left])
					return num[right];
				if(num[left] < num[middle])
					if(num[middle] < num[right])
						return num[left];
					else
						left = middle;
				else
					right = middle;
			}
		}   
};

int main()
{
	int b[7] = { 3, 4, 5, 6, 0, 1, 2};
	vector<int> a(b,b+7);	
	Solution fi;
	cout <<fi.findMin(a) << endl;
	return 0;
}
