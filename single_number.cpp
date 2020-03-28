#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

//O(n) but use extra memory
class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> m;
		for(int i : nums) {
			m[i]++;
		}
		for(auto p : m) {
			if(p.second == 1) {
				return p.first;
			}
		}
		return 0;
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		set<int> s;
		for(auto it = nums.begin(); it != nums.end(); it++) {
			auto tmp = find(it + 1, nums.end(), *it); 
			if(tmp != nums.end()) s.insert(*it);
			else if(s.count(*it) == 0 && tmp == nums.end())
				return *it;
		}
		return 0;
	}
};

int main() {
	vector<int> v = {2,2,1};
	Solution s;
	cout << s.singleNumber(v) << endl;
	return 0;
}
