class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negs = 0;
        int first_neg = -1;
        int max_len = 0;
        int start = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                negs++;
                if (first_neg < 0) {
                    first_neg = i;
                }
            } else if (nums[i] == 0) {
                negs = 0;
                first_neg = -1;
                start = i+1;
            }
            
            if (negs%2) {
                max_len = max(max_len, i-first_neg);
            } else {
                max_len = max(max_len, i-start+1);
            }
        }
        return max_len;
    }
};
