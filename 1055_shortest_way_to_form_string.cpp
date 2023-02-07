class Solution {
public:
    int shortestWay(string source, string target) {
    
        int M = source.length();
        int sourceIterator = 0;
        int prevIterator = sourceIterator;
        int ans = 0;

        for (char c : target) {
            prevIterator = sourceIterator;
            if (sourceIterator == 0) {
                ans++;
            }
            while (source[sourceIterator] != c) {
                sourceIterator = (sourceIterator + 1) % M;
                if (sourceIterator == prevIterator) {
                    return -1;
                }
                if (sourceIterator == 0) {
                    ans++;
                }
            }
            sourceIterator = (sourceIterator + 1) % M;
        }

        return ans;
    }  
};
