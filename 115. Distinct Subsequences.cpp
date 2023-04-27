class Solution {
public:
    int numDistinct(const string& s, const string& t) {
        
        if (s == t) {
            return 1;
        }

        vector<vector<unsigned long long int>> dp(t.size()+1, vector<unsigned long long int>(s.size()+1, 0));

        for (int ti = 1; ti < dp.size(); ++ti) {
            for (int si = ti; si < dp[ti].size(); ++si) {

                dp[ti][si] = dp[ti][si-1];
                if (t[ti-1] == s[si-1]) {
                    dp[ti][si] += (ti == 1 ? 1 : dp[ti-1][si-1]);
                } 
            }
        }
        return dp.back().back();
    }
};
