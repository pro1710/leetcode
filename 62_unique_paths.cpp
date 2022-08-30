class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mtx(m, vector<int>(n, 1));
        
        // reversed rows
        for (int r = mtx.size()-2; r >= 0; --r) {
            // reversed cols
            for (int c = mtx[r].size()-2; c >= 0; --c) {
                mtx[r][c] = mtx[r+1][c] + mtx[r][c+1];
                // cout << "[" << r << ", " << c << "] = " << mtx[r][c] << endl;
            }
        }
        
        return mtx[0][0];
    }
};
