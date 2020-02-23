#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }   
            }
        }
        return result;
    }
};

int main() {
    vector<int> v{1,2,3,4};
    Solution s;
    vector<int> result = s.twoSum(v,3);
    for(int i : result) cout << i << " ";
    return 0;
}
