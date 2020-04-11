#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//using std algorithm. This solution is faster than hash table :D
class Solution1 {
public:
  bool containsDuplicate(vector<int>& nums) {
    int s1 = nums.size();
    sort(nums.begin(), nums.end());
    auto it = unique(nums.begin(), nums.end());
    nums.resize(distance(nums.begin(), it));
    //we can also use nums.erase(unique(nums.begin(),nums.end()), nums.end());
    return s1 != nums.size();
  }
};

/*
use binarySearch (doesn't work because of memory exceeded)

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
    if(v.empty()) return 0;
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
*/

//use hash table
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for(int i : nums) {
      if(s.find(i) != s.end()) return true;
      else s.insert(i);
    }
    return false;      
  }
};

int main() {
  vector<int> v{1,2,3};
  Solution1 s;
  cout << s.containsDuplicate(v);
  return 0;
}

