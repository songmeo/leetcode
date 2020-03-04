#include <iostream>
#include <vector>
#include <map>

using namespace std;
//using map
class Solution {
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

int main() {
	Solution s;
	vector<int> Colors{2, 0, 2, 1, 1, 0};
	s.sortColors(Colors);
	for(int i : Colors) cout << i << " ";
	return 0;
}
