#include <iostream>
#include <vector>
#include <string>

using namespace std;
//naive way
class Solution {
public:
	string commonPrefix(string a, string b) {
		int i;
		for(i = 0; i < a.length() && a[i] == b[i]; i++);
		return a.substr(0,i);
	}
	
	string longestCommonPrefix(vector<string>& strs) {
		string cp = commonPrefix(strs[0],strs[1]);
		for(int i = 2; i < strs.size(); i++) {
			cp = commonPrefix(cp, strs[i]);
			cout << cp;
		}
		return cp;
	}
};

int main() {
	Solution s;
	vector<string> strs = {"flower","flow","flight"};
	cout << s.longestCommonPrefix(strs);
	return 0;
}
