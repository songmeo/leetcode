#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
 * complexity for searching:
 * map: O(log(n))
 * unordered_map: O(1)
 * vector: O(n)
 */
class Solution {
public:
	vector<int> twoSum(vector<int> nums, int target) {
		vector<int> result;
		unordered_map<int,int> m;
		for(int i = 0; i < (int)nums.size(); i++) {
			m[nums[i]] = i;
		}
		for(int i = 0; i < (int)nums.size(); i++) {
			if(m.count(target - nums[i]) && i != m[target - nums[i]]) {
				result.push_back(i);
				result.push_back(m[target - nums[i]]);
				return result;
			}
		}
		return result;
	}
};


int main() {
	Solution s;
	vector<int> result = s.twoSum({2, 7, 11, 15}, 9);
	for(int i : result) {
		cout << i << " ";
	}
	return 0;
}
