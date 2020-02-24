#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> result;
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,bool> m;
    for(int i : nums1) {
      m[i] = false;
    }
    for(int i : nums2) {
      if(m.count(i) && !m[i]) {
        m[i] = true;
        result.push_back(i);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> v1{1,9,4};
  vector<int> v2{9,4};
  for(int i : s.intersect(v1,v2)) cout << i << " ";
  return 0;
}
