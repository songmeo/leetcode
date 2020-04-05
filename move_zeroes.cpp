#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
		int repeat = 0;
        for(auto it = nums.begin(); it != nums.end();) {
            if(*it == 0 && repeat <= (int)nums.size()) {
				rotate(it, it + 1, nums.end());
				repeat++;
			}
			else 
				it++;
        }
    }
};

int main() {
	Solution s;
	vector<int> v = {0,0,1};
	s.moveZeroes(v);
	for(int i : v)
		cout << i;
	return 0;
}
