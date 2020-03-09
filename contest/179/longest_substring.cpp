#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
class Solution {
public:
	bool evenVowels(string s) {
		unordered_map<char,int> m;
        m['a'] = 0;
        m['e'] = 0;
        m['i'] = 0;
        m['o'] = 0;
        m['u'] = 0;
		for(char c : s) {
			if(m.find(c) != m.end()) m[c]++;
		}
		for(auto i : m) {
			if(i.second % 2 != 0) return false;
		}
		return true;
	}
	
	int findTheLongestSubstring(string s) {
		int min = 0;
		int max = s.length() - 1;
		while(min < max && !evenVowels(s.substr(min,max))) {
			max--;
		}
		int r1 = max - min;
		max = s.length() - 1;
		while(min < max && !evenVowels(s.substr(min,max))) {
			min++;class Solution {
public:
	int findTheLongestSubstring(string s) {
		unordered_map<int,int> m{{0,-1}};
		int res = 0, n = s.length(), cur = 0;
		for(int i = 0; i < n; i++) {
			cur ^= 1 << (string("aeiou").find(s[i]) + 1) >> 1;
			if(!m.count(cur)) m[cur] = i;
			res = max(res, i - m[cur]);
		}
		for(auto p : m) {
			cout << p.first << " " << p.second << endl;
		}
		return res;
	}
};

		}
		int r2 = max - min;
		return (r1 > r2)?r1:r2;
    }
};


class Solution {
public:
	int findTheLongestSubstring(string s) {
		unordered_map<int, int> m {{
	}
}
*/

/*
class Solution {
public:
	int findTheLongestSubstring(string s) {
		unordered_map<int,int> m{{0,-1}};
		int res = 0, n = s.length(), cur = 0;
		for(int i = 0; i < n; i++) {
			cur ^= 1 << (string("aeiou").find(s[i]) + 1) >> 1;
			//cout << cur << endl;
			if(!m.count(cur)) m[cur] = i;
			res = max(res, i - m[cur]);
		}
		for(auto p : m) {
			cout << p.first << " " << p.second << endl;
		}
		return res;
	}
};
*/

class Solution {
public:
	int findTheLongestSubstring(string str) {
		unordered_map<int, int> m {{0,-1}};
		int cur = 0, res = 0;
		
		for(int i = 0; i < (int) str.length(); ++i) {
			cur ^= 1 << (string("aeiou").find(i) + 1) >> 1;
			if(!m.count(cur)) m[cur] = i;
			res = max(res, i - m[cur]);
		}
		return res;
	}
};

int main() {
	Solution s;
	string str = "eleetminicoworoep";
	cout << s.findTheLongestSubstring(str);
	return 0;
}
