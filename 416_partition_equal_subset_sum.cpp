class Solution {
    unordered_set<int> memo;
public:
    bool canPartition(vector<int>& nums) {

        int total = accumulate(begin(nums), end(nums), 0);

        if (total%2) {
            return false;
        }

        int half = total/2;

        vector<vector<int>> dp(nums.size()+1, vector<int>(half+1));

        dp[0][0] = true;
        for (int i = 1; i < nums.size()+1; ++i) {
            for (int j = 0; j < half+1; j++) {
                if (j < nums[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp.back().back();
    }
};
