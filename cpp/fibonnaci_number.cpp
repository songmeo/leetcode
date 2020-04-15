#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//recursive way
class Solution2 {
public:
	int fib(int N) {
		if(N == 0) return 0;
		if(N == 1) return 1;
		return fib(N - 1) + fib(N - 2);
	}
};

/*
 * using memorization
 * memorized calls cost O(1)
 * non-memorized calls (the first time call) is O(n)
 * time -> O(n)
*/
class Solution1 {
public:
	unordered_map<int, int> m{{0,0},{1,1}};
	int fib(int n) {
		if(m.count(n) > 0)
			return m[n];
		else {
			m[n] = fib(n -1) + fib(n-2);
			return m[n];
		}
	}	
};

/*
 * bottom-up way
 * exact time as memorization
 * topological sort for DAG
 * optimizing: only remember 2 last elements
 */
class Solution {
public:
	int fib(int n) {
		vector<int> f{0,1};
		for(int i = 2; i <= n; i++) {
			f.push_back(f[i - 1] + f[i - 2]);
		}
		return f[n];
	};
};

int main() {
	Solution s;
	cout << s.fib(6);
	/*
	vector<int> f{1,1};
	f[2] = 2;
	for(int i : f) cout << i << " ";
	*/
	return 0;
}
