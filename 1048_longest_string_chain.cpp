class Solution {
public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> dp;

        std::sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
            return word1.size() < word2.size();
        });

        int ans = 1;

        for (const string &word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1, word.length() + 1);
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};
