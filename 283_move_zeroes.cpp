class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, e = nums.size(); i < e; ++i) {
            if (nums[i] != 0) {
                continue;
            }
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] != 0) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }
};
