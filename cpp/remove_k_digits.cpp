#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int min = INT_MAX;
        if(k == num.length()) {
            return "0";
        } 
        //0 1 2 3 4 5
        for(int i = 0; i <= num.size() - k; i++) {
            string tmp_s = num;
            int tmp_i = 0;
            tmp_s.erase(i,k);
            tmp_i = stoi(tmp_s);
            cout << tmp_i <<endl;
            if(tmp_i < min) {
                min = tmp_i;
                ans = tmp_s;
            }
        }
        while(ans.length() > 1 && ans[0] == '0') {
            ans.erase(0,1);
        }
        return ans;
    }
};

int main() {
	string num = "102000";
	Solution s;
	cout << s.removeKdigits(num, 1);
	return 0;
}
