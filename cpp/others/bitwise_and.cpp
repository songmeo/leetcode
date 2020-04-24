/*
 * given a binary sequence, find the bitwise and of a range
 */
 #include <iostream>
 #include <string>
 using namespace std;

class Solution {
public:
	int next0(string &s, int pos) {
		for(int i = pos; i < (int) s.size() - 1; i++) {
			if(s[i] == '0')
				return i;
		}
		return -1;
	}
	
	int bitwise_and(string &s, int i, int j) {
		if(j > (int) s.size() - 1 || j < i) return -1;
		if(next0(s,i) > j)
			return 1;
		return 0;
	}
};

int main() {
	Solution s;
	string str = "01101010110";
	cout << s.bitwise_and(str, 2, 5);
	return 0;
}
