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
		for(auto it = s.begin(); it != s.end(); it++) {
			
		}
		return result;
	}
};
int main() {
	Solution s;
	cout << s.romanToInt("XXVII") << endl;
	cout << s.romanToInt("IX") << endl;
	cout << s.romanToInt("MCMXCIV") << endl; //1994   1000 100 1000 10 100 1 5
	return 0;
}
