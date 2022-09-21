class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> res(nums.size());
     
        int lo = 0;
        int hi = nums.size() - 1;
        int pos = nums.size() - 1;
        
        while (lo <= hi) {
            
            int lov = nums[lo]*nums[lo];
            int hiv = nums[hi]*nums[hi];
            if (lov < hiv) {
                res[pos--] = hiv;
                hi--;
            } else {
                res[pos--] = lov;
                lo++;
            }
            
        }
        
        return res;
    }
};
