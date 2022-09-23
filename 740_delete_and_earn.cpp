class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> accum(10000+1);
        
        for (auto& a: nums) {
            accum[a] += a;
        }
        
        int first_best = 0;
        int second_best = 0;
        for (int i = accum.size() - 1; i > 0; --i) {
            int best = max(accum[i] + second_best, first_best);
            
            second_best = first_best;
            first_best = best;

        }
        return first_best;
    }
};
