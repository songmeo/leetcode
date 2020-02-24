#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  vector<int> result;
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    multimap<int,bool> m;
    for(int i : nums1) {
      m.insert(pair<int,bool>(i,false));
    }
    for(int i : nums2) {
      auto it = m.find(i);
      if(it != m.end()) {
        m.erase(it);
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
