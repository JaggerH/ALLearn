class Solution {

	public:

		bool isPalindrome(string s) {

			// Start typing your C/C++ solution below  

			// DO NOT write int main() function  

			if (s == "") {  

				return true;  

			}  

			transform(s.begin(), s.end(), s.begin(), ::tolower);

			for (string::iterator it = s.begin(); it < s.end(); it++) {  

				if (!isalpha((*it)) && !isdigit((*it))) {  

					s.erase(it--);     

				}

			}  

			for (int i = 0; i < s.length() / 2; i++) {  

				if (s[i] != s[s.length() - i - 1]) {  

					return false;  

				}  

			}  

			return true;

		}

};
