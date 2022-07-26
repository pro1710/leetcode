class Solution {
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        constexpr int max_len = 100;
        constexpr int max_target = 30;
        
        vector<int> nums(max_target+1, 0);
        for (auto& n: candidates) {
            if (n > target) {
                continue;
            }
            nums[n] += 1;
        }
        
        vector<int> candidate{};
        vector<vector<int>> res{};
        find_nums(nums, target, candidate, res);

        return res;
        
    }
    
    void find_nums(vector<int>& nums, int target, vector<int>& candidate, vector<vector<int>>& res) {
  
        if (target == 0) {
            res.push_back(candidate);
            return;
        }
        
        for (int i = 1; i <= target; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            
            if (!candidate.empty() && candidate.back() > i) {
                continue;
            }
            
            nums[i] -= 1;
            candidate.push_back(i);

            find_nums(nums, target - i, candidate, res);
            
            candidate.pop_back();
            nums[i] += 1;
        }
    }
    
};
