class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = next(slow);
        while (fast !=1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }

    int next(int n) {
        int res = 0 ;
        while (n) {
            res += pow(n%10, 2);
            n /= 10;
        }
        return res;
    }
};
