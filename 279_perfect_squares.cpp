class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1, sn = sqrt(n); j <= sn; ++j) {
                dp[i] = min(dp[i], dp[i%(j*j)] + i/(j*j));
            }
        }
        return dp[n];
    }
};
