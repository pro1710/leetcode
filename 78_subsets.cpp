class Solution {
public:
    
    void dfs(vector<vector<int>>& res, vector<int> opt, vector<int> sub, int l) {
        
        res.push_back(sub);
        
        for (int i = l; i < opt.size(); ++i) {
            sub.push_back(opt[i]);
            dfs(res, opt, sub, i+1);
            sub.pop_back();
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        dfs(res, nums, {}, 0);
        return res;
    }
};
