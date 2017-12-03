// 28_implement_strstr.cpp

class Solution {
public:
    int strStr(string haystack, string needle) {
        bool match = true;
        for (int i = 0, e = haystack.size() - needle.size()+1; i < e; ++i) {
            match = true;
            for (int j = 0, r = needle.size()-1; j <= r; ++j, --r) {
                if (haystack[i+j] != needle[j] || haystack[i+r] != needle[r]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
        return -1;
    }
};


