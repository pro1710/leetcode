class Solution {
public:
    int countSubstrings(string s) {
        
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
        }

        int ans = 1;
        for (int i = 1; i < s.size(); ++i) {
            ans++;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i] && ( i-j == 1 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                    ans++;
                } 
            }
        }

       return ans;
    }
};
