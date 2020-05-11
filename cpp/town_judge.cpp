#include <iostream>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int> in;
        unordered_map<int,int> out;
        for(vector<int> t : trust) {
            in[t[1]]++;
            out[t[0]]++;
        }
        for(int i = 1; i <= N; i++) {
            if(in[i] == N - 1 && out[i] == 0)
                return i;
        }
        return -1;
    }
};

int main() {
	Solution s;
	vector<vector<int>> trust = { {1,2} };
	cout << s.findJudge(2,trust);
	return 0;
}
