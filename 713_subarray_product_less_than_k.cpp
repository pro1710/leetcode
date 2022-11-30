class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        if (k < 2) {
            return ans;
        }
        int product = 1;
        int i = 0;

        for (int j = 0; j < nums.size(); ++j) {
            product *= nums[j];
            while (product >= k) {
                product /= nums[i];
                ++i;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
