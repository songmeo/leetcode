#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
 * using map
 * time: O(n) because it's nlog(n) + n but there are always 3 elements in map so it's log(3)
 * space: O(1) 
*/
class Solution1 {
public:
	void sortColors(vector<int>& nums) {
		map<int,int> m;
		for(int i : nums)
			m[i]++;
		nums.clear();
		for(auto i : m) {
			while(i.second > 0) {
				nums.push_back(i.first);
				i.second--;
			}
		}
	}
};

/*
 * time: O(n)
 * space: O(1)
*/
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int smaller = 0, larger = nums.size() - 1;
		for(int i = 0; i < (int)nums.size(); i++) {
			if(nums[i] < 1)
				swap(nums[i], nums[smaller++]);
		}
		for(int i = (int)nums.size() - 1; i > 0; i--) {
			if(nums[i] > 1)
				swap(nums[i], nums[larger--]);
		}
	}
};

int main() {
	Solution s;
	vector<int> Colors{2, 0, 2, 1, 1, 0};
	s.sortColors(Colors);
	for(int i : Colors) cout << i << " ";
	return 0;
}
