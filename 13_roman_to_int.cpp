// 13_roman_to_int.cpp

class Solution {
public:
    int romanToInt(string s) {
        // map<char, int> m = {
        //     {'M', 1000},
        //     {'D', 500}, 
        //     {'C', 100},
        //     {'L', 50},
        //     {'X', 10},
        //     {'V', 5},
        //     {'I', 1}
        // };
        
        int m['X'+1] = {};
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;
        
        int res = 0;
        for (int i = 0, e = s.size(); i < e;) {
            if (m[s[i]] < m[s[i+1]]) {
                res += m[s[i+1]] - m[s[i]];
                i += 2;
            } else {
                res += m[s[i]];
                ++i;
            }
        }
        return res;
    }
};


