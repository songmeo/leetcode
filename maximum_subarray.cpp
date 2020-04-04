#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> nums) {
        int max_sum = nums[0];
        for(auto it1 = nums.begin(); it1 < nums.end(); it1++) {
            int sum = 0;
            for(auto it2 = it1; it2 < nums.end(); it2++) {
                sum += *it2;
                if(sum > max_sum) max_sum = sum;
            }
        }
        return max_sum;
    }
};

int main() {
	Solution s;
	cout << s.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}); // 4 -1 2 1 has largest sum 6
	return 0;
}
