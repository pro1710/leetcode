class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();
        
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            
            if (lo == hi) {
                break;
            }
            
            if (target > nums[mid]) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
