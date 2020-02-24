#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
  vector<int> result;
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    set<int> s;
    for(int i : nums1) {
      s.insert(i);
    }
    for(int i : nums2) {
      auto it = s.find(i);
      if(it != s.end()) {
        s.erase(it);
        result.push_back(i);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> v1{1,2,2,1};
  vector<int> v2{2,2};
  for(int i : s.intersect(v1,v2)) cout << i << " ";
  return 0;
}
