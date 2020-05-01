// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        if(!isBadVersion(n)) return -1;
        long low = 1, high = n, mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(isBadVersion(mid)) {
                high = mid - 1;
                if(!isBadVersion(high)) return mid;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
