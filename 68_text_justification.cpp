class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i;
            int len = 0;
            while (j < n && len + words[j].size() + j - i <= maxWidth) {
                len += words[j].size();
                j++;
            }
            int spaces = maxWidth - len;
            int gaps = j - i - 1;
            stringstream ss;
            if (gaps == 0 || j == n) {
                for (int k = i; k < j; k++) {
                    ss << words[k];
                    if (k != j-1) {
                        ss << " ";
                        spaces--;
                    }
                }
                ss << string(spaces, ' ');
            } else {
                int base_spaces = spaces / gaps;
                int extra_spaces = spaces % gaps;
                for (int k = i; k < j; k++) {
                    ss << words[k];
                    if (k < j - 1) {
                        ss << string(base_spaces, ' ');
                        if (extra_spaces > 0) {
                            ss << " ";
                            extra_spaces--;
                        }
                    }
                }
            }
            ans.push_back(ss.str());
            i = j;
        }
        return ans;
    }
};
