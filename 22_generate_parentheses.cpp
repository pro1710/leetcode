// 22_generate_parentheses.cpp

class Solution {
public:
    void trace(const string& s, const int& open, const int& close, vector<string>& res) {
        if (!close) {
            res.push_back(s);
        } else {
            if (open) {
                trace(s + "(", open-1, close, res);
            }
            if (close > open) {
                trace(s + ")", open, close-1, res);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n  == 0)
            return {};
        
        vector<string> res = {};
        trace("", n, n, res);
        return res;
    }
};


