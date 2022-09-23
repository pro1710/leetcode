class Solution {
public:
    string reverseWords(string s) {
        int pos = 0;
        while (pos < s.size()) {
            size_t p = s.find(' ', pos);
            if (p == string::npos) {
                p = s.size();
            }
            reverse(s.begin()+pos, s.begin()+p);
            pos = p+1;
        }
        
        return s;
    }
};
