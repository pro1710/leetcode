class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        return binSearch(nums, 0, nums.size()-1, target);
        
    }
    
    int binSearch(const vector<int>& nums, int lo, int hi, int target) {
        
        int mid = lo + (hi-lo)/2;
        
        if (lo == hi) {
            if (target == nums[lo]) {
                return lo;
            } else {
                return -1;
            }
        }
        
        if (target > nums[mid]) {
            return binSearch(nums, mid+1, hi, target);
        } 
        
        return binSearch(nums, lo, mid, target);
        
    }
    
};
