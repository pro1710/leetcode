class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        
        struct Cell {
            int hor;
            int vert;
            int diag;
            int adiag;
        };

        vector<vector<Cell>> dp(mat.size()+2, vector<Cell>(mat[0].size()+2));;
        int ans = 0;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j]) {
                    dp[i+1][j+1].hor = dp[i+1][j].hor + 1;
                    dp[i+1][j+1].vert = dp[i][j+1].vert + 1;
                    dp[i+1][j+1].diag = dp[i][j].diag + 1;
                    dp[i+1][j+1].adiag = dp[i][j+2].adiag + 1;

                }
                ans = max(ans, dp[i+1][j+1].hor);
                ans = max(ans, dp[i+1][j+1].vert);
                ans = max(ans, dp[i+1][j+1].diag);
                ans = max(ans, dp[i+1][j+1].adiag);
            }
        }
        return ans;
    }
};
