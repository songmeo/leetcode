#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> s, t;
        for(char c: S) {
            if(c == '#') {
				if(!s.empty())
					s.pop_back();
			}
            else s.push_back(c);
        }
        for(char c: T) {
            if(c == '#') {
				if(!t.empty())
					t.pop_back();
			}
            else t.push_back(c);
        }
        for(char c : s) cout << c << " ";
        cout << endl;
        for(char c : t) cout << c << " ";
        return s == t;
    }
};

int main() {
	Solution s;
	cout <<s.backspaceCompare("y#fo##f","y#f#o##f");
	return 0;
}
