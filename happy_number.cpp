#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int next_sum(int n) {
		vector<int> v;
		int sum = 0;
		while(n) {
			v.push_back(n % 10);
			n /= 10;
		}
		for(int i : v) {
			cout << i << " ";
			sum += i*i;
		}
		cout << endl;
		return sum;
	}
	
	bool isHappy(int n) {
		int tmp = n;
		while(tmp != 1) {
			tmp = next_sum(tmp);
		}
		return true;
	}
};

int main() {
	Solution s;
	cout << s.isHappy(18);
	return 0;
}
