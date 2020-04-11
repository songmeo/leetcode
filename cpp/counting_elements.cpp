class Solution {
public:
    int countElements(vector<int>& arr) {
        int result = 0;
        unordered_set<int> s;
        for(int i : arr) {
            s.insert(i);
        }
        for(int i : arr) {
            if(s.find(i + 1) != s.end()) result++;
        }
        return result;
    }
};
