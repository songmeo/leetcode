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
	bool isCommon(vector<string>& strs, int len) {
		string s1 = strs[0].substr(0,len);
		for(string s : strs) {
			for(int i = 0; i < len; ++i) {
				if(s[i] != s1[i])
					return false;
			}
		}
		return true;
	}
	
	string longestCommonPrefix(vector<string>& strs) {
		int minLen = INT_MAX;
		for(string s : strs)
			minLen = min((int)s.length(), minLen);
		int min = 0;
		int max = minLen;
		int mid = 0;
		while(min <= max) {
			mid = (min + max)/2;
			if(isCommon(strs,mid))
				min = mid + 1;
			else
				max = mid - 1;
		}
		return strs[0].substr(0,mid);
	}
};

int main() {
	Solution s;
	vector<string> strs = {"flower","flow","flight"};
	cout << s.longestCommonPrefix(strs);
	return 0;
}
