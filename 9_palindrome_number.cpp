// 9_palindrome_number.cpp

class Solution {
public:
    bool isPalindrome(int x) {
    //     if (x < 0 || x > 2147447412) return false;
    //     if (x < 10) return true;
        
    //     int len = (int)log10(x)+1;
    //     while(x) {
    //         if (x%10 != x/(int)pow(10, --len)) return false;
    //         x = x%(int)pow(10, len)/10;
    //         --len;
    //     }
    //     return true;
    
    if (x < 0) return false;

    int p = x; 
    int q = 0; 
    
    while (p >= 10){
         
        q += p%10; 
        p /=10; 
        q *=10;
    }
    return q == x-p;
    
    }
};

