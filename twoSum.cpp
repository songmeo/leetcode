#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

//O(n^2) solution
class Solution1 {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for(int i = 0; i < nums.size(); ++i) {
      for(int j = i + 1; j < nums.size(); ++j) {
        if(nums[i] + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
        }   
      }
    }
    return result;
  }
};

//unordered map or hashmap insert and access time is in O(1)
class Solution2 {
  public:
  vector<int> result;
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); ++i) {
      if(map.find(target - nums[i]) == map.end()) {
        map[nums[i]] = i;
      }
      else {
        result.push_back(map[target-nums[i]]);
        result.push_back(i);
      }
    }
    return result;
  }  
};

int main() {
    vector<int> v{1,2,3,4};
    Solution2 s;
    vector<int> result = s.twoSum(v,3);
    for(int i : result) cout << i << " ";
    return 0;
}
