#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	string sortString(string s) {
		string result;
		map<char,int> m;
		for(char c : s) {
			m[c]++;
		}
		while(result.length() < s.length()) {
			for(auto it = m.begin(); it != m.end() && it->second > 0; ++it) {
				result += it->first;
				(it->second)--;
			}
			for(auto it = m.rbegin(); it != m.rend() && it->second > 0; --it) {
				result += it->first;
				(it->second)--;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	string str = "spo";
	cout << s.sortString(str);
	return 0;
}
