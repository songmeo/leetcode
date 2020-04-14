#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pos(vector<int> v, int k, int max, int min) {
        if(v.empty()) return 0;
        if(max <= min) 
          return (k > v[min])?(min + 1):min;
        int mid = (max + min) / 2;
        if(k == v[mid])
          return mid;
        else if(k < v[mid])
          return pos(v, k, mid - 1, min);
        else
          return pos(v, k, max, mid + 1);
    }
    int lastStoneWeight(vector<int> stones) {
        sort(stones.begin(), stones.end());
        for(auto it = stones.rbegin(); stones.size() > 1 && it != stones.rend();) {
            int first = *it, second = *(it + 1);
            int tmp = abs(first - second);
            stones.pop_back();
            stones.pop_back();
            if(tmp)
                stones.insert(stones.begin() + pos(stones, tmp, stones.size() - 1, 0), tmp);
            if(stones.size() == 0) return 0;
            it = stones.rbegin();
        }
        
        return stones.empty()?0:stones[0];
    }
};

int main() {
	vector<int> v = {};
	Solution s;
	cout << s.lastStoneWeight({3,1});
	return 0;
}
