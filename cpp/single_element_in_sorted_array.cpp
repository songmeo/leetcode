#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};

int main() {
	vector<int> nums = {3,3,7,7,10,11,11};
	Solution s;
	cout << s.singleNonDuplicate(nums);
	return 0;
}
