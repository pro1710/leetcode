class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned ans = 0;
        for (int i = 0, e = sizeof(n)*8; i < e-1; ++i) {
            ans |= n & 1;
            ans <<= 1; 
            n >>= 1;
        }
        ans |= n & 1;    
        return ans;
    }
};
