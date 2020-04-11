#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
using library doesn't work for cases when nums size is smaller than k
class Solution1 {
public:
  void rotate(vector<int>& nums, int k) {
    std::rotate(nums.begin(),nums.end() - k, nums.end()); 
  }
};
*/

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    while(k--) {
	  nums.insert(nums.begin(), *(nums.end() - 1));
	  nums.pop_back();
	}
  }
};

int main() {
  Solution* s = new Solution();
  vector<int> v{1,2,3,4,5,6};
  s->rotate(v, 3);
  for(int i : v) cout << i << " ";
  return 0; 
}
