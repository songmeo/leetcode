#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool hasDuplicate(vector<int> v) {
		unordered_set<int> s;
		for(int i : v) {
			s.insert(i);
		}
		return s.size() != v.size();
	}
	
	string trace(vector<vector<int>> matrix) {
		ostringstream ans;
		
		//find trace
		int trace = 0;
		for(int i = 0; i < (int) matrix.size(); i++) {
			trace += matrix[i][i];
		}
		
		//find row
		int row = 0;
		for(vector<int> v : matrix) {
			if(hasDuplicate(v)) 
				row++;
		}
		
		//find column
		int column = 0;
		int c = 0;
		while(c < (int) matrix.size()) {
			int r = 0;
			vector<int> tmp;
			while(r < (int) matrix.size()) {
				tmp.push_back(matrix[r++][c]);
			}
			if(hasDuplicate(tmp)) column++;
			c++;
		}
		
		ans << trace << " " << column << " " << row;
		return ans.str();
	}
};

int main() {
	Solution s;
	vector<vector<int>> matrix(5,vector<int>(5));
	matrix = {
		{0,0,1,2},
		{1,2,3,4},
		{2,3,4,5},
		{4,3,2,1}};
	cout << s.trace(matrix);
}
