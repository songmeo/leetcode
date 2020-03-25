#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int binarySearch(vector<int> & numbers, int target) {
		int min, mid, max;
		min = mid = max = 0;
		while(min <= max) {
			mid = (min + max)/2;
			if(target > numbers[mid])
				max = mid - 1;
			else if(target < numbers[mid])
				min = mid + 1;
			else
				return mid;
		}
		return -1;
	}
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
		unordered_map<int, int> m;
		for(int i = 0; i < (int)numbers.size(); i++) {
			int pos = binarySearch(numbers, target - numbers[i]);
			if(pos != -1 && pos != i) {
				result.push_back(i);
				result.push_back(pos);
				return result;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> v{2,7,11,15};
	for(int i : s.twoSum(v, 9)) {
		cout << i << " ";
	}
	return 0;
}
