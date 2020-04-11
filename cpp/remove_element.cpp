#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int result;
  int binarySearch(vector<int>& v, int k) {
    int min = 0;
    int max = v.size() - 1;
    int mid;
    while(max >= min) {
      mid = (max + min)/2;
      if(k > v[mid])
        min = mid + 1;
      else if(k < v[mid])
        max = mid - 1;
      else
        return mid;
    }
    return -1;
  }
  int removeElement(vector<int>& nums, int val) {
    sort(nums.begin(), nums.end());
    while(binarySearch(nums,val) != -1) {
      nums.erase(nums.begin() + binarySearch(nums,val));
    }
    return nums.size();  
  }
};

int main() {
  Solution s;
  vector<int> v{3,2,2,3};
  cout << s.removeElement(v,3);
  return 0;  
}
