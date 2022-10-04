class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        const int n = mat.size();
        const int m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int y = 1; y <= n; ++y) {
            for (int x = 1; x <= m; ++x) {
                dp[y][x] = dp[y - 1][x] + dp[y][x - 1] + mat[y - 1][x - 1] - dp[y - 1][x - 1];
            }
        }
      
        auto ans = mat;
        for (int y = 1; y <= n; ++y) {
            for (int x = 1; x <= m; ++x) {
                int x1 = max(1, x - K);
                int x2 = min(m, x + K);
                int y1 = max(1, y - K);
                int y2 = min(n, y + K);
                ans[y - 1][x - 1] = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

//         vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));


//         int i = 0;
//         for (int j = 0; j < mat[0].size(); ++j) {
//             for (int r = i-k; r <= i+k; ++r) {
//                 for (int c = j-k; c <= j+k; ++c) {
//                     if (c >= 0 && r >= 0 && r < mat.size() && c < mat[r].size()) {
//                         ans[i][j] += mat[r][c];
//                     }
//                 }
//             }
//         }
        
//         for (int i = 1; i < mat.size(); ++i) {
//             for (int j = 0; j < mat[i].size(); ++j) {
//                 ans[i][j] = ans[i-1][j];
                
//                 for (int c = j-k; c <= j+k; ++c) {
//                     if (c >= 0 && c < mat[i].size()) {
//                         if (i-k-1 >= 0 && i-k-1 < mat.size()) {
//                             ans[i][j] -= mat[i-k-1][c];
//                         }

//                         if (i+k >= 0 && i+k < mat.size()) {
//                             ans[i][j] += mat[i+k][c];
//                         }
//                     } 
//                 }
//             }
//         }
//         return ans;
//     }
// };
