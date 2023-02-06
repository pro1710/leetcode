class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        vector<pair<int, int>> dp;
        for (int i = 0; i < nums.size(); ++i) {
            dp.push_back({1, -1});
        }

        int max_len = 1;
        int max_len_idx = dp.size()-1;
        for (int i = dp.size()-2; i >= 0; --i) {
            for (int j = i+1; j < dp.size(); ++j) {
                if (nums[j]%nums[i] == 0) {
                    if (dp[i].first < dp[j].first + 1) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = j;
                    }
                }
            }
            if (dp[i].first > max_len) {
                max_len = dp[i].first;
                max_len_idx = i;
            }
        }

        vector<int> ans;
        int n = max_len_idx;
        while (n != -1) {
            ans.push_back(nums[n]);
            n = dp[n].second;
        }
        return ans;
    }
};
