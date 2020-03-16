#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
			if(!s.empty()) {
				re.push_back(s);
			}
			else {
				re.push_back(to_string(i));
			}
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
