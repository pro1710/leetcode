class Solution {
    
public:
    vector<int> getRow(int rowIndex) {
            
        vector<int> res = {1};
        for (int i  = 0; i < rowIndex; ++i) {
            res = nexRow(res);
        }
        return res;
    }

    vector<int> nexRow(const vector<int>& prev) {
        vector<int> next(prev.size()+1, 1);
        for (int i = 1; i < next.size()-1; ++i) {
            next[i] = prev[i-1] + prev[i];
        }
        return next;
    }
};
