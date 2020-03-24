#include <iostream>
#include <vector>
using namespace std;

//O(n^2)
class Solution1 {
public:
	int subarraySum(vector<int> nums, int k) {
		int result = 0;
		for(auto it1 = nums.begin(); it1 != nums.end(); it1++) {
			int tmp = *it1;
			if(tmp == k) result++;
			for(auto it2 = it1 + 1; it2 != nums.end(); it2++) {
				tmp += *it2;
				if(tmp == k) result++;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.subarraySum({1,1,1}, 2) << endl;
	return 0;
}
