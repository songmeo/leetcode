#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int kSubsequence(vector<int> nums, int k) {
		int result = 0;
		for(auto it1 = nums.begin(); it1 != nums.end(); it1++) {
			if(*it1 % 5 == 0) result++;
			int tmp = *it1;
			for(auto it2 = it1 + 1; it2 != nums.end(); it2++) {
				tmp += *it2;
				if(tmp % 5 == 0)
					result++;
			}
		}
		return result;
	}
};

int main() {
	vector<int> nums{5,10,11,9,5};
	Solution s;
	cout << s.kSubsequence(nums, 5) << endl;
	return 0;
}
