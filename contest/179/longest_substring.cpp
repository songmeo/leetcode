#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

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
		return max - min;
    }
};

int main() {
	Solution s;
	string str = "eleetminicoworoep";
	cout << s.findTheLongestSubstring(str);
	return 0;
}
