#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int binarySearch(vector<int> & numbers, int target) {
		int min, mid, max;
		min = 0, max = numbers.size() - 1;
		while(numbers[min] <= numbers[max]) {
			mid = (min + max)/2;
			if(target < numbers[mid])
				max = mid - 1;
			else if(target > numbers[mid])
				min = mid + 1;
			else
				return mid;
		}
		return -1;
	}
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
		for(int i = 0; i < (int)numbers.size() - 1; i++) {
			vector<int> v(numbers.begin() + i + 1, numbers.end());
			int pos = binarySearch(v, target - numbers[i]);
			if(pos != -1) {
				result.push_back(i + 1);
				result.push_back(pos + i + 1 + 1);
				return result;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> v{5,25,75};
	for(int i : s.twoSum(v, 100)) {
		cout << i << " ";
	}
	return 0;
}
