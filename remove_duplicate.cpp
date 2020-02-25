#include <iostream>
#include <vector>

using namespace std;

class Solution {
int result;
public:
  int removeDuplicates(vector<int>& nums) {
    result = nums.size();
    for(int i = 0; i < nums.size(); ++i) {
      for(auto it = nums.begin() + i + 1; it != nums.end() && *it == nums[i]; ++it) {
        nums.erase(it);
        result--;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums{0,0,1,2};
  cout << s.removeDuplicates(nums);
  return 0;
}
