// 58_len_of_last_word.cpp

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
               ++len;
            } else if (len !=0) {
                return len;
            }
        }
        return len; 
    }
};
