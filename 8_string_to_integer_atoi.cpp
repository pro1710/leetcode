// 8_string_to_integer_atoi.cpp

class Solution {
public:
    int myAtoi(string str) {
        
        int index = 0;
        while (str[index] == ' ') ++index;
        bool neg = false;
        if (str[index] == '-') {
            neg = true;
            ++index;
        } else if(str[index] == '+') {
            ++index;
        }
        
        int cutoff  = neg ? INT32_MIN : INT32_MAX ;
        int cutlim  = cutoff % 10;
        cutoff /= 10;
        cutlim = neg ? -cutlim : cutlim;
        
        int res = 0;
        for (int i = index, e = str.size(); i < e; ++i) {
            int d = str[i];
            if (!isdigit(d)) {
                return res;
            }
            d -= '0';
        	if (neg) {
    			if (res < cutoff || (res == cutoff && d > cutlim)) {
    				return INT32_MIN;
    			} else {
    				res *= 10;
    				res -= d;
    			}
    		} else {
    			if (res > cutoff || (res == cutoff && d > cutlim)) {
    				return INT32_MAX;
    			} else {
    				res *= 10;
    				res += d;
    			}
    		}
        }
        return res;
    }
};


