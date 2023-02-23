class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n+1, 1);
        for (int i = 2; i <= n; ++i) {
            factorials[i] = factorials[i-1] * i;
        }

        vector<int> nums(n);
        for (int i = 1; i <= n; ++i) {
            nums[i-1] = i;
        }
        vector<int> perm = getKthPermutation(nums, factorials, k-1);

        string result;
        for (int i = 0; i < n; ++i) {
            result += to_string(perm[i]);
        }
        return result;
    }

    vector<int> getKthPermutation(vector<int>& nums, vector<int>& factorials, int k) {
        int n = nums.size();
        vector<int> perm(n);

        for (int i = n-1; i >= 0; --i) {
            int idx = k / factorials[i];
            perm[n-1-i] = nums[idx];
            nums.erase(nums.begin() + idx);
            k -= idx * factorials[i];
        }

        return perm;
    }
};
