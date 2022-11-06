class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return bs(nums, 0, nums.size()-1);
    }

    int bs(const vector<int>& nums, int b, int e) {
        cout << b <<", "<< e << endl;
        if (b==e) {
            return b;
        }

        int mid = b + (e-b)/2;

        if (nums[mid] > nums[mid+1]) {
            return bs(nums, b, mid);
        }

        return bs(nums, mid+1, e);

    }
};
