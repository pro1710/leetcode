class Solution {
    // array<int, 20> memo;
public:
    int numTrees(int n) {

        // if (memo[n]) {
        //     return memo[n];
        // }

        // int res = 0;
        // for (int i = 1; i <= n; ++i) {

        //     res += numTrees(i-1) * numTrees(n-i);
 
        // }
        // if (!res) {
        //     res = 1;
        // }
        // memo[n] = res;
        // return res;

        // catalan number 

        long C = 1;
        for (int i=0; i < n; ++i) {
            C = C*2*(2*i+1)/(i+2);
        }
        return C;
    }


};
