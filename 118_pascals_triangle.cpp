class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        res[0] = {1};
        for (int i  = 1; i < numRows; ++i) {
            res[i] = nexRow(res[i-1]);
        }
        return res;
    }

    vector<int> nexRow(const vector<int>& prev) {
        vector<int> next(prev.size()+1, 1);
        for (int i = 1; i < next.size()-1; ++i) {
            next[i] = prev[i-1] + prev[i];
        }
        return move(next);
    }
};
