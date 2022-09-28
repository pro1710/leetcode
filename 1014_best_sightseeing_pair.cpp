class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int max_low = 0;
        int max_score = 0;
        
        for (int i = 1; i < values.size(); ++i) {
            max_low = max(max_low, values[i-1]+(i-1));
            max_score = max(max_score, values[i]-i + max_low);   
        }
        return max_score;
    }
};
