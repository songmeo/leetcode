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
		string result = "";
		for(auto it = s.begin(); it != s.end(); it++) {
			if(m.find(*it) != m.end()) return result;
			result += *it;
			m[*it]++;
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.longestSubstr("abcabcbb");
	return 0;
}
