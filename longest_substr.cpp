/*
 * Given a string, find the length of the longest substring without repeating characters.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//naive solution O(n^2)
class Solution1 {
public:
	int longestSubstr(string s) {
		int max_len = 0;
		for(auto it1 = s.begin(); it1 != s.end(); it1++) {
			int len = 0;
			unordered_map<char,int> m;
			string::iterator it2;
			for(it2 = it1; it2 != s.end(); it2++) {
				if(m.find(*it2) != m.end()) break;
				len++;
				m[*it2]++;
			}
			if(len > max_len) {
				max_len = len;
			}
		}
		return max_len;
	}
};

class Solution {
public:
	int longestSubstr(string s) {
		unordered_map<char,int> m;
		for(char c: s) {
			m[c]++;
		}
		if(m.size() == 1) return 1;
		int max_len = m.size();
		for(auto it = s.begin(); it != s.end(); it++) {
			int len = 0;
			if(m[*it] > 1) {
				string substr(it + 1, s.end());
				string::iterator next_pos = find(it + 1, s.end(), *it);
				if(next_pos != s.end()) {
					len = next_pos - it;
				}
				if(len < max_len && len != 0) max_len = len;
			}
		}
		return max_len;
	}
};

int main() {
	Solution s;
	cout << s.longestSubstr("abcabcbb") << endl;
	cout << s.longestSubstr("bbbbb") << endl;
	cout << s.longestSubstr("pwwkew") << endl;
	return 0;
}
