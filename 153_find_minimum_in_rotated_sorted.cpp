class Solution {
public:
    int findMin(vector<int>& nums) {
        return bs(nums, 0, nums.size()-1);
    }
    
    int bs(const vector<int>& nums, int b, int e) {
        
        if (e==b) {
            return nums[e];
        }
        
        int mid = b + (e-b)/2;
        
        if (nums[mid] > nums[e]) {
            return bs(nums, mid+1, e);
        }
        
        return bs(nums, b, mid);
    }
};
