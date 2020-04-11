#include <iostream>
using namespace std;

/*
fastest swap a and b
	a ^= b;
	b ^= a;
	a ^= b;
*/

class Solution {
public:
	int getSum(int a, int b) {
		if(a < 0 || b < 0) {
			if(a < 0) a = (-a) ^ 255;
			if(b < 0) b = (-b) ^ 255;
			return (a |= b) ^ 255;
		}
		return a |= b;
	}
};
 
int main() {
	Solution s;
	cout << s.getSum(5,10) << endl; //a = 101 b = 1010 a + b = 1111
	cout << s.getSum(2,3) << endl; //a = 10 b = 11 a + b = 11
	cout << s.getSum(0,-2) << endl; //a = 100 b = 10000010
	cout << s.getSum(2,-2); //a = 10 b = 10000010
	return 0;
}
