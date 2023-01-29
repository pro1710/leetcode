class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int prev = 0;

        int ans = 0;
        for (const auto& num: nums) {
            curr++;
            if (num == 0) {
                prev = curr;
                curr = 0;
            }
            ans = max(ans, curr+prev);
        }
        return ans;
    }
};
