class Solution {
    unordered_set<int> memo;
public:
    bool isInterleave(const string& s1, const string& s2, const string& s3) {
        return helper(s1, s2, s3, 0, 0, 0);
    }

    bool helper(const string& s1, const string& s2, const string& s3,
                int i1, int i2, int i3) {

        int index = i1*100000 + i2*1000 + i3;
        if (memo.find(index) != memo.end()) {
            return false;
        }
        memo.insert(index);

        if (s1.size() - i1 + s2.size() -i2 != s3.size()-i3) {
            return false;
        }

        if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size()) {
            return true;
        }

        if (i1 == s1.size()) {
            return s2.substr(i2) == s3.substr(i3);
        } 

        if (i2 == s2.size()) {
            return s1.substr(i1) == s3.substr(i3);
        }

        if (s1[i1] == s3[i3]) {
            if (helper(s1, s2, s3, i1+1, i2, i3+1)) {
                return true;
            } 
        }

        if (s2[i2] == s3[i3]) {
            if (helper(s1, s2, s3, i1, i2+1, i3+1)) {
                return true;
            } 
        }

        return false;
    }
};
