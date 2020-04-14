class Solution {
public:
    int pos(vector<int> v, int k) {
        int min = 0, max = v.size() - 1;
        int mid = 0;
        while(min <= max) {
            mid = (min + max)/2;
            if(v[mid] == k) return mid;
            else if(v[mid] > k) {
                max = mid - 1;
            }
            else
                min = mid + 1;
        }
        return mid;
    }
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        //1 1 2 4 7 8
        for(auto it = stones.rbegin(); it != stones.rend() && stones.size() > 1;) {
            int first = *it, second = *(it + 1);
            int tmp = abs(first - second);
            stones.pop_back();
            stones.pop_back();
            cout << pos(stones,tmp);
            stones.insert(stones.begin() + pos(stones, tmp), tmp);
            it = stones.rbegin();
        }
        return stones[0];
    }
};
