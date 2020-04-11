#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Time complexity: O(n)
 * Space: O(1)
 */
 
class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> re;
		for(int i = 1; i <= n; ++i) {
			string s;
			if(i % 3 == 0) {
				s += "Fizz";
			}
			if(i % 5 == 0) {
				s += "Buzz";
			}
			if(s.empty()) {
				s += to_string(i);
			}
			re.push_back(s);
		}
		return re;
	}
};

int main() {
	Solution s;
	for(auto i : s.fizzBuzz(15)) {
		cout << i;
	}
	return 0;
}
