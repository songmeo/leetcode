#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        vector<int> ans;
        for(int i = 0; i < mat.size(); i++) {
            auto p = make_pair(find(mat[i].begin(), mat[i].end(), 0) - mat[i].begin(),i);
            v.push_back(p);
        }
        sort(v.begin(), v.end()); //O(nlog(n))
        for(auto p : v) {
            cout << p.first << " " << p.second << endl;
        }
        int i = 0;
        while(i < k) {
            ans.push_back(v[i++].second);
        }
        return ans;
    }
};
