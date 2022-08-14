class Solution {
public:
    double myPow(double x, int n) {
        
        int p = abs(n);
        
        double res = 1;
        while (p > 0) {
            
            if (p&1) {
                res *= x;
            }
            
            x *= x;
            p /= 2;
            
        }
        
        return n > 0 ? res : 1/res;
    }
};
