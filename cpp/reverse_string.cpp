#include <iostream>
#include <vector>
using namespace std;

/*
 * Time: O(n)
 * Space: O(1)
*/
class Solution1 {
public:
    void reverseString(vector<char>& s) {
		if(!s.empty()) {
			for(auto it1 = s.begin(), it2 = s.end() - 1; it2 > it1; ++it1, --it2) {
				char tmp = move(*it1);
				*it1 = move(*it2);
				*it2 = move(tmp);
			}
		}
    }
};

//using recursion
class Solution {
public:
	void reverse(vector<char>& s, int i, int j) {
		if(i >= j) 
			return;
		int tmp = move(s[i]);
		s[i++] = move(s[j]);
		s[j--] = move(tmp);
		reverse(s, i, j);
	}
	
	void reverseString(vector<char>& s) {
		reverse(s, 0, s.size() - 1);
	}
};

int main() {
	Solution s;
	vector<char> str{'h','e','l','l','o'};
	vector<char> s1;
	s.reverseString(str);
	for(char i : str) cout << i;
	return 0;
}
