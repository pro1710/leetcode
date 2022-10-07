// 5_longest_palindromic_substring.cpp

class Solution {
public:
    string longestPalindrome(string s) {
         int max_poly = 1, mi = 0;
        for (int i = 0; s.size() - i > max_poly/2; ++i) {
            int right = i;
            int left = i;
            while (s[left] == s[right]) {
                ++right;
            }
            --right;
            i = right;
            
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            
            ++left;
            --right;

            int len = right - left + 1;
            if (max_poly < len) {
                mi = left;
                max_poly = len;
            }
        }
        return s.substr(mi, max_poly);
    }
};
//  //dp
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
//         int mlen = 1;
//         int ans_i = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             dp[i][i] = 1;
//             if (i+1< s.size() && s[i] == s[i+1]) {
//                 dp[i][i+1] = 1;
//                 ans_i = i;
//                 mlen = 2;
//             }
//         } 

//         for (int k = 3; k <= s.size(); ++k) {
//             for (int i = 0; i < s.size() - k + 1; ++i) {
//                 int j = i+k-1;
//                 if (dp[i+1][j-1] && s[i] == s[j]) {
//                     dp[i][j] = 1;
//                     if (k > mlen) {
//                         ans_i = i;
//                         mlen = k;
//                     }
//                 }
//             }
//         }
//         return s.substr(ans_i, mlen);
//     }   
// };
