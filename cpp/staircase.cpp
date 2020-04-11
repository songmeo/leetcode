#include <iostream>
#include <vector>
using namespace std;

//fibonacci way
class Solution1 {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        return climbStairs(n - 1) + climbStairs(n-2);
    }
};

//bottom up way
class Solution {
public:
	int climbStairs(int n) {
		vector<int> arr(n + 1);
		arr[0] = 1;
		arr[1] = 1;
		for(int i = 2; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[n];
	}
};

int main() {
	Solution s;
	cout << s.climbStairs(44);
	return 0;
}

