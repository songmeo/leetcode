#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
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

int main() {
	vector<int> v = {2,2,1};
	Solution s;
	cout << s.singleNumber(v) << endl;
	return 0;
}
