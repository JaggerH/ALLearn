#include <iostream>
#include <algorithm>
#include <vector>
#include "string.h"
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > temp;
        if(numRows==0)
            return temp;
        vector<int> last;
        last.push_back(1);
        temp.push_back(last);
        for(int i = 1; i < numRows; i++) {
            vector<int> newtemp;
            newtemp.push_back(1);
            if(last.size() > 1) {
                for(int j = 1; j < last.size(); j++){
                    int result = last[j] + last[j-1];
                    newtemp.push_back(result);
                }
            }
            newtemp.push_back(1);
            last = newtemp;
            temp.push_back(newtemp);
        }
        return temp;
    }
};
int main()
{
	vector<vector<int> > result = generate(3);
	cout << endl;
	return 0;
}
