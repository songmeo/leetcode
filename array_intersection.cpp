#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

class Solution1 {
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

//this one uses set because set elements are ordered and unique so we could avoid duplicates
class Solution2 {
public:
  std::set<int> s1,s2;
  std::vector<int> result;
  std::vector<int> intersection(std::vector<int> v1, std::vector<int> v2) {
    for(int i : v1) s1.insert(i);
    for(int i : s1) {
      if(std::find(v2.begin(), v2.end(), i) != v2.end()) s2.insert(i);
    }
    for(int i : s2) result.push_back(i);
    return result;
  }
};

//this one uses unordered_set. Unordered set is faster than set to access individual elements by their key, and less efficient for range iteration
class Solution3 {
  public:
    std::vector<int> result;
    std::vector<int> intersection(std::vector<int> v1, std::vector<int> v2) {
      /*
      for(int i : v1) s1.insert(i);
      for(int i : v2) {
        if(s1.find(i) != s1.end() && find(result.begin(), result.end(), i) == result.end()) result.push_back(i);
      }
      */
      std::unordered_set<int> s1(v1.begin(),v1.end());
      for(auto &it : v2) {
        if(s1.count(it)) {
          result.push_back(it);
          s1.erase(it);
        }
      }
      return result;
    }
};

int main() {
  Solution3 s;
  //std::vector s1{4,9,5};
  //std::vector s2{9,4,9,8,4};
  for(int i : s.intersection({4,9,5},{9,4,9,8,4})) {
    std::cout << i << " ";
  }
  return 0;
}
