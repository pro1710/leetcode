class Solution {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3) {
            return n - 1;
        } 
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        cout << n << endl;
        return ans*n;
    }
};
