#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * using hashmap
 * putting characters to hashmap costs O(n)
 * iterating through the string again also cost O(n)
 */
class Solution {
public: 
	int firstUniqChar(string s) {
		unordered_map<char,int> um;
		for(char i : s) {
			um[i]++;
		}
		for(int i = 0; i < s.length(); ++i) {
			if(um[s[i]] == 1) return i;
		}
		return -1;
	}
};

int main() {
	Solution s;
	string str = "cc";
	cout << s.firstUniqChar(str);
	return 0;
}
