class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> head(nums.size(), 1);
        vector<int> tail(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            head[i] = head[i-1] * nums[i-1];
            tail[tail.size()-1-i] = tail[tail.size()-i] * nums[nums.size()-i];
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = head[i] * tail[i];
        }

        return ans;

    }
};
