class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res = {};
        auto curr = newInterval;
        
        for (int i = 0; i < intervals.size(); ++i) {
            
            auto& nxt  = intervals[i];
            
            if (curr[0] > nxt[1]) {
                res.push_back(nxt);
                continue;
            }
            
            if (curr[1] < nxt[0]) {
                res.push_back(curr);
                curr = {};
                copy(intervals.begin()+i, intervals.end(), back_inserter(res));
                break;
            }
            
            curr[0] = min(curr[0], nxt[0]);
            curr[1] = max(curr[1], nxt[1]);
            
        }
        
        if (curr.size()) {
            res.push_back(curr);
        }
        
        return res;
    }
};
