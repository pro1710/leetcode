// static const auto init = []{
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
//     return false;
// }();

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<vector<double>> dp(prob.size()+1, vector<double>(target+1, 0.0));
        dp[0][0] = 1.0;
        for (int i = 1; i <= prob.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i-1][j] * (1-prob[i-1]);
                if (j != 0) {
                    dp[i][j] += dp[i-1][j-1] * prob[i-1];
                } 
            }
        }
        return dp[prob.size()][target];
    }
};
