#include <iostream>
#include <vector>
#include <set>
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
			sum += i*i;
		}
		return sum;
	}
	
	bool isHappy(int n) {
		set<int> s;
		int tmp = n;
		while(tmp != 1) {
			tmp = next_sum(tmp);
			if(s.find(tmp) != s.end()) return false;
			s.insert(tmp);
		}
		return true;
	}
};

int main() {
	Solution s;
	cout << s.isHappy(18);
	return 0;
}
