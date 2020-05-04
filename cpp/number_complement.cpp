/*
 * Given a positive integer, output its complement number. 
 * The complement strategy is to flip the bits of its binary representation.
 */
#include <iostream>
using namespace std;

class Solution {
public:
	int number_complement(int k) {
		int ans = 0;
		bool met = false;
		for(int i = 30; i >= 0; i--) {
			int tmp = k & (1 << i);
			if(tmp != 0 && !met) 
				met = true;
			else if(!met)
				continue;
			if(tmp == 0)
				ans |= (1 << i);
		}
		return ans;
	}
};

int main () {
	Solution s;
	cout << s.number_complement(5);
	return 0;
}
