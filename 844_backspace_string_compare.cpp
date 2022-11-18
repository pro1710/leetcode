class Solution {
public:
    bool backspaceCompare(string& s, string& t) {
        return apply(s) == apply(t);
    }

    vector<char> apply(const string& s) {
        vector<char> ans(s.size());
        int i = 0;
        for (auto& c: s) {
            if (c != '#') {
                ans[i] = c;
                i++;
            } else if (i) {
                i--;
            }
        }
        ans.resize(i);
        return ans;
    }
};
