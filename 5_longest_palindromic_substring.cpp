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
