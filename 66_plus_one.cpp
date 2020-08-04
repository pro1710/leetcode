// 66_plus_one.cpp

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r = 1;
        for (int i  = digits.size()-1; i >= 0; --i) {
            digits[i] += r;
            r = digits[i] / 10;
            digits[i] %= 10;
            
            if (r == 0) {
                break;
            }
        }
        
        if (r) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
