// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<bool> breakable(s.size() + 1, false);
//         breakable[0] = true;
//         for (int i = 0; i <= s.size(); ++i) {
//             if (breakable[i]) {
//                 for (auto& word : wordDict) {
//                     if (word == s.substr(i, word.size())) {
//                         breakable[i + word.size()] = true;
//                     }
//                 }
//             }
//         }
        
//         return breakable[s.size()];
//     }
// };

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo = {};
        for (auto& w: wordDict) {
            memo[w] = true;
        }
        return solve(s, memo);
    }

    bool solve(const string& s, unordered_map<string, bool>& memo) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        for (int i = 1 ; i < s.size(); ++i) {
            string first = s.substr(0, i);
            auto it = memo.find(first);
            if (it != memo.end() && it->second) {
                string second = s.substr(i);
                memo[second] = solve(second, memo);

                if (memo[second]) {
                    return true;
                } 
            }
            
        }
        return false;
    }
};

