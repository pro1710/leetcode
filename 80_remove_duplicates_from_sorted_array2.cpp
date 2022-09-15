class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = 0;
        
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (i > n-3 || nums[i] != nums[i+2]) {
                nums[k++] = nums[i];
            }
        }
        
        return k;
        
    }
};
