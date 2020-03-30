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
		int result = m[s[0]];
		for(auto it = s.begin() + 1; it != s.end(); it++) {
			if(m[*it] <= m[*(it - 1)]) {
				result += m[*it];
			}
			else {
				result = m[*it] - result;
			}
		}
		return result;
	}
};
int main() {
	Solution s;
	cout << s.romanToInt("XXVII") << endl;
	cout << s.romanToInt("IX") << endl;
	return 0;
}
