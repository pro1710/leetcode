class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(n+m, 0);
        
        for (int i = 0, j = 0, k = 0; i < n+m; ++i) {
            if (j == n) {
                res[i] = nums1[k];
                ++k;
            } else if (k == m) {
                res[i] = nums2[j];
                ++j;
            } else if (nums1[k] > nums2[j]) {
                res[i] = nums2[j];
                ++j;
            } else {
                res[i] = nums1[k];
                ++k;
            }
        }
        swap(res, nums1);
    }
};
