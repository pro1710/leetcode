// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//       int s = accumulate(nums.begin(), nums.end(), 0);
//         if (s < target || (s - target) % 2 != 0) return 0;
//         int m = nums.size(), n = (s - target) / 2;
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         dp[0][0] = 1;
//         for (int i = 1; i <= m; ++i) {
//             for (int j = 0; j <= n; ++j) {
//                 dp[i][j] += dp[i - 1][j];
//                 if (nums[i - 1] <= j) dp[i][j] += dp[i - 1][j - nums[i - 1]];
//             }
//         }
//         return dp[m][n];    
//     }
// };

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> memo(nums.size()+1);
        return trace(0, nums, target, memo);
    }


    int trace(int b, const vector<int>& nums, int target, vector<unordered_map<int, int>>& memo) {

        if (memo[b].find(target) != memo[b].end()) {
            return memo[b][target];
        }

        if (b == nums.size()) {
            return target == 0;
        }
        
        memo[b][target] = trace(b+1, nums, target + nums[b], memo);
        memo[b][target] += trace(b+1, nums, target - nums[b], memo);

        return memo[b][target];
    }
};
