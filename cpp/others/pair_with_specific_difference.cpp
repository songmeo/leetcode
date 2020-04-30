/*
 * finding with pair (x,y) in given array so that x - y = k
 * maintain the order of y
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<int>> specificDifference(vector<int> arr, int k) {
		unordered_set<int> m;
		vector<vector<int>> ans;
		for(int i : arr) {
			m.insert(i);
		}
		for(int i : arr) {
			if(m.count(i + k) > 0) {
				vector<int> pair{i + k, i};
				ans.push_back(pair);
			}
		}
		return ans;
	}
};

int main() {
	vector<int> arr{0,1,2,4,3};
	Solution s;
	for(vector<int> p : s.specificDifference(arr, 1)) {
		for(int i : p ) cout << i << " ";
		cout << endl;
	}
	return 0;
}
