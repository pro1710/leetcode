class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size()-1, target) != -1;
    }
    
    int binSearch(vector<int>& nums, const int& left, const int& right, const int& target) {
        if (left > right) {
            return -1;
        }
        
        if (right - left == 0) {
            return nums[left] == target ? left : -1;
        }
        
        int mid  = (right + left)/2;
        
        int right_part = -1;

        if (nums[left] >= nums[right]) {
            if (-1 != (right_part = binSearch(nums, mid+1, right, target))) {
                return right_part;
            }
            return binSearch(nums, left, mid, target);
        } 
        
        if (target > nums[mid]) {
            return binSearch(nums, mid+1, right, target);
        }        
        
        return binSearch(nums, left, mid, target);
        
    }   
};

// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         for (auto& a: nums) {
//             if (a == target) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };
