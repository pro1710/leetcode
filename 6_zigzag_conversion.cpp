// 6_zigzag_conversion.cpp

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        res.reserve(s.size());
        
        queue<int> current, next;
        // 1st row
        for (int i = 0, e = s.size(), step = numRows*2-2; i < e; i+=step) {
            res += s[i];
            current.push(i);
        }
        
        int index = 0;
        for (int i = 2, e = numRows; i < e; ++i) {
            while (!current.empty()) {
                index = current.front();
                current.pop();
                ++index;
                if (index < s.size()) {
                    res += s[index];
                    next.push(index);
                    index+=(2*numRows-2*i);
                    if (index < s.size()){
                        res += s[index];
                    }
                }
            }
            swap(current, next);
        }
        
        // last row
        for (int i = numRows - 1, e = s.size(), step = numRows*2-2; i < e; i+=step) {
            res += s[i];
        }
        
        return res;
    }
};


