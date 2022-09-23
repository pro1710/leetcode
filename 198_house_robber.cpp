class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        nums[nums.size()-2] = max(nums[nums.size()-2], nums[nums.size()-1]);
        
        for (int i = nums.size()-3; i >= 0; --i) {
            nums[i] = max(nums[i+1], nums[i+2] + nums[i]);
        }
        
        return nums[0];
    }
};
