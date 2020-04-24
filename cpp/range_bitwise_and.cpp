#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for(int bit = 30; bit >= 0; bit--) {
            if((m & (1 << bit)) != (n & (1 << bit))) {
                break;
            }
            else {
                ans |= (m & (1 << bit));
            }
        }
        return ans;
    }
};

int main() {
	Solution s;
	cout << s.toString(5);
	cout << s.rangeBitwiseAnd(5,7);
	return 0;
}
