class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;

        for (int i = 0; i < t.size() && p < s.size(); ++i) {
            if (s[p] == t[i]) {
                ++p;
            }
        }
        return p == s.size();
    }
};
