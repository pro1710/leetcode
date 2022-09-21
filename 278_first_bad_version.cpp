// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binSearchFirst(0, n);
    }
    
    int binSearchFirst(int lo, int hi) {
        
        int mid = lo + (hi-lo)/2;
        
        if (lo == hi) {
            return lo;
        }
        
        if (isBadVersion(mid)) {
            return binSearchFirst(lo, mid);
        }
        
        return binSearchFirst(mid+1, hi);
    }
    
};
