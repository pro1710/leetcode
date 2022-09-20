class Solution {
public:
    
    unordered_map<int, int> memo = {}; // array
    
    int decode(string& s, int idx) {

        if (memo.find(idx) != memo.end()) {
            return memo[idx];
        }
        
        if (idx == s.size()) {
            return 1;
        } 
        
        int n1 = s[idx] - '0';
        if (n1 == 0) {
            return 0;
        } 
        
        int res = decode(s, idx+1);

        if (idx < s.size()-1 && n1 <= 2) {
            int n2 = s[idx+1] - '0';
            if (n1 == 1 || n2 <= 6) {
                auto res2 = decode(s, idx+2);
                res += res2;
            }  
        }
        
        memo[idx] = res;
        return res;
    }
    
    int numDecodings(string s) {
        
        return decode(s, 0);
        
    }
};
