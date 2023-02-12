class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp = vector<vector<int>>(matrix.size(), vector<int>(matrix.front().size()));

        int ans = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        return ans;
    }

    int dfs(int r, int c, vector<vector<int>>& g, vector<vector<int>>& dp) {

        if (dp[r][c]) {
            return dp[r][c];
        }

        if (r != 0 && g[r][c] < g[r-1][c]) {   
            dp[r][c] = max(dp[r][c], dfs(r-1, c, g, dp));
        }

        if (r != g.size()-1 && g[r][c] < g[r+1][c]) {
             dp[r][c] = max(dp[r][c], dfs(r+1, c, g, dp));
        }

        if (c != 0 && g[r][c] < g[r][c-1]) {   
             dp[r][c] = max(dp[r][c], dfs(r, c-1, g, dp));
        }

        if (c != g[r].size()-1 && g[r][c] < g[r][c+1]) {
             dp[r][c] = max(dp[r][c], dfs(r, c+1, g, dp));
        }

        dp[r][c] += 1;
        return dp[r][c];
    }
};
