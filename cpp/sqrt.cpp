#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
	int sqrt(int x) {
		return (int) std::sqrt(x);
	}
};

int main() {
	Solution s;
	cout << s.sqrt(4) << endl;
	cout << s.sqrt(8) << endl;
	return 0;
}
