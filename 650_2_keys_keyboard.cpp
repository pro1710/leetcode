class Solution {
public:
    int minSteps(int n) {
        
        if (n == 1) {
            return 0;
        }

        int i = 2;
        while (n%i) {
            ++i;
        }

        if (i == n) {
            return i;
        }

        return i + minSteps(n/i);

    }
};
