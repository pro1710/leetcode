// 4_median_of_2_sorted_arrays.cpp

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      	if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
    	int m = nums1.size(), n = nums2.size();
    	int imin = 0, imax = nums1.size();
    	while (imin <= imax) {
    		int i = (imax + imin)/2, j = (m+n+1)/2 - i;
    		if (i < m && nums2[j-1] > nums1[i])
    			imin = i + 1;
    		else if (i > 0 && nums1[i-1] > nums2[j])
    			imax = i - 1;
    		else {
    			int max_left = 0;
    			if (!i) {
    				max_left = nums2[j-1];
    			} else if (!j) {
    				max_left = nums1[i-1];
    			} else {
    				max_left = max(nums1[i-1], nums2[j-1]);
    			}
    				
    			if ((m+n)%2) return max_left;
    			
    			int min_right = 0;
    			if (i == m) {
    				min_right = nums2[j];
    			} else if (j == n) {
    				min_right = nums1[i];
    			} else {
    				min_right = min(nums1[i], nums2[j]);
    			}
    			
    			return (max_left + min_right) / 2.0;
			
		}
	}
        return 0;
    }
};