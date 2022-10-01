class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res = {};
        case_permutation(res, s, 0);
        return res;
    }

    void case_permutation(vector<string>& res, string s, int pos) {

        if (pos == s.size()) {
            res.push_back(s);
            return;
        }

        case_permutation(res, s, pos+1);

        if (!isdigit(s[pos])) {
            if (islower(s[pos])) {
                s[pos] = toupper(s[pos]);
            } else {
                s[pos] = tolower(s[pos]);
            }
            case_permutation(res, s, pos+1);
        } 
    }
};
