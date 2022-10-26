// #define DEBUG

class Solution {
private:
    int search(const vector<int>& nums, size_t a, size_t b, int target, int direction) {
        #ifdef DEBUG
            cout << "looking for " << target << " between " << a << " and " << b << endl;
        #endif
        
        if (a > b) {
            return -1;
        }
        
        if (a == b) {
            return nums[a] == target ? a : -1;
        }

        int mid =  (a + b) / 2;
        #ifdef DEBUG
            cout << "mid = " << mid << ", val = " << nums[mid] << endl;
        #endif

        if (nums[mid] == target) {
            if (!direction) {
                if (mid == 0 || nums[mid-1] != target) {
                    return mid;
                }
                return search(nums, a, mid-1, target,direction);
            } else {
                if (mid == nums.size() - 1 || nums[mid+1] != target) {
                    return mid;
                }
                return search(nums, mid+1, b, target,direction);
            }
            
            
        }
        
        if (nums[mid] > target) {
            return search(nums, a, mid, target, direction);
        } else {
            return search(nums, mid+1, b, target, direction);
        }
        
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        
        int left = search(nums, 0, nums.size()-1, target, 0);
        #ifdef DEBUG
            cout << "left pos " << left;
        #endif
        
        int right = search(nums, 0, nums.size()-1, target, 1);
        #ifdef DEBUG
            cout << "left pos " << right;
        #endif
        return {left, right};
    }
};
