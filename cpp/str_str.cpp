#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		size_t p = haystack.find(needle);
		if(p != string::npos) //npos is the greatest possible value for an element of type size_t
			return p;
		else
			return -1;
	}
};

int main() {
	Solution s;
	cout << s.strStr("hello", "0");
	return 0;
}
