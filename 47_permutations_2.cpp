class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> counts(21, 0);
        for (auto& n: nums) {
            counts[n+10] += 1; // +10
        }
        
        vector<vector<int>> res = {};
        permutations(res, {}, counts, nums.size());
        
        return res;
    }
    
    void permutations(vector<vector<int>>& res, vector<int> curr, vector<int> counts, int num) {
        if (num == 0) {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] != 0) {
                
                counts[i] -= 1;
                curr.push_back(i-10);
                
                permutations(res, curr, counts, num-1);
                    
                curr.pop_back();
                counts[i] += 1;
            }
        }
    }
    
};
