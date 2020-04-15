#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxConsecutive(vector<int>& nums) {
		int sum = 0;
		int ans = 0;
		for(int i : nums) {
			if(i == 0) sum = 0;
			sum += i;
			ans = max(sum, ans);
		}
		return ans;
	}
};

int main() {
	vector<int> v = {1,1,0,1,1,1};
	Solution s;
	cout << s.maxConsecutive(v);
}
