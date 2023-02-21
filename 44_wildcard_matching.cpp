class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> prev(s.size()+1, 0);
        vector<bool> cur(s.size()+1, 0);

        if (s.size() != p.size() && p.find('*') == string::npos) {
            return false;
        }

        prev[0] = 1;
        for (int i = 1; i <= p.size(); ++i) {
            char ps = p[i-1];

            if (ps == '*') {
                int j = 0;
                while (j <= s.size() && prev[j] == 0) {
                    ++j;
                }
                while (j <= s.size()) {
                    cur[j++] = 1;
                }
            } else {
                for (int j = 1; j <= s.size(); ++j) {
                    cur[j] = prev[j-1] && (ps == '?' || ps == s[j-1]);
                }
            }
            swap(prev, cur);
            fill(cur.begin(), cur.end(), 0);
        }

        return prev.back();
    }
};
