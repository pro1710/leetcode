class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        bool has_1 = false;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                has_1 = true;
            }
            if (nums[i] <= 0 || nums[i] > nums.size()) {
                nums[i] = 1;
            }
        }

        if (!has_1) {
            return 1;
        }

        for (int i = 0; i < nums.size(); ++i) {
           int a = abs(nums[i]);
       
            if (a == nums.size()) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[a] = -abs(nums[a]);
            }
           
        }
      
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                return i;
            }
        }

        if (nums[0] > 0) {
            return nums.size();
        }

        return nums.size()+1; 
    }
};
