#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> result;
		map<int,int> m;
		for(int i : nums) {
			m[i]++;
		}
		for(int i : nums) {
			int c = 0;
			for(auto it = m.begin(); it->first != i; ++it) {
				c += it->second;
			}
			result.push_back(c);
		}
		return result;
    }
};

int main() {
	vector<int> nums = {8,1,2,2,3};
	Solution s;
	for(int i : s.smallerNumbersThanCurrent(nums)) cout << i << " ";
	return 0;
}
