class Solution {

    
public:
    
    int climbStairs(int n) {
        int prev = 0, curr = 1;
        
        for (int i = 1; i <= n ; ++i) {
            int tmp = curr;
            curr += prev;
            prev = tmp;
        }
        
        return curr;
    }
};
