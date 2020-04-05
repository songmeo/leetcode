#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> nums) {
        for(auto it = nums.begin(); it != nums.end();) {
            if(*it == 0)
                rotate(it, it + 1, nums.end());
            else
                it++;
        }
    }
};

int main() {
	Solution s;
	cout << s.moveZeroes({0,1,0,3,12});
	return 0;
}
