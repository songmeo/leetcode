#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pos(vector<int> v, int k) {
		if(v.empty()) return 0;
		int max = v.size() - 1, min = 0, mid = 0;
		while(max >= min) {
			mid = (max + min)/2;
			if(v[mid] == k)
				return mid;
			else if(k < v[mid])
				max = mid - 1;
			else
				min = mid + 1;
		}
		return (k > v[mid])?mid+1:mid;
	}
	
    int lastStoneWeight(vector<int> stones) {
        sort(stones.begin(), stones.end());
        for(auto it = stones.rbegin(); stones.size() > 1 && it != stones.rend();) {
            int first = *it, second = *(it + 1);
            int tmp = abs(first - second);
            stones.pop_back();
            stones.pop_back();
            if(tmp)
                stones.insert(stones.begin() + pos(stones, tmp), tmp);
            if(stones.size() == 0) return 0;
            it = stones.rbegin();
        }
        
        return stones.empty()?0:stones[0];
    }
};

int main() {
	vector<int> v = {};
	Solution s;
	cout << s.lastStoneWeight({2,7,4,1,8,1});
	return 0;
}
