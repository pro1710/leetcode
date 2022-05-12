class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result = {};
        vector<int> curr = {};
        solve(candidates, target, result, curr, 0);
        return result;
    }
    
    void solve(vector<int>& candidates, int target, vector<vector<int> >& result, vector<int>& curr, int pos) {
        
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        
        while (pos < candidates.size() && target - candidates[pos] >= 0) {

            curr.push_back(candidates[pos]); 

            solve(candidates, target - candidates[pos], result, curr, pos);
            ++pos;
            curr.pop_back();
        }
    }
};
