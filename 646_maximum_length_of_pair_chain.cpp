class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(begin(pairs), end(pairs), 
            [](const vector<int>& p1, const vector<int>& p2) {
                return p1[1] < p2[1];
            }
        );

        int ans = 1;
        int right = pairs[0][1];

        for (int i = 1; i < pairs.size(); ++i) {
            if (right < pairs[i][0]) {
                ans++;
                right = pairs[i][1];
            }
        }
        return ans;
        
    }
};
