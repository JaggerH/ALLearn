#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
inline void NEXT(const string &T,vector<int >&next)
{
	//按模式串生成vector,next(T.size())
	next[0] = -1;
	for(int i = 1;i<T.size();i++){
		int j = next[i-1];
		while(T[i] != T[j+1] && j >= 0)
			j = next[j];//递推计算
		if(T[i] == T[j+1]) next[i] = j+1;
		else next[i] = 0;//
	}
}

inline string::size_type COUNT_KMP(const string &S,	const string &T)
{
	//利用模式串T的next函数求T在主串S中的个数count的KMP算法
	//count是最终的个数,index是原串的指针（可以回溯的位置），pos是匹配串的指针（每次在匹配串中的位置），iter是index的分身 
	vector<int> next(T.size());
	NEXT(T,next);
	string::size_type index,count = 0;
	for(index = 0; index < S.size(); index++){
		int pos = 0;
		string::size_type iter = index;
		while(pos < T.size() && iter < S.size()){
			if(S[iter] == T[pos]){
				++iter;++pos;
			}
			else {
				if(pos == 0)++iter;
				else pos = next[pos-1]+1;
			}
		}//whileend
		if(pos == T.size()&&(iter-index) == T.size()) ++count;
	}//forend
	return count;
}

int main(int argc,char*argv[])
{
	int n = 0;
	cin >> n;
	while(n--)
	{
		string T,S;
		cin >> T >> S; 
		string::size_type count = COUNT_KMP(S,T);
		cout << count << endl;
	}
	return 0;
}
