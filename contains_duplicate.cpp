#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//using std algorithm
class Solution1 {
public:
  bool containsDuplicate(vector<int>& nums) {
    int s1 = nums.size();
    sort(nums.begin(), nums.end());
    auto ip = unique(nums.begin(),nums.end());
    nums.resize(distance(nums.begin(),ip));
    return s1 == nums.size();
  }
};

//use binarySearch
class Solution {
public:
  int binarySearch(vector<int>& v, int k) {
    int max = v.size() - 1;
    int min = 0;
    int mid;
    while(max >= min) {
      mid = (max + min)/2;
      if(v[mid] > k)
        max = mid - 1;
      else if(v[mid] < k)
        min = mid + 1;
      else
        return mid; 
    }
    return -1;
  }
  
  bool containsDuplicate(vector<int>& v) {
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 1; ++i) {
      vector<int> tmp(v.begin() + i + 1, v.end());
      if(binarySearch(tmp,v[i]) != -1) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  vector<int> v{1,2,3,1};
  Solution s;
  cout << s.containsDuplicate(v);
  return 0;
}

