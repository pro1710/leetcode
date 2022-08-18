class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res = {};
        
        sort(begin(intervals), end(intervals));
        
        int c = 0;
        res.push_back(intervals[c]);
        
        for (int i = 1; i < intervals.size(); ++i) {

            if (res[c][1] < intervals[i][0]) {
                res.push_back(intervals[i]);
                ++c;
            } else if (res[c][0] <= intervals[i][0]) {
                if (res[c][1] <= intervals[i][1]) {
                    res[c][1] = intervals[i][1];
                }
            } 
        }
        return res;
    }
};
