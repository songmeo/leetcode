#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//using library
class Solution1 {
public:
  void Rotate(vector<int>& nums, int k) {
    rotate(nums.begin(),nums.end() - k, nums.end()); 
  }
};

int main() {
  Solution1 s;
  vector<int> v{1,2,3,4,5,6,7};
  s.Rotate(v, 3);
  for(int i : v) cout << i << " ";
  return 0; 
}
