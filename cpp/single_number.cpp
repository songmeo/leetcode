#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//O(n) but use extra memory
class Solution1 {
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

//using set and find std (even slower)
class Solution2 {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> s;
		for(auto it = nums.begin(); it != nums.end(); it++) {
			auto tmp = find(it + 1, nums.end(), *it); 
			if(tmp != nums.end()) s.insert(*it);
			else if(s.count(*it) == 0 && tmp == nums.end())
				return *it;
		}
		return 0;
	}
};

//using std erase and find. still slower than hash map
class Solution3 {
public:
	int singleNumber(vector<int>& nums) {
		for(auto it = nums.begin(); it != nums.end();) {
			auto tmp = find(it + 1, nums.end(), *it); 
			if(tmp != nums.end()) {
				nums.erase(tmp);
				nums.erase(it);
			}
			else {
				it++;
			}
		}
		return nums[0];
	}
};

//math. as fast as hash map
class Solution4 {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> s;
		int tmp = 0;
		for(int i : nums) {
			s.insert(i);
			tmp += i;
		}
		for(int i : s){
			tmp -= i*2;
		}
		return tmp*-1;
	}
};

//bit manipulation. O(n) time, O(1) space
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for(int i : nums) {
			result ^= i;
		}
		return result;
	}
};

int main() {
	vector<int> v = {4,1,2,1,2};
	Solution s;
	cout << s.singleNumber(v) << endl;
	return 0;
}
