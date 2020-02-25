#include <iostream>
#include <vector>

using namespace std;

class Solution {
int result;
public:
  int removeDuplicates(vector<int>& nums) {
    result = nums.size();
    for(auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
      for(auto it2 = it1 + 1; it2 != nums.end() && *it2 == *it1; ++it2) {
        nums.erase(it2);
        --result;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums{0,0,1,1,1,2,2,3,3,4};
  cout << s.removeDuplicates(nums);
  return 0;
}
