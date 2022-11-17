class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> ans = {};

        int f = 0; 
        int s = 0;

        while (f < firstList.size() && s < secondList.size()) {

            int i = max(firstList[f][0], secondList[s][0]);
            int j = min(firstList[f][1], secondList[s][1]);

            if (i <= j) {
                ans.push_back({i, j});
            } 
            
            if (j == secondList[s][1]) {
                s++;
            } else {
                f++;
            }
        }

        return ans;
    }
};
