class Solution {
public:
    
    void combinations(vector<vector<int>>& res, 
                      const vector<int>& options, 
                      vector<int> comb, 
                      int start,
                      int index, int r) {
        
        if (r==0) {
            res.push_back(comb);
            return;
        }
        
        for (int i = start, e = options.size(); i < e && e-i+1 >= r; ++i) {
            comb[index] = options[i];
            combinations(res, options, comb, i+1, index+1, r-1);
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res = {};
        vector<int> tmp(k);
        vector<int> options = {};
        for (int i = 0; i < n; ++i) {
            options.push_back(i+1);
        }
        
        combinations(res, options, tmp, 0, 0, k);
        return res;
    }
};
