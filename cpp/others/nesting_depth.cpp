#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	string nestingDepth(string s) {
		stringstream ans;
		for(auto it = s.begin(); it != s.end(); it++) {
		}
		return ans.str();
	}
};

int main() {
	Solution s;
	string ss[] = {"221", "0000", "101", "111000", "1"};
	for(string str : ss) {
		cout << s.nestingDepth(str) << " ";
	}
	return 0;
}

