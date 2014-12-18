#include <iostream>
#include <vector>
#include "string.h"
using namespace std;

void split(string origin,string sp,vector<string>& temp)
{
	size_t last = 0;  
    size_t index = origin.find_first_of(sp, last);  
    while (index != string::npos)  
    {  
        temp.push_back(origin.substr(last, index-last));  
        last = index + 1;  
        index = origin.find_first_of(sp, last);  
    }  
    if (index-last > 0) //最后一段就是将剩余的字符串全部写入vector，如果有剩余 
    {  
        temp.push_back(origin.substr(last, index-last));  //substr的第二个参数为负时就是到结尾
    }  
}
int main()
{
	vector<string> temp;
	string a = "i am here";
	split(a," ",temp);
	cout << endl;
	return 0;
}
