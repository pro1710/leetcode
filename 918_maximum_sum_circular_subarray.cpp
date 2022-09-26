class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int sum = 0;
        int min_sum = 1e5;
        int max_sum = -1e5;
        
        int curr_max = -1e5;
        int curr_min = 1e5;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            curr_max = max(nums[i], curr_max + nums[i]);
            max_sum = max(max_sum, curr_max);
            
            curr_min = min(nums[i], curr_min + nums[i]);
            min_sum = min(min_sum, curr_min);
            
            sum += nums[i];
        }
        
        if (max_sum < 0) {
            return max_sum;
        }        
        return max(max_sum, sum - min_sum);
    }
};
