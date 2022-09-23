class Solution {
public:
    int rob(vector<int>& nums) {
    
        if (nums.size() == 1) {
            return nums.front();
        }
        
        int best = 0;
        for (int p = 0; p <= 1; ++p) {
            // p == 0: without 1st
            // p == 1: withour last
            int first_best = nums[nums.size()-1-p]; 
            int second_best = 0; 
            
            for (int i = nums.size()-2-p; i > -p; --i) {
            
                int tmp = max(first_best, nums[i]+second_best);

                second_best = first_best;
                first_best = tmp;                
            }
            best = max(best, max(first_best, second_best));
        }
        
        return best;
    }
};
