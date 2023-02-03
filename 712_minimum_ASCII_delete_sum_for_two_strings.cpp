class Solution {
public:
    int minimumDeleteSum(const string& s1, const string& s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        
        for (int i = 0; i < s1.size(); ++i) {
            dp[i+1][0] = s1[i] + dp[i][0];
        }
        
        for (int i = 0; i < s2.size(); ++i) {
            dp[0][i+1] = s2[i] + dp[0][i];
        }

        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i][j-1] + (int)s2[j-1], dp[i-1][j] + (int)s1[i-1]);
                }   
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
