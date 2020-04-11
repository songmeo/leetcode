/*
 * Given a string, find the length of the longest substring without repeating characters.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

//using hashSet as sliding window 
//time complexity: O(n) space complexity: O(k) k is size of the set
class Solution2{
public:
	int longestSubstr(string str) {
		unordered_set<char> s;
		int start = 0, end = 0, len = 0;
		while(start < (int) str.length() && end < (int) str.length()) {
			if(s.find(str[end]) == s.end()) {
				s.insert(str[end++]);
				len = max(len, end - start);
			}
			else {
				s.erase(str[start++]);
			}
		}
		return len;
	}
};

class Solution {
public:
	int longestSubstr(string str) {
		unordered_map<char, int> m;
		int start = 0, end = 0, len = 0;
		while(end < str.length()) {
			if(m.find(str[end]) != m.end()) {

			}
			m[str[end]] = end;
			len = max(len, end - start);
			start = end + 1;
			end++;
			
		}
		return len;
	}
};

int main() {
	Solution s;
	cout << s.longestSubstr("abcabcbb") << endl;
	cout << s.longestSubstr("bbbbb") << endl;
	cout << s.longestSubstr("pwwkew") << endl;
	cout << s.longestSubstr("abbacd") << endl;
	return 0;
}
