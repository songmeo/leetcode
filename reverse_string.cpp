#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
		if(!s.empty()) {
			for(auto it1 = s.begin(), it2 = s.end() - 1; it1 != s.begin() + s.size()/2 && s.size() > 0; ++it1, --it2) {
				int tmp = move(*it1);
				*it1 = move(*it2);
				*it2 = move(tmp);
			}
		}
    }
};

int main() {
	Solution s;
	vector<char> str{'h','e','l','l','o'};
	vector<char> s1;
	s.reverseString(s1);
	for(char i : s1) cout << i;
	return 0;
}
