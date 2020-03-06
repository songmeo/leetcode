#include <iostream>
#include <vector>
#include <string>
using namespace std;

//naive way
class Solution1 {
public:
	string commonPrefix(string a, string b) {
		size_t i;
		for(i = 0; i < a.length() && a[i] == b[i]; i++);
		return a.substr(0,i);
	}
	
	string longestCommonPrefix(vector<string>& strs) {
		if(strs.empty()) return "";
		if(strs.size() == 1) return strs[0]; 
		for(string s : strs) {
			if(s.empty()) return "";
		}
		string cp = commonPrefix(strs[0],strs[1]);
		for(size_t i = 2; i < strs.size(); i++) {
			cp = commonPrefix(cp, strs[i]);
			cout << cp;
		}
		return cp;
	}
};

//divide and conquer
class Solution {
public:
	string commonPrefix(string a, string b) {
		size_t i;
		for(i = 0; i < min(a.length(),b.length()) && a[i] == b[i]; i++);
		return a.substr(0,i);
	}
	string longestCommonPrefix(vector<string>& strs) {
		if(strs.size() == 0) return "";
		if(strs.size() == 1) return strs[0];
		int mid = strs.size()/2;
		vector<string> left(strs.begin(), strs.begin() + mid);
		vector<string> right(strs.begin() + mid + 1, strs.end());
		string lcpleft = longestCommonPrefix(left);
		string lcpright = longestCommonPrefix(right);
		return commonPrefix(lcpleft, lcpright);
	}
};

int main() {
	Solution s;
	vector<string> strs = {"flower","flow","flight"};
	cout << s.longestCommonPrefix(strs);
	return 0;
}
