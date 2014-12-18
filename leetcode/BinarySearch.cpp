#include <iostream>
#include <algorithm>
#include <vector>
#include "string.h"
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0,right = n,t;
        while(left <= right)
        {	
			t = (left + right)/2;
			if(A[t] == target)
				return t;
			else {
           		if(A[t] < target){
           		    left = t + 1;
           		}
           		else{
           		    right = t - 1;
           		}
			}
	    }
		return -1;
    }
};
int main()
{
	Solution temp;
	int A[] = {1,3};
	cout<<temp.search(A,sizeof(A)/4 - 1,3);
	return 0;
}
