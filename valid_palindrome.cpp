#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		for(auto it = s.begin(); it != s.end();) {
			*it = tolower(*it);
			if(!isalnum(*it)) it = s.erase(it);
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
	string s1 = "race a car";
	cout << s.isPalindrome(s1);
	return 0;
}
