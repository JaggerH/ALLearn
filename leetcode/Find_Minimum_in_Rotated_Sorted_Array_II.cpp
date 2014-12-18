#include <iostream>
#include <algorithm>
#include <vector>
#include "string.h"
using namespace std;
class Solution {
	public:
		int findMin(vector<int> &num) {
			vector<int> temp;
			for(vector<int>::iterator it = num.begin(); it != num.end(); it++)
			{
				if(temp.size() == 0)
					temp.push_back(*it);
				else
					if(temp[temp.size() - 1] != *it)
						temp.push_back(*it);
			}
			if(temp.size() == 1)
				return temp[0];
			if(temp.size() == 2)
				if(temp[0] < temp[1])
					return temp[0];
				else 
					return temp[1];
			int left=0, right = temp.size() - 1, middle = 0;
			while(left <= right)
			{
				middle = (left + right)/2;
				if( right - left == 1 && temp[right] < temp[left])
					return temp[right];
				if(temp[left] < temp[middle])
					if(temp[middle] < temp[right])
						return temp[left];
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
