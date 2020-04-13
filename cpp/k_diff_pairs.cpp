class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_set<int> s;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            auto tmp = find(nums.begin(), nums.end(), nums[i] + k);
            if(tmp != nums.end() && !s.count(nums[i]) && tmp - nums.begin() != i) {
                ans++;
                s.insert(nums[i]);
            }   
        }
        return ans;
    }
};
