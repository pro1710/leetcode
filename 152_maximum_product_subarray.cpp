class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0];
        int min_prod = nums[0];
        int ans = nums[0];

        
        for (int i = 1; i < nums.size(); ++i) {
            int& x = nums[i]; 
            int tmp = max(x, max(max_prod*x, min_prod*x));
            min_prod = min(x, min(max_prod*x, min_prod*x));
            
            max_prod = tmp;
            
            ans = max(max_prod, ans);  
        }
        return ans;
    }
};
