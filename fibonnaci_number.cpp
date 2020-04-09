#include <iostream>
#include <vector>
using namespace std;

//dynamic programming
class Solution {
public:
	int fib(int N) {
		if(N == 0) return 0;
		if(N == 1) return 1;
		return fib(N - 1) + fib(N - 2);
	}
};

int main() {
	Solution s;
	cout << s.fib(2);
	return 0;
}
