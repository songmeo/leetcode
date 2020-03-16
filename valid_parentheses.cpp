#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

/*
 * time complexity: O(n)
 * space complexity: O(n) the worst case is pushing the whole string to the stack
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
			if(m.find(*it1) != m.end()) { //O(n)
				st.push(*it1); //O(1)
			}
			else if(!st.empty() && (*it1) == m[st.top()]) { //O(1)
				st.pop(); //O(1)
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

