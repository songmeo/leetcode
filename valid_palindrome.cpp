#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		for(auto it = s.begin(); it != s.end(); ++it) {
			*it = tolower(*it);
			if(*it < 97 || *it > 122) s.erase(it);
		}
		cout << s << endl;
		return 0;
	}
};

int main() {
	Solution s;
	string str = "A man, a plan, a canal: Panama";
	cout << s.isPalindrome(str);
	return 0;
}
