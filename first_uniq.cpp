#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public: 
	int firstUniqChar(string s) {
		return unique(s.begin(), s.end()) - s.begin();
	}
};

int main() {
	Solution s;
	string str = "cc";
	cout << s.firstUniqChar(str);
	return 0;
}
