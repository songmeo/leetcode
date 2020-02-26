#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int s1 = nums.size();
    sort(nums.begin(), nums.end());
    auto ip = unique(nums.begin(),nums.end());
    nums.resize(distance(nums.begin(),ip));
    return s1 == nums.size();
  }
};

int main() {
  vector<int> v{2,3,1};
  Solution s;
  cout << s.containsDuplicate(v);
  return 0;
}

