#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double slope(vector<int> c1, vector<int> c2) {
        return (double) (c1[1] - c2[1]) /  (c1[0] - c2[0]);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2) return true;
        double s = slope(coordinates[1], coordinates[0]);
        for(int i = 2; i < coordinates.size(); i++) {
            double tmp = slope(coordinates[i],coordinates[0]);
            if(tmp != s)
                return false;
        }
        return true;
    }
};

int main() {
	vector<vector<int>> v = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
	Solution s; 
	cout << s.checkStraightLine(v);
	return 0;
}
