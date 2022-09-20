class Solution {
public:
    
    void subsets(vector<vector<int>>& res, vector<int> curr, int idx, vector<int>& nums) {
        
        res.push_back(curr);
        
        for (int i = idx; i < nums.size(); ++i) {
            if (nums[i]) {
                nums[i]--;
                curr.push_back(i-10);
                subsets(res, curr, i, nums);
                curr.pop_back();
                nums[i]++;
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> accum(21,0);
        for (auto& n: nums) {
            accum[n+10]++;
        }
        
        vector<vector<int>> res{};
        subsets(res, {}, 0, accum);
        
        return res;
        
    }
};
