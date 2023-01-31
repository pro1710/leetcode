class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int with_square = 0;
        int no_square = 0;
        int ans = 0;
        for (auto& n: nums) {
            with_square = max(with_square + n, no_square + n*n);
            no_square = max(0, no_square + n);
            ans = max(ans, with_square);
        }
        return ans;
    }
};
