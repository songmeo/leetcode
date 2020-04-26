#include <iostream>
#include <vector>
using namespace std;

/*
 * printing a 2-dimensional matrix in spiral clockwise order
 */
 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        int dir = 0;
        vector<int> ans;
		while(top <= bottom && left <= right) {
			if(dir == 0) {
				for(int i = left; i <= right; i++) {
					ans.push_back(matrix[top][i]);
				}
				top++;
			}
			else if(dir == 1) {
				for(int i = top; i <= bottom; i++) {
					ans.push_back(matrix[i][right]);
				}
				right--;
			}
			else if(dir == 2) {
				for(int i = right; i >= left; i--) {
					ans.push_back(matrix[bottom][i]);
				}
				bottom--;
			}
			else {
				for(int i = bottom; i >= top; i--) {
					ans.push_back(matrix[i][left]);
				}
				left++;
			}
			dir = (dir + 1)%4;
		}
		return ans;
    }
};

int main() {
	vector<vector<int>> v = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}
	};
	Solution s;
	for(int i : s.spiralOrder(v)) {
		cout << i << " ";
	}
	return 0;
}
