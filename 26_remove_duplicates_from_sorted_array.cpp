// 26_remove_duplicates_from_sorted_array.cpp

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next = 0;
        for (int i  = 0, e = nums.size(); i < e; ++i) {
            if (i == e-1 || nums[i] != nums[i+1]) {
                nums[next++] = nums[i];
            }
        }
        return next;
    }
};


