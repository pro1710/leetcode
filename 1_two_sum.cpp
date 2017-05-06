// 1_two_sum.cpp

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashm = {};
        for (int i = 0, e = nums.size(); i < e; ++i) {
            int c = target - nums[i];
            if (hashm.find(c) != hashm.end()) {
                return vector<int>({hashm[c], i});
            } else {
                hashm.insert({nums[i], i});
            }
        }
    }
};
