#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int result = 0;
		int tmp = x % 10;
		int i = 0;
		while(x) {
			tmp = x % 10;
			x /= 10;
			result += tmp * pow(10,i++);
		}
		
		return result;
	}
};

int main() {
	Solution s;
	cout << s.reverse(321);
}
