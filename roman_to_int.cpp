#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<char, int> m{
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
	};
	int romanToInt(string s) {
		int result = 0;
		for(char i : s) {
			result += m[i];
		}
		return result;
	}
};
int main() {
	Solution s;
	cout << s.romanToInt("XXVII");
	return 0;
}
