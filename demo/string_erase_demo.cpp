#include <iostream>
#include <algorithm>
#include <vector>
#include "string.h"
using namespace std;


int main()
{
	//vector<vector<int> > temp;

    //vector<int> last.push_back(1);

    //temp.push_back(last);
	string s = "..//.......12a....";	

	int i = 0;
	for(string::iterator it = s.begin(); it < s.end() ; it++) {
		if(!isalpha(*it) && !isdigit(*it)){
			s.erase(it--);
		}
	}
	cout << s << endl;

	return 0;
}
