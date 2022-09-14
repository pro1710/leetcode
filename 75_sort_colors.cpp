class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int r = 0;
        int b = nums.size()-1;
        int i = 0;

        while (i <= b) {

            if (nums[i] == 0) {
                swap(nums[r], nums[i]);
                r++;
                i++;
            }else if (nums[i] == 2) {
                swap(nums[b], nums[i]);
                b--;

            } else {
                i++;
            }
        }
    }
};
