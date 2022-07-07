class Solution {
public:
    int mySqrt(int x) {
        if( x == 1) return 1;
        
        long long left = 0;
        long long right = x;
        long long ans = 0;
        
        while(left <= right){
            long long guess = left + (right-left)/2;
            long long err = guess * guess - x;
            
            if(err == 0){
                ans = guess;
                break;
            } else if(err > 0){
                right = guess - 1;
            } else {
                ans = guess;
                left = guess + 1;
            }
        }

        return ans;
    }
};
