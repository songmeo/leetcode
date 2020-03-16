#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

/*
 * time complexity: 
*/
class Solution {
public:
	bool isValid(string str) {
		unordered_map<char,char> m {
			{'{','}'},
			{'[',']'},
			{'(',')'},
		};
		stack<char> st;
		for(auto it1 = str.begin(); it1 != str.end(); ++it1) {
			if(m.find(*it1) != m.end()) {
				st.push(*it1);
			}
			else if(!st.empty() && (*it1) == m[st.top()]) {
				st.pop();
			}
			else {
				return false;
			}
		}
		return st.empty();
	}
};

int main() {
	string str = "]";
	Solution s;
	cout << s.isValid(str);
	return 0;
}

