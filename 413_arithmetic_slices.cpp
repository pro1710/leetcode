class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }

        int curr = nums[1] - nums[0];
        int len = 2;
        int ans = 0;
        for (int i = 2; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i-1];
            if (diff == curr) {
                len++;
            } else {
                if (len >= 3) {
                    ans += (len-1)*(len-2)/2;
                }
                len = 2;
                curr = diff;
            }
        }
        if (len >= 3) {
            ans += (len-1)*(len-2)/2;
        }
        return ans;
    }
};
