#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(auto it = digits.rbegin(); it != digits.rend(); it++) {
            if(*it != 9) {
                *it += 1;
                return digits;
            }
            else if(it == digits.rend() - 1) {
                *it = 0;
                digits.insert(digits.begin(),1);
                return digits;
            }
            else {
                *it = 0;
            }
        }
        return digits;
    }
};

int main() {
	vector<int> v{9,9,9};
	Solution s;
	for(int i : s.plusOne(v))
		cout << i << i;
	return 0;
}
