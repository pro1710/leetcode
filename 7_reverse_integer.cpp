// 7_reverse_integer.cpp

class Solution {
public:
    int reverse(int x) {
        //simple case
        if (-10 < x && x < 10) return x;
        
        if (x >= 2147483603 || x <= -2147483603 ) return 0;
        
        bool neg = false;
        
        if (x < 0) {
            neg = true;
            x *= -1;
        }
        
        int d = 10;
        int res = 0, prev = 0;
        while (x) {
            res *= 10;
            if (res/10 - prev) return 0;
            res += x%d;
            x /= 10;
            prev = res;
        }

        return (neg ? -res : res);
    }
};


