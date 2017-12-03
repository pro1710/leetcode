// 29_divide_two_integers.cpp

class Solution {
public:
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1) return 2147483647; // I know this is ugly, but tastcase...
        long long res = 0;
        long long dividend = abs((long long)a);
        long long divisor = abs((long long)b);
        long long d = divisor;
        long long r = 1;
        while(dividend >= divisor){
            d = divisor;
            r = 1;
            while((d << 1) < dividend) {
                d <<= 1;
                r <<= 1;
            }
            res += r;
            dividend -= d;
        }
        
        if((a < 0 && b >= 0) || ( a >= 0 && b < 0))
            return -res;
        return res;
    }
};

