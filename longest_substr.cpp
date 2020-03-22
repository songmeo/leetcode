/*
 * Given a string, find the length of the longest substring without repeating characters.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	string longestSubstr(string s) {
		unordered_map<char,int> m;
		string result;
		int max_len = 0;
		for(auto it1 = s.begin(); it1 != s.end(); it1++) {
			int len = 0;
			string::iterator it2;
			for(it2 = it1; it2 != s.end(); it2++) {
				if(m.find(*it2) != m.end()) break;
				len++;
				m[*it2]++;
			}
			if(len > max_len) {
				max_len = len;
				result = string(it1,it2);
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.longestSubstr("abcabcbb") << endl;
	cout << s.longestSubstr("bbbbb") << endl;
	cout << s.longestSubstr("pwwkew") << endl;
	return 0;
}
