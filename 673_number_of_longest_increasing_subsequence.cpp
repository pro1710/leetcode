class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int const N = nums.size();
        vector<int> lis_size(N, 1);
        vector<int> lis_number(N, 1);
        int max_len = 1;

        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (lis_size[j] + 1 > lis_size[i]) {
                        lis_size[i] = lis_size[j]+1;
                        lis_number[i] = lis_number[j];
                    } else if (lis_size[j] + 1 == lis_size[i]) {
                        lis_number[i] += lis_number[j];
                    }
                }
            }
            max_len = max(max_len, lis_size[i]);
        }

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (lis_size[i] == max_len) {
                ans += lis_number[i];
            }
        }
        return ans;

    }
};
