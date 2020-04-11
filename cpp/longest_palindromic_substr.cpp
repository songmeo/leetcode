#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
			if(s[i] != s[j])
				return false;
		}
		return true;
	}
	
	string longestPalindrome(string str) {
		string result;
		for(string::iterator it = str.begin(); it != str.end(); it++) {
			auto next = find_end(it + 1, str.end(), it, it);
			string tmp;
			if(next != it) {
				tmp = string(it, next + 1);
			}
			else {
				tmp = *it;
			}
			if(validPalindrome(tmp) && tmp.length() > result.length()) result = tmp;
		}
		return result;
	}
};

int main() {
	string str = "babad"; //bab
	Solution s;
	cout << s.longestPalindrome("babad") << endl;
	cout << s.longestPalindrome("abc") << endl;
	cout << s.longestPalindrome("") << endl;
	cout << s.longestPalindrome("ccc") << endl;
	return 0;
}
