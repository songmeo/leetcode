#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int distinctPairs(vector<pair<int, int>>pairs, target) {
		for(pair p : pairs) {
			
		}
		return 0;
	}
};

int main() {
	vector<pair<int, int>> pairs;
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {5,4,3,2,1};
	for(int i = 0; i < (int)(sizeof(arr1)/sizeof(arr1[0])); i++) {
		pairs.push_back(make_pair(arr1[i], arr2[i]));
	}
	Solution s;
	cout << s.distinctPairs(pairs, 6);
	return 0;
}
