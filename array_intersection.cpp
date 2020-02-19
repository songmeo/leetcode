#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

class OldSolution {
public:
  std::vector<int> result;
  std::vector<int> intersection(std::vector<int> nums1, std::vector<int> nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    for(int i = 0; i < nums1.size(); ++i) {
      for(int j = 0; j < nums2.size(); ++j) {
        if(nums1[i] == nums2[j])
          result.push_back(nums1[i]);
      }
    }
    result.erase(std::unique( result.begin(), result.end()), result.end()); //unique returns the pointer to the element next to the last element which is not removed
    return result;  
  }
};

//this one uses set because set elements are ordered and unique
class Solution {
public:
  std::set<int> s1,s2;
  std::vector<int> intersection(std::vector<int> n1, std::vector<int> n2) {

        
  }
};


int main() {
  OldSolution s;
  //std::vector s1{4,9,5};
  //std::vector s2{9,4,9,8,4};
  for(int i : s.intersection({4,9,5},{9,4,9,8,4})) {
    std::cout << i << " ";
  }
  return 0;
}
