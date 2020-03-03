#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		for(auto it = s.begin(); it != s.end();) {
			*it = tolower(*it);
			if(!isalpha(*it)) it = s.erase(it);
			else ++it;
		}
		string tmp = s;
		reverse(s.begin(),s.end());
		return s == tmp;
	}
};

int main() {
	Solution s;
	string str = "A man, a plan, a canal: Panama";
	cout << s.isPalindrome(str);
	return 0;
}
