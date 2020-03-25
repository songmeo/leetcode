#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//binary search 
class Solution1 {
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

//library binary search
class Solution2 {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
		unordered_map<int,int> m;
		for(int i = 0; i < (int)numbers.size(); i++) {
			m[numbers[i]] = i;
		}
		for(int i = 0; i < (int) numbers.size(); i++) {
			if(binary_search(numbers.begin() + i + 1, numbers.end(), target - numbers[i])) {
				result.push_back(i + 1);
				result.push_back(m[target - numbers[i]] + 1);
				return result;
			}
		}
		return result;
	}
};
//time exceeded
class Solution {
public:
	vector<int> twoSum(vector<int> & numbers, int target) {
		vector<int> result;
		for(int i = 0; i < (int) numbers.size(); i++) {
			auto pos = find(numbers.begin() + i + 1, numbers.end(), target - numbers[i]);
			if(pos != numbers.end()) {
				result.push_back(i + 1);
				result.push_back(pos - numbers.begin() + 1);
			}
		}
		return result;
	}
};

int main() {
	Solution2 s;
	vector<int> v{2,7,11,15};
	for(int i : s.twoSum(v, 9)) {
		cout << i << " ";
	}
	return 0;
}
