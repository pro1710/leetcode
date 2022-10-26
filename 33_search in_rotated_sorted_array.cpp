class Solution {
public:
    int search(vector<int>& nums, int target) {
        // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", ")); cout << endl;
        return binSearch(nums, 0, nums.size()-1, target);
    }

private:
    int binSearch(vector<int>& nums, const int& left, const int& right, const int& target) {

        // cout << "binSearch: left = " << left << ", right = " << right << ", target = " << target << endl; 
        
        if (left > right) {
            // cout << "left > right" << endl; 
            return -1;
        }
        
        if (right - left == 0) {
            // cout << "right - left == 0: nums[left] = " << nums[left] << ", nums[right] = " << nums[right] << endl;
            return nums[left] == target ? left : -1;
        }
        
        int mid  = (right + left)/2;
        
        int right_part = -1;

        if (nums[left] > nums[right]) {
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
