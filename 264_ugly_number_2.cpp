class Solution {
public:
    int nthUglyNumber(int n) {
        int two = 0;
        int three = 0;
        int five = 0;
        vector<int> ugly(n);
        ugly[0] = 1;

        for (int i = 1; i < n; ++i) {

            int mul2 = ugly[two] * 2;
            int mul3 = ugly[three] * 3;
            int mul5 = ugly[five] * 5;

            ugly[i] = min(mul2, min(mul3, mul5));

            if (ugly[i] == mul2) {
                two++;
            } 
            if (ugly[i] == mul3) {
                three++;
            } 
            if (ugly[i] == mul5) {
                five++;
            }
        }
        return ugly.back();

    }
};
Console
