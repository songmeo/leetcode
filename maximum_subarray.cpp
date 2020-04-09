#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

class Solution1 {
public:
    int maxSubArray(vector<int> nums) {
		list<int> lst;
        int sum = 0;
        for(auto it1 = nums.begin(); it1 < nums.end(); it1++) {
			lst.push_back(*it1);
			int tmp = sum;
			sum += *it1;
			if(sum < tmp) {
				sum -= *lst.begin();
				lst.pop_front();
			}
        }
        return sum;
    }
};
//using kadane algorithm 
class Solution {
public:
	int maxSubArray(vector<int> nums) {
		int ans = INT_MIN, tmp = 0;
		for(int i : nums) {
			tmp += i;
			ans = max(ans, tmp);
			tmp = max(tmp, 0);
		}
		return ans;
	}
};

int main() {
	Solution s;
	cout << s.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}); // 4 -1 2 1 has largest sum 6
	return 0;
}
