// 3_longest_substr_wt_repeating_chars.cpp

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vlen(256, -1);
        int maxlen = 0;
        int start = -1;
        for (int i = 0, e = s.size(); i < e; ++i) {
            if (vlen[s[i]] > start) {
                start = vlen[s[i]];
            }
            vlen[s[i]] = i;
            maxlen = max(maxlen, i-start);
        }
        return maxlen;
    }
};