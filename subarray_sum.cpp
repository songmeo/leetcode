#include <iostream>
#include <vector>
#include <set>
using namespace std;

//O(n^2) time exceeded
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

class Solution {
public: //1 1 1
	int subarraySum(vector<int> nums, int k) {
		set<int> sums { 0 };
		int count = 0;
		int sum = 0;
		for(int i = 0; i < (int) nums.size(); i++) {
			sum += nums[i];
			sums.insert(sum);
			if(sums.find(sum - k) != sums.end()) count++;
		}
		return count;
	}
	
};

int main() {
	Solution s;
	cout << s.subarraySum({1,1,1}, 2) << endl;
	return 0;
}
