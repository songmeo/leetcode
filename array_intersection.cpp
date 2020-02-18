#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<int> intersection(std::vector<int> nums1, std::vector<int> nums2) {
    std::vector<int> result;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    for(int i = 0; i < nums1.size(); ++i) {
      for(int j = 0; j < nums2.size(); ++j) {
        if(nums1[i] == nums2[j])
          result.push_back(nums1[i]);
      }
    }
    result.erase(std::unique( result.begin(), result.end()), result.end());
    return result;  
  }
};

int main() {
  Solution s;
  //std::vector s1{4,9,5};
  //std::vector s2{9,4,9,8,4};
  for(int i : s.intersection({4,9,5},{9,4,9,8,4})) {
    std::cout << i << " ";
  }
  return 0;
}
