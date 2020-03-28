#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool negative = false;
		if(x < 0) {
			if(x < INT_MAX*(-1))
				return 0;
			x *= -1;
			negative = true;
		}
		int result = 0;
		while(x) {
			int tmp = x % 10;
			if(result > INT_MAX/10) {
				return 0;
			}
			result = result*10 + tmp;
			x /= 10;
		}
		return negative?-1*result:result;
	}
};

int main() {
	Solution s;
	cout << s.reverse(321) << endl;
	cout << s.reverse(-321) << endl;
	cout << s.reverse(120) << endl;
	cout << s.reverse(1534236469) << endl;
}
