class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans = {};

        int P = p.size();
        const vector<int> pv = strToVec(p, 0, P);
        vector<int> sv = strToVec(s, 0, P-1);
        
        for (int i = 0, e = s.size()-P; i <= e; ++i) {
            sv[s[i+P-1] - 'a']++;
            if (pv == sv) {
                ans.push_back(i);
            }
            int& si = sv[s[i] - 'a'];
            si = (si > 0 ? si-1 : 0);
        }
        return ans;
    }

    vector<int> strToVec(const string& str, int beg, int end) {
        vector<int> res(26, 0);
        
        if (end < beg || end > str.size() || beg < 0) {
            return res;
        }

        for (; beg < end; ++beg) {
            res[str[beg]-'a']++;
        }
        return res;

    }
};
