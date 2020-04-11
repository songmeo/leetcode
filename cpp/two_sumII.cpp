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

//two pointer technique
//time O(n), space O(1) 
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
		auto it1 = numbers.begin();
		auto it2 = numbers.end() - 1;
		while(it1 < it2) {
			int sum = *it1 + *it2;
			if(sum == target) {
				result.push_back(it1 - numbers.begin() + 1);
				result.push_back(it2 - numbers.begin() + 1);
				return result;
			}
			else if(sum > target) {
				it2--;
			}
			else if(sum < target) {
				it1++;
			}
			else
				return vector<int>();
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
