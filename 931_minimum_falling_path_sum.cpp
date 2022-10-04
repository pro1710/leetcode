class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = matrix.size() - 2; i >= 0; --i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                int tmp = matrix[i+1][j];
                if (j-1 >=0) {
                    tmp = min(tmp, matrix[i+1][j-1]);
                } 
                if (j+1 < matrix[i].size()) {
                    tmp = min(tmp, matrix[i+1][j+1]);
                }
                matrix[i][j] += tmp;
            }
        }

        int ans = 1e5;
        for (auto& a: matrix[0]) {
            ans = min(ans, a);
        } 
        return ans;
    }
};
