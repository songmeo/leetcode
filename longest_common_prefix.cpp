#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;


//horizontal way: time O(n) (sum of all characters in the string), space O(1) (always use the same space)
class Solution1 {
public:
	string commonPrefix(string a, string b) {
		size_t i;
		for(i = 0; i < min(a.length(),b.length()) && a[i] == b[i]; i++);
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

//divide and conquer: time O(n), space O(m.logn) (memory overhead because recursive calls are stored in the execution stack)
class Solution2 {
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

//using binary search
class Solution {
public:
	bool isCommonPrefix(vector<string>& strs, int len) {
		string s1 = strs[0].substr(0,len);
		for(string s : strs) {
			for(size_t i = 0; i < s1.length(); ++i) {
				if(s1[i] != s[i]) 
					return false;
			}
		}
		return true;
	}
	
	string longestCommonPrefix(vector<string>& strs) {
		if(strs.size() == 0) return "";
		if(strs.size() == 1) return strs[0];
		int minLen = INT_MAX;
		for(string s : strs)
			minLen = min(minLen, (int)s.length());
		int low = 1;
		int high = minLen;
		while(low <= high) {
			int mid = (low + high) / 2;
			if(isCommonPrefix(strs, mid))
				low = mid + 1;
			else
				high = mid - 1;
		}
		return strs[0].substr(0, (low + high) / 2);
	}
};

int main() {
	Solution s;
	vector<string> strs = {"flower","flow","flight"};
	cout << s.longestCommonPrefix(strs);
	return 0;
}
