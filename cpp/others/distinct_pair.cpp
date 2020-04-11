#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pairs;
class Solution {
public:
	int distinctPairs(vector<int> nums, int target) {
		sort(nums.begin(), nums.end());
		set<pairs> v;
		for(int i = 0; i < (int)nums.size(); i++) {
			auto it = find(nums.begin() + i, nums.end(), target-nums[i]);
			if(it != nums.end()) {
				pairs x = make_pair(nums[i], *it);
				v.insert(x);
			}
		}
		for(pairs p : v) {
			cout << p.first << " " << p.second << endl;
		}
		return v.size();
	}
};

int main() {
	vector<int> nums = {1, 2, 3, 6, 7, 8, 9, 1};
	Solution s;
	cout << s.distinctPairs({1, 2, 3, 6, 7, 8, 9, 1}, 10) << endl;
	cout << s.distinctPairs({1, 3, 46, 1, 3, 9}, 47) << endl;
	return 0;
}
