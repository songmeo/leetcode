#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	unordered_map<char, int> m{ //MCMXCIV
		{'I', 1}, //V X
		{'V', 5},
		{'X', 10}, //L C
		{'L', 50},
		{'C', 100}, //D M
		{'D', 500},
		{'M', 1000},
	};
	int romanToInt(string s) {
		int result = 0;
		string::reverse_iterator it;
		for(it = s.rbegin(); it != s.rend() - 1; it++) {
			if(m[*it] > m[*(it + 1)]) {
				result += m[*it] - m[*(it + 1)];
			}
		}
		if(s.length() % 2 != 0) result += m[s[0]]; 
		return result;
	}
};
int main() {
	Solution s;
	cout << s.romanToInt("XXVII") << endl;
	cout << s.romanToInt("IX") << endl;
	cout << s.romanToInt("MCMXCIV") << endl; //1994        1000 100 1000 10 100 1 5
	return 0;
}
